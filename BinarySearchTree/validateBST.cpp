/*
Problem: Validate Binary Search Tree

Category:
- Trees
- Binary Search Tree (BST)

Description:
- Given the root of a binary tree, determine whether
  it is a valid Binary Search Tree.

BST Property:
1. All values in the left subtree must be smaller
   than the root node.
2. All values in the right subtree must be greater
   than the root node.
3. Both left and right subtrees must also satisfy
   the BST property.

Approach:
1. Start from the root node.
2. Maintain a valid range (minimum and maximum values)
   for each node.
3. If the current node value violates the range,
   return false.
4. Recursively check the left subtree with an updated
   maximum boundary.
5. Recursively check the right subtree with an updated
   minimum boundary.
6. If all nodes satisfy the constraints, the tree
   is a valid BST.

Example:

Input Tree:

        5
       / \
      1   4
         / \
        3   6

Output:
Not Valid BST

Explanation:
- Node 3 is in the right subtree of 5 but is smaller
  than 5, violating the BST property.

Time Complexity: O(n)
- Each node is visited once.

Space Complexity: O(h)
- h = height of the tree due to recursion stack.

Concepts Used:
- Binary Trees
- Binary Search Tree validation
- Recursion
- Range checking
*/

/*
Function: isHelper(Node* root, Node* min, Node* max)

Purpose:
- Check whether the binary tree satisfies the
  Binary Search Tree (BST) property.

Definition:
- In a BST, every node must follow:
  • All values in the left subtree are smaller than the node.
  • All values in the right subtree are greater than the node.

Approach:
1. If the current node is NULL, return true.
2. If a minimum boundary exists and the node value
   is less than or equal to it, return false.
3. If a maximum boundary exists and the node value
   is greater than or equal to it, return false.
4. Recursively validate the left subtree while updating
   the maximum boundary to the current node.
5. Recursively validate the right subtree while updating
   the minimum boundary to the current node.
6. Return true only if both subtrees are valid.

Time Complexity: O(n)
- Every node in the tree is visited once.

Space Complexity: O(h)
- h is the height of the tree due to recursion stack.
*/

/*
Function: isBST(Node* root)

Purpose:
- Determine whether the given binary tree
  is a valid Binary Search Tree.

Approach:
1. Start checking from the root node.
2. Initially there are no minimum or maximum constraints.
3. Call the helper function to verify BST rules
   for all nodes in the tree.

Time Complexity: O(n)

Space Complexity: O(h)
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

class Solution{
    public:
    bool isHelper(Node* root,Node* min,Node* max){
        // base case //
        if(root == NULL) return true;

        if(min!=NULL && root->data <= min->data){
            return false;
        }
        if(max!=NULL && root->data >= max->data){
            return false;
        }

        return isHelper(root->left,min,root) && isHelper(root->right,root,max);
    }

    bool isBST(Node* root){
        return isHelper(root,NULL,NULL); 
    }
};

int main(){
    Node* root = new Node(5);
    root->left = new Node(1);
    root->right = new Node(4);
    root->right->left = new Node(3);
    root->right->right = new Node(6);

    Solution obj;
    if(obj.isBST(root)){
        cout<<"Valid BST"<<endl;
    }else{
        cout<<"Not Valid BST"<<endl;
    }
    return 0;
}