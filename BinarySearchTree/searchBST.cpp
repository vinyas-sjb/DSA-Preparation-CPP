/*
Function: insert(Node* root, int val)

Purpose:
- Insert a new value into the Binary Search Tree (BST).

Definition:
- A Binary Search Tree follows this property:
  Left subtree contains values smaller than the root,
  Right subtree contains values greater than the root.

Approach:
1. If the root node is NULL, create a new node with the given value.
2. If the value is smaller than root->data, recursively insert into the left subtree.
3. Otherwise, recursively insert into the right subtree.
4. Return the root node after insertion.

Time Complexity:
- Average Case: O(log n)
- Worst Case: O(n) when the tree becomes skewed.

Space Complexity: O(h)
- h = height of the tree due to recursion stack.
*/

/*
Function: buildBST(vector<int>& arr)

Purpose:
- Construct a Binary Search Tree (BST) using elements from an array.

Definition:
- Each element of the array is inserted into the BST
  following the BST insertion rule.

Approach:
1. Initialize the root as NULL.
2. Traverse the array using a loop.
3. Insert each element into the BST using the insert() function.
4. Return the root of the constructed BST.

Time Complexity:
- Average Case: O(n log n)
- Worst Case: O(n²) if the tree becomes completely skewed.

Space Complexity: O(h)
- h = height of the tree.
*/

/*
Function: search(Node* root, int key)

Purpose:
- Search for a specific key value in a Binary Search Tree.

Definition:
- The BST property allows efficient searching by
  comparing the key with the current node value.

Approach:
1. If the root is NULL, the key is not present → return false.
2. If root->data equals the key, return true.
3. If key is smaller than root->data, search in the left subtree.
4. If key is greater than root->data, search in the right subtree.

Time Complexity:
- Average Case: O(log n)
- Worst Case: O(n) when the tree becomes skewed.

Space Complexity: O(h)
- h = height of the tree due to recursion stack.
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
        data=val;
        left=right=NULL;
    }
};

//insert elements in buildBST //
Node* insert(Node* root, int val){
    if(root == NULL){
        return new Node(val);
    }

    if(val < root->data){
        root->left = insert(root->left,val);
    }else{
        root->right = insert(root->right,val);
    }
    return root;

}

// build a BST //
Node* buildBST(vector<int>&arr){
    Node* root = NULL;
    for(int val : arr){
        root = insert(root,val);
    }
    return root;
}

// search element/key value in BST //
bool search(Node* root, int key){ //0(height) -> 0(logn) 
    if(root==NULL) return false;
    if(root->data == key){
        return true;
    }

    if(key < root->data){
    return search(root->left,key);
    }else{
    return search(root->right,key);
    }
}

int main(){
    vector<int>arr = {3,2,1,5,6,4};
    Node* root = buildBST(arr);
    cout<<search(root,8);
    return 0;
}

/*
Program: Binary Search Tree Implementation

Features Implemented:
1. Insert elements into BST
2. Build BST from an array
3. Search a key in BST

Concepts Used:
- Recursion
- Binary Search Tree properties
- Tree traversal logic
*/