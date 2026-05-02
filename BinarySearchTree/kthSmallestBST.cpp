/*
Problem: Kth Smallest Element in a BST

Category:
- Trees
- Binary Search Tree (BST)

Description:
- Given the root of a Binary Search Tree (BST)
  and an integer k, return the kth smallest
  element in the tree.

BST Property Used:
- Inorder traversal (Left → Root → Right)
  of a BST gives elements in sorted order.

Approach:
1. Perform inorder traversal of the BST.
2. Maintain a counter to track how many nodes
   have been visited.
3. When the counter reaches k, return the
   current node value.
4. Stop further traversal once the answer is found.

Example:

Input Tree:

        5
       / \
      3   6
     / \
    2   4
   /
  1

Inorder Traversal:
1, 2, 3, 4, 5, 6

k = 4

Output:
4

Explanation:
- The 4th smallest element in sorted order is 4.

Time Complexity: O(n)
- In worst case, we may visit all nodes.

Space Complexity: O(h)
- h = height of tree (recursion stack).

Concepts Used:
- Binary Search Tree (BST)
- Inorder Traversal
- Recursion
- Counting nodes
*/


/*
Function: kthSmallest(Node* root, int k)

Purpose:
- Find the kth smallest element in a BST.

Approach:
1. Traverse the left subtree.
2. Check if current node is the kth element
   using a counter (prevOrder).
3. If yes, return current node value.
4. Otherwise, increment counter.
5. Traverse the right subtree.
6. Return -1 if k is not found.

Important Note:
- Uses a class variable 'prevOrder' to track
  number of visited nodes during traversal.

Time Complexity: O(n)

Space Complexity: O(h)
*/


/*
Function: main()

Purpose:
- Create a sample BST.
- Call the kthSmallest function.
- Print the result.

Steps:
1. Construct the BST manually.
2. Call solution::kthSmallest().
3. Display the kth smallest element.

Output:
The kth smallest element in the BST.
*/

#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr){}
};

class solution{
    public:
    int prevOrder = 0;
    int kthSmallest(Node* root, int k){
        if(root == NULL) return -1;

        // left //
        if(root->left != NULL){
            int leftans = kthSmallest(root->left,k);
            if(leftans != -1){
                return leftans;
            }
        }

        // root //
        if(prevOrder+1 == k){
            return root->data;
        }
        prevOrder++;

        // right //
        if(root->right != NULL){
            int rightans = kthSmallest(root->right,k);
            if(rightans != -1){
                return rightans;
            }
        }
        return -1;
    }

};

int main(){
    solution obj;
    Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(6);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->left->left->left = new Node(1);

    cout<<"The Kth Smallest in BST is : "<<obj.kthSmallest(root,4);
    return 0;
}