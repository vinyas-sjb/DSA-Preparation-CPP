/*
============================================================
Problem: Breadth First Search (BFS) Traversal of Graph
============================================================

Concepts Used:
- Graph
- Adjacency List
- Queue
- Breadth First Search (BFS)

Description:
- BFS visits nodes level by level.
- It explores all neighbors of a node before
  moving to the next level.

Approach:
1. Mark source node as visited.
2. Push source node into queue.
3. While queue is not empty:
   - Remove front node.
   - Print current node.
   - Visit all unvisited neighbors.
   - Mark them visited and push into queue.
4. Continue until queue becomes empty.

Example Graph:

0 -- 1 -- 2
          / \
         3---4

BFS Traversal:
0 1 2 3 4

Time Complexity:
- O(V + E)

Space Complexity:
- O(V)

Where:
V = Number of Vertices
E = Number of Edges

============================================================
*/

#include<iostream>
#include<vector>
#include<list>
#include<queue>
using namespace std;

class Graph{
    int v;
    list<int>*l;
public:
    Graph(int v){
        this->v = v;
        l = new list<int>[v];
    }

    void addAdj(int u, int v){
        l[u].push_back(v);
        l[v].push_back(u);
    }

    // BFS Traversal //
    void bfs(){
        queue<int>Q;
        vector<bool>vis(v,false);
        // initialize 0 as visited //
        Q.push(0);
        vis[0] = true;

        while(Q.size() > 0){
            int u = Q.front();
            Q.pop();
            cout<<u<<" ";

            for(int v : l[u]){
                if(!vis[v]){
                    vis[v] = true;
                    Q.push(v);
                }
            }
        }
        cout<<endl;
    }
};

int main(){
    Graph g(5);
    g.addAdj(0,1);
    g.addAdj(1,2);
    g.addAdj(2,3);
    g.addAdj(3,4);
    g.addAdj(4,2);

    g.bfs();
    return 0;
}
/*
============================================================
Summary:
- BFS uses Queue (FIFO).
- Visits nodes level by level.
- Visited array prevents revisiting nodes.
- Useful for shortest path in unweighted graphs.

Pattern:
Push → Visit → Explore Neighbors

Data Structure Used:
Queue

Applications:
- Shortest Path (Unweighted Graph)
- Connected Components
- Level Order Traversal
- Network Broadcasting

============================================================
*/

// BFS = Queue + Visited Array
// Visit nodes level by level
// Time: O(V + E)
// Space: O(V)