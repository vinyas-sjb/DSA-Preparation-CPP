/*
============================================================
Problem: Depth First Search (DFS) Traversal of Graph
============================================================

Concepts Used:
- Graph
- Adjacency List
- Recursion
- Depth First Search (DFS)

Description:
- DFS explores a graph by going as deep as possible
  along a path before backtracking.
- It uses recursion (or a stack) to visit vertices.

Approach:
1. Start from the source vertex (0).
2. Mark the current vertex as visited.
3. Print the current vertex.
4. Visit each unvisited neighbor recursively.
5. Continue until all reachable vertices are visited.

Example Graph:

      0
      |
      1
     / \
    2   3
    |
    4

DFS Traversal:
0 1 2 4 3

Traversal Flow:
0 → 1 → 2 → 4
          ↑
     Backtrack
          ↓
          3

Time Complexity:
- O(V + E)

Space Complexity:
- O(V)

Where:
V = Number of Vertices
E = Number of Edges

Applications:
- Path Finding
- Cycle Detection
- Connected Components
- Topological Sorting
- Maze Solving

============================================================
*/

#include<iostream>
#include<list>
#include<vector>
using namespace std;

class Graph{
    int V; //Vertex of graph//
    list<int>*l;
public:
    Graph(int V){
        this->V = V;
        l = new list<int>[V];
    }

    void addAdj(int u,int v){
        l[u].push_back(v);
        l[v].push_back(u);
    }

    // DFS TRAVERSAL //
    void dfsHelper(int u, vector<bool> &vis){

        // u->src vertex v->neighbour vertex //
        cout<<u<<" ";
        vis[u] = true;
        for(int v : l[u]){
            if(!vis[v]){
                dfsHelper(v,vis);
            }
        }
    }

    void dfs(){
        int src = 0;
        vector<bool>vis(V,false);

        dfsHelper(src,vis);
    }

};

int main(){
    Graph g(5);
    
    g.addAdj(0,1);
    g.addAdj(1,2);
    g.addAdj(1,3);
    g.addAdj(2,4);

    g.dfs();
    return 0;
}
/*
============================================================
Summary:
- DFS uses Recursion (or Stack).
- Visits a node and explores its deepest
  unvisited neighbor first.
- Backtracks when no unvisited neighbors remain.
- Visited array prevents revisiting nodes.

Pattern:
Visit → Go Deep → Backtrack

Data Structure Used:
- Adjacency List
- Recursion Stack
- Visited Array

Time Complexity:
- O(V + E)

Space Complexity:
- O(V)

============================================================
*/

// DFS = Recursion + Visited Array
// Go Deep First, Then Backtrack
// Time: O(V + E)
// Space: O(V)