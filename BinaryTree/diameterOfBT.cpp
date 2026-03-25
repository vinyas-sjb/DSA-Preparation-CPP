/*
Problem: Diameter of Binary Tree

Definition:
- The diameter of a binary tree is the length of the longest path 
  between any two nodes in the tree.
- This path may or may not pass through the root.

Diameter Calculation:
For every node:
diameter = height(left subtree) + height(right subtree)

Approach:
1. For each node, calculate the height of its left subtree.
2. Calculate the height of its right subtree.
3. Compute the diameter passing through that node.
4. Recursively compute the diameter of the left subtree.
5. Recursively compute the diameter of the right subtree.
6. Return the maximum of:
      - diameter of left subtree
      - diameter of right subtree
      - diameter passing through current node

Why Time Complexity is O(n²):
- The height() function takes O(n).
- diameterOfBT() calls height() for every node.
- Therefore total complexity becomes O(n × n) = O(n²).

Time Complexity: O(n²)
Space Complexity: O(h)
- h is the height of the tree due to recursion stack.
*/

/*
Function: height(Node* root)

Purpose:
- Computes the height of the binary tree.

Definition:
- Height is the number of nodes in the longest path 
  from the current node to a leaf node.

Logic:
1. Recursively compute height of left subtree.
2. Recursively compute height of right subtree.
3. Return max(leftHeight, rightHeight) + 1.

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

 static int idx=-1;
Node* buildTree(vector<int>&preOrder){
    idx++;
    if(preOrder[idx]==-1){
        return NULL;
    }
    Node* root = new Node(preOrder[idx]);
    root->left = buildTree(preOrder);
    root->right = buildTree(preOrder);
    return root;

}

//calculte the diameter of BT //
int height(Node* root){
    if(root==NULL) return 0;

    int lHt = height(root->left);
    int rHt = height(root->right);
    return max(lHt,rHt)+1;
}

int diameterOfBT(Node* root){
    if(root==NULL){
        return 0;
    }
    int leftHt = diameterOfBT(root->left);
    int rightHt = diameterOfBT(root->right);
    // to check max height of left and right in height function //
    int currDia = height(root->left)+height(root->right);
    return max(currDia, max(leftHt,rightHt));
}

int main(){
    vector<int>preOrder = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    Node* root = buildTree(preOrder);

    cout<<"the maximum diamter of BT is : "<<diameterOfBT(root)<<endl;
    return 0;
}

/*
Problem: Diameter of Binary Tree

The diameter of a binary tree is the longest path between 
any two nodes in the tree.
*/

/*
Key Idea:
For every node, calculate the height of its left and right subtree.
The diameter through that node is:
height(left) + height(right)
*/

/*
Formula:
diameter = height(left subtree) + height(right subtree)
*/

/*
Traversal Used:
The recursion works similar to postorder traversal
(Left → Right → Root).
*/

/*
Example Tree:

        1
       / \
      2   3
         / \
        4   5

Longest Path:
2 → 1 → 3 → 4

Diameter = 3 edges
*/