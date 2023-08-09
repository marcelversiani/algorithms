#include <TspSolver.h>

void TspSolver::solve(TspReader &tr,std::vector<int> &percourse) {
    TspSolver TS;
    TS.getMatrix(tr);
    TS.primSolver();
    TS.preOrder(0, percourse);
}//solve

void TspSolver::getMatrix(TspReader &tr) {
    std::vector<City> cities(tr.getNumCities());
    tr.copyCitiesVector(cities);
    adjMatrix.resize(tr.getNumCities(), std::vector<int>(tr.getNumCities(), 0));

    for (int i = 0; i < tr.getNumCities(); ++i) {
        for (int j = 0; j < tr.getNumCities(); ++j) {
            adjMatrix[i][j] = cities[i].disti(cities[j]);
        }
    }
}// create the adjacency matrix

void TspSolver::primSolver() {
    parent.resize(adjMatrix.size(), -1);
    std::vector<bool> visited(adjMatrix.size(), false);
    std::vector<Edge> edges;

    // insert root edges
    for (int i = 0; i < adjMatrix[0].size(); ++i) {
            Edge edge(adjMatrix[0][i], 0, i);
            edges.push_back(edge);
    }
    std::make_heap(edges.begin(), edges.end());
    visited[0] = true;

    // while there are edges to explore
    while (!edges.empty()) {
        int currVertex = edges.front().to_vertex;
        int prevVertex = edges.front().from_vertex;
        // pop the best edge
        std::pop_heap(edges.begin(), edges.end());
        edges.pop_back();

        // ignore the already explored edges
        if(visited[currVertex]) continue;
        visited[currVertex] = true;
        parent[currVertex] = prevVertex;

        // insert new edges
        for (int i = 0; i < adjMatrix.size(); ++i) {
            if(visited[i] == false) {
                Edge e(adjMatrix[currVertex][i], currVertex, i);
                edges.push_back(e);
                std::push_heap(edges.begin(), edges.end());
            }
        }
    }
}// find the minimum spanning tree

void TspSolver::preOrder(int currVertex, std::vector<int> &percourse) {
    std::vector<Child> children;
    // find the children of the current vertex
    for (int i = 0; i < adjMatrix.size(); ++i) {
        if(parent[i] == currVertex) {
            Child c(adjMatrix[currVertex][i], i);
            children.push_back(c);
        }
    }
    // sort the children by distance so we can get the shortest path
    std::sort(children.begin(), children.end());
    percourse.push_back(currVertex + 1);
    // recursively walk trough the children
    for (int i = 0; i < children.size(); ++i) {
        preOrder(children[i].vertex, percourse);
    }
}// pre order walk trough the vertices