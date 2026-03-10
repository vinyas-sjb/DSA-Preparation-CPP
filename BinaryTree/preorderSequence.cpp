/*
Problem: Preorder Traversal of Binary Tree

Traversal Order:
Root → Left → Right

Approach:
- Visit the root node first.
- Recursively traverse the left subtree.
- Recursively traverse the right subtree.

Algorithm:
1. Print current node value.
2. Call preorder for left child.
3. Call preorder for right child.

Time Complexity: O(n)
- Every node is visited exactly once.

Space Complexity: O(h)
- h = height of tree (recursion stack).
*/

#include<iostream>
#include<vector>
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
static int idx = -1;
Node* buildTree(vector<int>preorder){
    idx++;
    if(preorder[idx] == -1) return NULL;
    Node* root = new Node(preorder[idx]);
    root->left = buildTree(preorder);
    root->right = buildTree(preorder);
    return root;
}

int main(){
    vector<int>preorder = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    Node* root = buildTree(preorder);
    cout<<root->data<<endl;
    cout<<"left value is "<<root->left->data<<" "<<"right value is : "<<root->right->data<<endl;

    return 0;
}

/*
Preorder Traversal
Order: Root → Left → Right
Time: O(n)
Space: O(h)
*/