/*
============================================================
Problem: Lowest Common Ancestor (LCA) in a Binary Search Tree
============================================================

Category:
- Trees
- Binary Search Tree (BST)

Description:
- Given a BST and two nodes p and q, find their Lowest
  Common Ancestor (LCA).

Definition:
- LCA is the lowest node that has both p and q as descendants.

Key Insight (BST Property):
- Left subtree → values < root
- Right subtree → values > root

Approach:
1. Start from root.
2. If both p and q are smaller → go left.
3. If both p and q are greater → go right.
4. Otherwise → current node is LCA.

Example:
        6
       / \
      2   8
     / \ / \
    0  4 7  9
      / \
     3   5

p = 0, q = 4 → LCA = 2

Time Complexity: O(h)
Space Complexity: O(h)

============================================================
*/

#include <iostream>
using namespace std;

/*----------------------- Node Definition -----------------------*/
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

/*----------------------- Solution Class ------------------------*/
class Solution {
public:

    /*
    Function: LCA
    Purpose: Returns Lowest Common Ancestor of p and q
    */
    Node* LCA(Node* root, Node* p, Node* q) {
        if (!root) return nullptr;

        if (root->data > p->data && root->data > q->data)
            return LCA(root->left, p, q);

        if (root->data < p->data && root->data < q->data)
            return LCA(root->right, p, q);

        return root;
    }
};

/*---------------------------- Main -----------------------------*/
int main() {

    /*
        BST Structure:
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

    Node* p = root->left->left;   // 0
    Node* q = root->left->right;  // 4

    Solution obj;
    Node* ans = obj.LCA(root, p, q);

    cout << "LCA: " << ans->data << endl;

    return 0;
}

/*
============================================================
Comparison: BST vs Normal Binary Tree (LCA)
============================================================

BST:
- Uses value comparison
- Traverses one path only
- Time: O(h)
- Faster and optimized

Normal Binary Tree:
- Searches both left and right
- No value comparison
- Time: O(n)
- General solution

Summary:
BST → Efficient (uses ordering)
BT  → Flexible (works everywhere)

============================================================
*/