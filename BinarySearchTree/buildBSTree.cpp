/*
Function: insert(Node* root, int val)

Purpose:
- Insert a new value into the Binary Search Tree (BST).

Definition:
- In a BST, all values smaller than the root go to the left subtree
  and all values greater than the root go to the right subtree.

Approach:
1. If the root is NULL, create a new node with the given value.
2. If val is smaller than root->data, recursively insert into the left subtree.
3. If val is greater than or equal to root->data, recursively insert into the right subtree.
4. Return the root node after insertion.

Time Complexity:
- Average Case: O(log n)
- Worst Case: O(n) (when the tree becomes skewed)

Space Complexity: O(h)
- h = height of the tree due to recursion stack.
*/

/*
Function: buildBST(vector<int>& arr)

Purpose:
- Build a Binary Search Tree (BST) using elements from an array.

Definition:
- The BST is constructed by inserting each element of the array
  into the tree one by one using the BST insertion rule.

Approach:
1. Initialize the root as NULL.
2. Traverse the array using a loop.
3. Insert each element into the BST using the insert() function.
4. Return the root of the constructed BST.

Time Complexity:
- Average Case: O(n log n)
- Worst Case: O(n²) when the tree becomes completely skewed.

Space Complexity: O(h)
- h = height of the tree.
*/

/*
Function: inorder(Node* root)

Purpose:
- Perform inorder traversal of a Binary Search Tree.

Definition:
- Inorder traversal visits nodes in the order:
  Left Subtree → Root → Right Subtree.

Property:
- In a BST, inorder traversal prints the elements in
  sorted (ascending) order.

Approach:
1. If the node is NULL, return.
2. Recursively traverse the left subtree.
3. Print the root node value.
4. Recursively traverse the right subtree.

Time Complexity: O(n)
- Each node is visited exactly once.

Space Complexity: O(h)
- h = height of the tree due to recursion stack.
*/

/*
BST/
 ├── buildBST.cpp
 ├── insertBST.cpp
 ├── inorderTraversal.cpp
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

void inorder(Node* root){

    if(root==NULL) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
int main(){
    vector<int>arr = {3,2,1,5,6,4};
    Node* root = buildBST(arr);
    cout<<"The elements in inorderTraversal of BST is : ";
    inorder(root);
    cout<<endl;

    return 0;
}