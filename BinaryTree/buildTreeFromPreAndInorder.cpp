/*
Problem: Construct Binary Tree from Preorder and Inorder Traversal

Preorder Traversal:
Root → Left → Right

Inorder Traversal:
Left → Root → Right

Key Idea:
- Preorder gives the root of the tree.
- Inorder helps determine the left and right subtrees.

Approach:
1. Take the current element from preorder as the root.
2. Search this root in the inorder array.
3. Elements before the root in inorder form the left subtree.
4. Elements after the root form the right subtree.
5. Recursively construct left and right subtrees.

Example:

Preorder: 3 9 20 15 7
Inorder : 9 3 15 20 7

Constructed Tree:

        3
       / \
      9   20
         /  \
        15   7

Time Complexity: O(n²)
- Searching root in inorder takes O(n) each time.

Space Complexity: O(h)
- h = height of tree (recursion stack).
*/

/*
Function: search()

Purpose:
- Finds the index of a given value in the inorder array
  within a specific range.

Return:
- Index of the value if found.
- -1 if the value does not exist.
*/

/*
Function: helper()

Purpose:
- Recursively constructs the binary tree using preorder
  and inorder traversals.

Logic:
1. Create a node using the current preorder index.
2. Find this node in the inorder array.
3. Elements before the index form the left subtree.
4. Elements after the index form the right subtree.
5. Recursively build both subtrees.
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

// search a root Node in inOrder and return the val //
int search(vector<int>inOrder,int left,int right,int val){
    for(int i=left;i<=right;i++){
        if(inOrder[i] == val){
            return i;
        }
    }
    return -1;
}

// build a BT by root in PreOrder and build left and right subtree by using InOrder tree //
Node* helper(vector<int>&preOrder,vector<int>&inOrder,int &preIdx,int left,int right){

    Node* root = new Node(preOrder[preIdx]);
    if(left > right ){
        return NULL;
    }
    int inIdx = search(inOrder,left,right,preOrder[preIdx]);
    preIdx++;

    // after getting val in inOrder build left and right subtree //
    root->left = helper(preOrder,inOrder,preIdx,left,inIdx-1);
    root->right = helper(preOrder,inOrder,preIdx,inIdx+1,right);

    return root;
}

Node* buildTree(vector<int>&preOrder, vector<int>&inOrder){
    int preIdx = 0;
    return helper(preOrder,inOrder,preIdx,0,inOrder.size()-1);
}

// print inOrder Tree //
void printInorderTree(Node* root){
    if(root==NULL) return;
    printInorderTree(root->left);
    cout<<root->data<<" ";
    printInorderTree(root->right);

}

int main(){
    vector<int>preOrder = {3,9,20,15,7};
    vector<int>inOrder = {9,3,15,20,7};
    Node* root = buildTree(preOrder,inOrder);
    printInorderTree(root);
    return 0;
  
}

/*
In inorder traversal:
- Elements before the root belong to the left subtree.
- Elements after the root belong to the right subtree.
*/

/*
Function: printInorderTree()

Purpose:
- Prints the inorder traversal of the constructed
  binary tree to verify the tree structure.
*/

/*
Note:
preIdx is passed by reference so that its value
updates correctly across recursive calls while
building the tree.
*/

/*
preIdx is passed by reference so that its value
updates across recursive calls while building
the tree using preorder traversal.

This behaves similar to using a static index,
but reference passing avoids global/static variables.
*/

/*
Static variable retains its value across recursive calls,
so the index correctly moves through the preorder array
while constructing the binary tree.
*/