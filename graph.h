#pragma once
#include <vector>
#include <iostream>

#ifndef SRC_GRAPH_H_
#define SRC_GRAPH_H_

// Edge structure
template <typename Te>
struct Edge {
  Te data;
  int weight;
  int dest;
  Edge<Te>* next;
  Edge(Te const& d = (Te)0, int w = 0, int j = 0) :
    data(d), weight(w), dest(j), next(nullptr) {}
};

// Vertex structure
template <typename Tv, typename Te>
struct Vertex {
  Tv data;
  int inDegree;
  int outDegree;
  Edge<Te>* next;
  Vertex(Tv const& d = (Tv)0) :
    data(d), inDegree(0), outDegree(1), next(nullptr) {}
};

struct Dist {
  int dist = 0x7fffffff;
  int prev = -1;
};

// Graph template class
// Implemented by adjacency list
template <typename Tv, typename Te>
class Graph {
private:
  std::vector<Vertex<Tv, Te>> adjList;
  int n; // Number of vertices
  int e; // Number of edges

public:
  // Constructor
  Graph() { n = e = 0; }

  // Destructor
  ~Graph() {
    for (int i = 0; i < n; i++) {
      Edge<Te>* ptr = adjList[i].next;
      if (ptr != nullptr) {
        while (ptr->next != nullptr) {
          Edge<Te>* temp = ptr->next;
          delete ptr;
          ptr = temp;
        }
        delete ptr;
      }
    }
  }

  // Vertex
  int getN() const { return n; }
  Tv& vertex(int i) { return adjList[i].data; }
  int inDegree(int i) { return adjList[i].inDegree; }
  int outDegree(int i) { return adjList[i].outDegree; }
  Te firstNbr(int i) { return adjList[i].next; }
  void insert(Tv const&);

  // Edge
  int getE() const { return e; }
  Te& edge(int i, int j)
  {
    Edge<Te>* ptr = adjList[i].next;
    while (ptr->dest != j) ptr = ptr->next;
    return ptr->data;
  }
  int& weight(int i, int j)
  {
    Edge<Te>* ptr = adjList[i].next;
    while (ptr->dest != j) ptr = ptr->next;
    return ptr->weight;
  }
  void insert(Te const&, int, int, int);
  void insertUndirected(Te const& edge, int w, int i, int j) {
    this->insert(edge, w, i, j);
    this->insert(edge, w, j, i);
  }

  // Utilities
  void showGraph();

  // Algorithms
  std::vector<Tv> dijkstra(int, int);
  void spfa();

};

// Insert vertex
template <typename Tv, typename Te>
void Graph<Tv, Te>::insert(Tv const& vertex) {
  adjList.push_back(Vertex<Tv, Te>(vertex));
  n++;
}


// Insert edge
template <typename Tv, typename Te>
void Graph<Tv, Te>::insert(Te const& edge, int w, int i, int j) {
  Edge<Te>* ptr = adjList[i].next;
  if (ptr == nullptr) {
    ptr = new Edge<Te>(edge, w, j);
    adjList[i].next = ptr;
  }
  else {
    while (ptr->next != nullptr) ptr = ptr->next;
    ptr->next = new Edge<Te>(edge, w, j);
  }
  e++;
  adjList[i].outDegree++;
  adjList[j].inDegree++;
}

// Show the adjacency list
template<typename Tv, typename Te>
void Graph<Tv, Te>::showGraph() {
  for (int i = 0; i < n; i++) {
    std::cout << i << "->";
    if (adjList[i].next != nullptr) {
      Edge<Te>* ptr = adjList[i].next;
      std::cout << ptr->dest << "->";
      while (ptr->next != nullptr) {
        ptr = ptr->next;
        std::cout << ptr->dest << "->";
      }
    }
    std::cout << "\n";
  }
}

template<typename Tv, typename Te>
std::vector<Tv> Graph<Tv, Te>::dijkstra(int from, int to) {
  std::vector<struct Dist> distVec;
  bool check[1024];
  memset(check, false, sizeof(check));
  for (int i = 0; i < n; i++) {
    Dist tmp;
    distVec.push_back(tmp);
  }
  distVec[from].dist = 0;
  for (int i = 1; i < n; i++) {
    int x = -1;
    // tag
    for (int j = 0; j < n; j++) {
      if (!check[j] && (x == -1 || distVec[j].dist < distVec[x].dist))
        x = j;
    }
    check[x] = true;
    //
    Edge<Te>* ptr = adjList[x].next;
    while (ptr != nullptr) {
      if (distVec[ptr->dest].dist > distVec[x].dist + ptr->weight) {
        distVec[ptr->dest].dist = distVec[x].dist + ptr->weight;
        distVec[ptr->dest].prev = x;
      }
      ptr = ptr->next;
    }
  }

  /*std::cout << '\n';
  for (int i = 0; i < n; i++) {
    std::cout << check[i] << " ";
  }
  std::cout << '\n';
  for (int i = 0; i < n; i++) {
    std::cout << distVec[i].dist << '\t' << distVec[i].prev << '\n';
  }*/

  std::vector<Tv> ret;
  int p = to;
  while (p != from) {
    ret.push_back(adjList[p].data);
    p = distVec[p].prev;
  }
  ret.push_back(adjList[from].data);
  return ret;
}

#endif // SRC_GRAPH_H_
