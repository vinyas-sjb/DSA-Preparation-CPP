/*
============================================================
Problem: Number of Islands
============================================================

Concepts Used:
- Graph Traversal
- Depth First Search (DFS)
- 2D Grid
- Connected Components

Description:
- Given a 2D grid containing:
    '1' -> Land
    '0' -> Water
- Count the number of islands present in the grid.

Definition:
- An island is formed by connecting adjacent land cells
  horizontally or vertically.
- All connected land cells belong to the same island.

Approach:
1. Traverse every cell in the grid.
2. When an unvisited land cell ('1') is found:
   - Run DFS to visit all connected land cells.
   - Increment island count.
3. Continue until all cells are processed.

DFS Directions:
- Up
- Right
- Down
- Left

Pattern:
Grid -> DFS/BFS -> Connected Components

Time Complexity:
- O(n * m)

Space Complexity:
- O(n * m)

Where:
n = Number of Rows
m = Number of Columns

============================================================
*/

#include<iostream>
#include<vector>
using namespace std;

class solution{
    public:
    void dfs(int i, int j, vector<vector<bool>>&vis, vector<vector<char>>& grid, int n, int m){
        // base case //
        if(i<0 || j<0 || i>=n || j>=m || vis[i][j] || grid[i][j]!='1'){
            return;
        }

        vis[i][j] = true;
        // neighbour vertex //
        dfs(i+1,j,vis,grid,n,m); // top
        dfs(i,j+1,vis,grid,n,m); // right
        dfs(i-1,j,vis,grid,n,m); // bottom
        dfs(i,j-1,vis,grid,n,m); // left
    }



    int numberOfIsland(vector<vector<char>>& grid){
        int n = grid.size(); // rows 
        int m = grid[0].size(); // columns
        int island = 0;
        vector<vector<bool>>vis(n, vector<bool>(m,false));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j] == '1'){
                    dfs(i,j,vis,grid,n,m);
                    island++;
                }
            }
        }
        return island;

    }
};

int main(){
    vector<vector<char>>grid = {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };

    solution obj;
    cout<<"The Number of island in 2D Grid is : "<<obj.numberOfIsland(grid);
    return 0;
}
/*
============================================================
Summary:
- Treat each land cell as a graph node.
- DFS explores all connected land cells.
- One DFS call = One Island.
- Island count equals the number of connected components.

Key Idea:
Unvisited Land -> DFS -> Island Count++

Output:
Number of Islands = 3
============================================================
*/