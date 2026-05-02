/*
Problem: Lowest Common Ancestor (LCA) in a Binary Search Tree

Category:
- Trees
- Binary Search Tree (BST)

Description:
- Given a Binary Search Tree (BST) and two nodes p and q,
  find their Lowest Common Ancestor (LCA).

Definition:
- The Lowest Common Ancestor is the lowest node in the tree
  that has both p and q as descendants (a node can be a
  descendant of itself).

BST Property Used:
1. Left subtree contains values smaller than the root.
2. Right subtree contains values greater than the root.

Approach:
1. Start from the root node.
2. If both p and q are smaller than root, move to left subtree.
3. If both p and q are greater than root, move to right subtree.
4. Otherwise, the current node is the LCA.

Example:

        6
       / \
      2   8
     / \ / \
    0  4 7  9
      / \
     3   5

p = 0, q = 4

Output:
LCA = 2

Time Complexity: O(h)
- h = height of the tree.

Space Complexity: O(h)
- Due to recursion stack.

Concepts Used:
- Binary Search Tree (BST)
- Recursion
- Tree traversal
*/


#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(NULL), right(NULL){}
};

class solution{
public:

    /*
    Function: LCA(Node* root, Node* p, Node* q)

    Purpose:
    - Find the Lowest Common Ancestor of two nodes in a BST.

    Approach:
    1. If root is NULL, return NULL.
    2. If both nodes are smaller than root, go left.
    3. If both nodes are greater than root, go right.
    4. Otherwise, root is the LCA.

    Time Complexity: O(h)
    Space Complexity: O(h)
    */

    Node* LCA(Node* root, Node* p, Node* q){
        if(root == NULL) return NULL;

        if(root->data > p->data && root->data > q->data){
            return LCA(root->left,p,q);
        }
        else if(root->data < p->data && root->data < q->data){
            return LCA(root->right,p,q);
        }
        else{
            return root;
        }
    }
};

int main(){
    solution obj;

    /*
        Constructing BST:

                6
               / \
              2   8
             / \ / \
            0  4 7  9
              / \
             3   5
    */

    Node* root = new Node(6);
    root->left = new Node(2);
    root->right = new Node(8);
    root->left->left = new Node(0);
    root->left->right = new Node(4);
    root->right->left = new Node(7);
    root->right->right = new Node(9);
    root->left->right->left = new Node(3);
    root->left->right->right = new Node(5);

    Node* p = root->left->left;   // Node 0
    Node* q = root->left->right;  // Node 4

    Node* ans = obj.LCA(root,p,q);

    cout<<"The LCA of given p and q in BST is : "<<ans->data;

    return 0;
}


/*
------------------------------------------------------------
Comparison: LCA in BST vs Normal Binary Tree
------------------------------------------------------------

1. Approach:
   - BST:
     Uses value comparison to decide direction.
   - Normal Binary Tree:
     Recursively searches both left and right subtrees.

2. Traversal:
   - BST:
     Traverses only one path (left OR right).
   - Normal Tree:
     Traverses both left AND right.

3. Time Complexity:
   - BST:
     O(h) → faster
   - Normal Tree:
     O(n) → slower

4. Logic:
   - BST:
     if(root > p && root > q) → go left
     if(root < p && root < q) → go right
     else → LCA found

   - Normal Tree:
     left = LCA(left subtree)
     right = LCA(right subtree)

     if(left && right) → root is LCA

5. Requirement:
   - BST:
     Tree must follow BST property
   - Normal Tree:
     Works for any binary tree

------------------------------------------------------------
Summary:
- BST LCA → Efficient using ordering property
- Binary Tree LCA → General solution using recursion
------------------------------------------------------------
*/

#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(NULL), right(NULL){}
};

class solution{
    public:
    Node* LCA(Node* root, Node* p, Node* q){
        if(root == NULL) return NULL;

        if(root->data > p->data && root->data > q->data){
            return LCA(root->left,p,q);
        }else if(root->data < p->data && root->data < q->data){
            return LCA(root->right,p,q);
        }else{
            return root;
        }
    }
};

int main(){
    solution obj;
    Node* root = new Node(6);
    root->left = new Node(2);
    root->right = new Node(8);
    root->left->left = new Node(0);
    root->left->right = new Node(4);
    root->right->left = new Node(7);
    root->right->right = new Node(9);
    root->left->right->left = new Node(3);
    root->left->right->right = new Node(5);

    Node* p = root->left->left;
    Node* q = root->left->right;
    Node* ans = obj.LCA(root,p,q);

    cout<<"The LCA of given p and q in BST is : "<<ans->data;
    return 0;
}