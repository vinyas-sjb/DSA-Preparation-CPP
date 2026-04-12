/*
Problem: Convert Sorted Array to Balanced Binary Search Tree

Category:
- Trees
- Binary Search Tree (BST)

Description:
- Given a sorted array, construct a height-balanced
  Binary Search Tree.

Balanced BST Property:
- The difference between the heights of left and
  right subtrees should be minimal.

Approach:
1. Choose the middle element of the array as the root.
2. Recursively build the left subtree using the left half.
3. Recursively build the right subtree using the right half.
4. Repeat until all elements are used.

Example:

Input:
Sorted Array = [-10, -2, 0, 4, 5]

Constructed BST:

        0
       / \
    -10   4
      \     \
      -2     5

Time Complexity: O(n)
- Each element is used exactly once.

Space Complexity: O(log n)
- Recursion stack for balanced tree height.

Concepts Used:
- Binary Search Tree
- Divide and Conquer
- Recursion
*/

/*
Function: helper

Purpose:
- Construct a height-balanced Binary Search Tree (BST)
  from a sorted array using the divide-and-conquer approach.

Definition:
- A balanced BST is a tree where the difference between the
  heights of left and right subtrees is minimal.

Approach:
1. Find the middle element of the array/subarray.
2. Create a node using the middle element.
3. Recursively construct the left subtree using elements
   before the middle index.
4. Recursively construct the right subtree using elements
   after the middle index.
5. Return the root node of the constructed subtree.

Time Complexity: O(n)
- Each element is processed exactly once.

Space Complexity: O(log n)
- Due to recursion stack for balanced tree construction.
*/

/*
Function: sortedArr

Purpose:
- Convert a sorted array into a height-balanced Binary Search Tree.

Definition:
- The function acts as a wrapper that initializes the recursive
  helper function with the starting and ending indices.

Approach:
1. Take the sorted array as input.
2. Call the helper function with the first and last index.
3. The helper function constructs the balanced BST.
4. Return the root node of the balanced BST.

Time Complexity: O(n)
- All elements of the array are used once.

Space Complexity: O(log n)
- Recursion depth in a balanced tree.
*/

/*
Function: inorder

Purpose:
- Perform inorder traversal of the Binary Search Tree.

Definition:
- Inorder traversal visits nodes in the order:
  Left Subtree → Root → Right Subtree.

Property:
- In a Binary Search Tree, inorder traversal produces
  elements in sorted (ascending) order.

Approach:
1. Recursively traverse the left subtree.
2. Print the current node value.
3. Recursively traverse the right subtree.

Time Complexity: O(n)
- Each node is visited exactly once.

Space Complexity: O(h)
- h is the height of the tree due to recursion stack.
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

Node* helper(vector<int>arr, int st, int end){
    // base case //
    if(st > end) return NULL;

    int mid = st+(end-st)/2;
    Node* root = new Node(arr[mid]);
    root->left = helper(arr,st,mid-1);
    root->right = helper(arr,mid+1,end);
    return root;
}

Node* sortedArr(vector<int> &arr){
   return helper(arr,0,arr.size()-1);
}

// print balanced BST in Inorder Traversal //
void inorder(Node* root){
    if(root == NULL) return;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main(){
    vector<int>arr = {-10,-2,0,5,4};
    Node* root = sortedArr(arr);
    cout<<"The root value of balanced BST is : "<<root->data<<endl;

    // The inoder traversal tree //
    cout<<"The inorder traversal Tree is : ";
    inorder(root);
    return 0;

}