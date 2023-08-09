#ifndef TSP_SOLVER
#define TSP_SOLVER


#include <TspReader.h>
#include <vector>


class Edge {
public:
    // edge constructor
    Edge(int distance, int from_vertex, int to_vertex) : distance(distance), from_vertex(from_vertex), to_vertex(to_vertex) { };
    int distance;
    int from_vertex;
    int to_vertex;
    
    // comparison operator
    bool operator<(const Edge& other) const {
        if (distance != other.distance) return distance > other.distance;
        else if (from_vertex != other.from_vertex) return from_vertex > other.from_vertex;
        else return to_vertex > other.to_vertex;
    }
};// class of edge

class Child {
public:
    // child constructor
    Child(int distance, int vertex) : distance(distance), vertex(vertex) { };
    int distance;
    int vertex;

    // comparison operator
    bool operator<(const Child& other) const {
        if (distance != other.distance) return distance < other.distance;
        else return vertex < other.vertex;
    }
};// class of child

class TspSolver {
public:
    // you should fill percourse with a permutation that represents the TSP solution
    void solve(TspReader &tr,std::vector<int> &percourse); 
    void getMatrix(TspReader &tr);
    void primSolver();
    void preOrder(int currVertex, std::vector<int> &percourse);

private:
    std::vector<std::vector<int>> adjMatrix;
    std::vector<int> parent;
}; 

#endif
