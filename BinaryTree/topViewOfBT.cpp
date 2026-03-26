/*
Problem: Top View of Binary Tree

Definition:
- The top view of a binary tree contains the nodes that are visible
  when the tree is viewed from the top.

Key Idea:
- Every node has a Horizontal Distance (HD) from the root.
- Root node has HD = 0.
- Left child decreases HD by 1.
- Right child increases HD by 1.

Approach:
1. Use Level Order Traversal (BFS) with a queue.
2. Store nodes along with their horizontal distance (HD).
3. Use a map to store the first node encountered at each HD.
4. Traverse the tree level by level.
5. If a horizontal distance is not present in the map,
   store the node's value.
6. Finally print all values stored in the map.

Traversal Used:
Level Order Traversal (Breadth First Search).

Example Tree:

        1
       / \
      2   3
         / \
        4   5

Horizontal Distances:

Node   HD
1      0
2     -1
3      1
4      0
5      2

Top View:
2 1 3 5

Time Complexity: O(n log n)
- n nodes are processed once.
- map insertion takes log n time.

Space Complexity: O(n)
- Queue stores nodes for BFS.
- Map stores horizontal distances.
*/

/*
Function: buildTree(vector<int>& preOrder)

Purpose:
- Builds a binary tree using preorder traversal input.

Preorder Format:
Root → Left → Right

Logic:
1. Read the current value from the preorder array.
2. If the value is -1, return NULL (represents empty node).
3. Create a new node with the current value.
4. Recursively build the left subtree.
5. Recursively build the right subtree.

Time Complexity: O(n)
Space Complexity: O(h)
- h is the height of the tree due to recursion stack.
*/

/*
Function: topView(Node* root)

Purpose:
- Prints the top view of a binary tree.

Logic:
1. Use a queue to perform level order traversal.
2. Store pairs of (node, horizontal distance).
3. Maintain a map to store the first node value
   for each horizontal distance.
4. If a horizontal distance is seen for the first time,
   store that node's value in the map.
5. Continue BFS traversal for all nodes.
6. Print the map values in order of horizontal distance.

Data Structures Used:
- Queue: for BFS traversal.
- Map: to store first node at each horizontal distance.

Time Complexity: O(n log n)
Space Complexity: O(n)
*/

#include<iostream>
#include<vector>
#include<queue>
#include<map>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data = val;
        left = right = NULL;
    }
};

static int idx=-1;
Node* buildTree(vector<int> &preOrder){
    idx++;
    if(preOrder[idx] == -1){
        return NULL;
    }
    Node* root = new Node(preOrder[idx]);
    root->left = buildTree(preOrder);
    root->right = buildTree(preOrder);

    return root;
}

// calculate the top view of element //
void topView(Node* root){
    if(root == NULL) return;

    queue<pair<Node*,int>>q; //(node,horizontalDistance:HD)//
    map<int,int>m; //(HD,nodeval)//
    q.push({root,0});

    while (q.size()>0)
    {
        Node* curr = q.front().first;
        int currHd = q.front().second;
        q.pop();

        if(m.find(currHd) == m.end()){
            m[currHd] = curr->data;
        }

        if(curr->left!=NULL){
            q.push({curr->left,currHd-1});
        }
        if(curr->right!=NULL){
            q.push({curr->right,currHd+1});
        }
    }
    //print elements in a map //
    cout<<"The top view element in a BT is : ";
    for(auto it : m){
        cout<<it.second<<" ";
    }
    
}

int main(){
    vector<int>preOrder = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    Node* root = buildTree(preOrder);

    topView(root);
    return 0;

}

/*
map is used instead of unordered_map because map keeps
horizontal distances sorted. This helps print the
top view from left to right correctly.
*/