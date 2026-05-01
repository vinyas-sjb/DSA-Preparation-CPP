/*
Problem: Minimum Distance Between BST Nodes

Category:
- Trees
- Binary Search Tree (BST)

Description:
- Given the root of a Binary Search Tree (BST),
  find the minimum difference between values of
  any two different nodes.

BST Property Used:
- Inorder traversal of a BST gives values in
  sorted (ascending) order.

Approach:
1. Perform an inorder traversal (Left → Root → Right).
2. Keep track of the previous visited node.
3. For each node, compute the difference between
   current node and previous node.
4. Update the minimum difference.
5. Return the smallest difference found.

Example:

Input Tree:

        4
       / \
      2   6
     / \
    1   3

Inorder Traversal:
1, 2, 3, 4, 6

Differences:
(2-1)=1, (3-2)=1, (4-3)=1, (6-4)=2

Output:
Minimum Difference = 1

Time Complexity: O(n)
- Each node is visited exactly once.

Space Complexity: O(h)
- h = height of the tree (recursion stack).

Concepts Used:
- Binary Search Tree (BST)
- Inorder Traversal
- Recursion
- Previous node tracking
*/


/*
Function: mindist(Node* root)

Purpose:
- Find the minimum difference between values
  of any two nodes in a BST.

Approach:
1. If the node is NULL, return INT_MAX.
2. Recursively find minimum difference in left subtree.
3. Compare current node with previous node.
4. Update minimum difference.
5. Recursively find minimum difference in right subtree.
6. Return the minimum of all computed differences.

Important Note:
- Uses a global variable 'prev' to track
  the previously visited node in inorder traversal.

Time Complexity: O(n)

Space Complexity: O(h)
*/


/*
Function: main()

Purpose:
- Create a sample BST.
- Call the function to compute minimum difference.
- Display the result.

Steps:
1. Construct the BST manually.
2. Call Solution::mindist().
3. Print the result.

Output:
Minimum distance between BST nodes.
*/

#include<iostream>
#include<climits>
#include<algorithm>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    
    Node(int val) : data(val),left(nullptr),right(nullptr){}
};

class Solution{
    public:
    Node* prev = NULL;
    int mindist(Node* root){
        // base case //
        if(root == NULL) return INT_MAX;
        int ans = INT_MAX;

        // left //
        if(root->left!=NULL){
            int leftMin = mindist(root->left);
            ans = min(ans,leftMin);
        }

        // root //
        if(prev != NULL){
            ans = min(ans, root->data - prev->data);
        }
        prev = root;

        // right //
        if(root->right != NULL){
            int rightMin = mindist(root->right);
            ans = min(ans,rightMin);
        }
        return ans;
    }
};

int main(){
    Node* root = new Node(83);
    root->left = new Node(62);
    root->right = new Node(88);
    root->left->left = new Node(42);
    root->left->right = new Node(82);
    root->left->left->right = new Node(52);
    Solution obj;

    cout<<"Minimum distance b/w BST is : "<<obj.mindist(root);

    return 0;
}