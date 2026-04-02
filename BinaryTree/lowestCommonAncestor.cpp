/*
Problem: Lowest Common Ancestor (LCA) in a Binary Tree

Definition:
- The Lowest Common Ancestor of two nodes p and q is the lowest
  node in the tree that has both p and q as descendants.

Example Tree:

            1
          /   \
         2     3
        / \   / \
       4   5 6   7
          / \
         8   9

Example:
p = 4
q = 9

Paths:
4 → 2 → 1
9 → 5 → 2 → 1

Lowest Common Ancestor = 2

Approach:
1. Traverse the tree recursively.
2. If the current node matches p or q, return the node.
3. Recursively search in left and right subtree.
4. If both sides return non-NULL, current node is the LCA.
5. If only one side returns non-NULL, propagate that node upward.

Traversal Used:
Depth First Search (DFS)

Time Complexity: O(n)
- Each node is visited at most once.

Space Complexity: O(h)
- h is the height of the tree due to recursion stack.
*/

/*
Function: buildTree(vector<int> preOrder)

Purpose:
- Construct a binary tree using preorder traversal.

Preorder Order:
Root → Left → Right

Logic:
1. Read current value from the array.
2. If value is -1, return NULL (represents empty node).
3. Create a new node.
4. Recursively build left subtree.
5. Recursively build right subtree.

Time Complexity: O(n)
*/

/*
Function: LCA(Node* root, int p, int q)

Purpose:
- Find the Lowest Common Ancestor of nodes p and q.

Logic:
1. If root is NULL, return NULL.
2. If root matches either p or q, return root.
3. Recursively find LCA in left and right subtree.
4. If both recursive calls return non-NULL,
   the current node is the LCA.
5. If only one side is non-NULL, return that node.
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
Node* buildTree(vector<int>preOrder){
    idx++;
    if(preOrder[idx] == -1){
        return NULL;
    }
    Node* root = new Node(preOrder[idx]);
    root->left = buildTree(preOrder);
    root->right = buildTree(preOrder);

    return root;
}

// lowest common ancestor //
Node* LCA(Node* root, int p, int q){
    // check if root is null //
    if(root == NULL) return NULL;

    // check if p lies under q or q under p , if yes return root of either one of those p and q //
    if(root->data == p || root->data == q){
        return root;
    }

    // if not check left and right LCA //
    Node* leftLCA = LCA(root->left,p,q);
    Node* rightLCA = LCA(root->right,p,q);

    if(leftLCA && rightLCA){ // if both are valid return root //
        return root;
    }else if(leftLCA != NULL){ // rightLCA is NULL //
        return leftLCA;
    }else{ // leftLCA is NULL //
        return rightLCA;
    }
}


int main(){
    vector<int>preOrder = {1,2,4,-1,-1,5,8,-1,-1,9,-1,-1,3,6,-1,-1,7,-1,-1};
    Node* root = buildTree(preOrder);
    int p=4;
    int q=9;
    Node* ans = LCA(root,p,q);
    cout<<"The LCA of BT for given p and q values is : "<<ans->data;

    return 0;
}

/*
Base Case:
If the current node is NULL,
there is no subtree to explore,
so return NULL.
*/

/*
If the current node matches either
p or q, return the current node.
This means we found one of the
required nodes.
*/

/*
Recursively search for p and q
in the left and right subtrees.
*/

/*
If both left and right recursive
calls return non-NULL, it means
p and q are found in different
subtrees, so the current node
is the Lowest Common Ancestor.
*/

/*
If only one subtree returns a
non-NULL value, propagate that
result upward in the recursion.
*/