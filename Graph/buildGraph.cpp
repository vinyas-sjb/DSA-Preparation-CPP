/*
============================================================
Problem: Graph Representation using Adjacency List
============================================================

Concepts Used:
- Graph
- Adjacency List
- Undirected Graph

Description:
- A graph consists of vertices (nodes) and edges.
- Adjacency List stores all neighboring vertices
  of each node.

Approach:
1. Create an array of lists.
2. Each index represents a vertex.
3. For every edge (u, v):
   - Add v to u's list.
   - Add u to v's list.
4. Traverse each list to display the graph.

Example:

      0
      |
      1
     / \
    2---3

Adjacency List:
0 : 1
1 : 0 2 3
2 : 1 3
3 : 2 1

Time Complexity:
- addEdge() : O(1)
- print()   : O(V + E)

Space Complexity:
- O(V + E)

============================================================
*/

#include<iostream>
#include<list>
using namespace std;

class Graph{
    int v;
    list<int> *l;
    public:
    Graph(int v){
        this->v = v;
        l = new list<int>[v];
    }

    void addEdge(int u, int v){
        // u->src and v->destination //
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void print(){
        for(int i=0;i<v;i++){
            cout<<i<<" : ";
            for(int neigh : l[i]){
                cout<<neigh<<" ";
            }
            cout<<endl;
        }
    }
};

int main(){
    Graph g(4);

    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,1);

    g.print();
    return 0;

}
/*
============================================================
Summary:
- Graph represented using Adjacency List.
- Efficient for sparse graphs.
- Stores only connected neighbors.
- Foundation for BFS and DFS traversal.

Key Formula:
Space = O(V + E)

Where:
V = Number of Vertices
E = Number of Edges
============================================================
*/