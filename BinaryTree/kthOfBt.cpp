/*
Problem: Print Kth Level of a Binary Tree

Definition:
- The Kth level of a binary tree contains all nodes that are
  exactly K edges away from the root.

Approach:
1. Use recursion to traverse the tree.
2. Decrease K in each recursive call.
3. When K becomes 1, print the node value.

Example Tree:

        1
       / \
      2   3
     /   / \
    7   4   5

K = 3

Output:
7 4 5

Traversal Used:
Depth First Traversal (Recursive)

Time Complexity: O(n)
- Every node is visited once.

Space Complexity: O(h)
- h is the height of the tree due to recursion stack.
*/

/*
Function: buildTree(vector<int> preOrder)

Purpose:
- Constructs a binary tree using preorder traversal.

Preorder Order:
Root → Left → Right

Logic:
1. Read the current value from the array.
2. If value is -1, return NULL (represents no node).
3. Create a new node.
4. Recursively build left subtree.
5. Recursively build right subtree.
*/

/*
Function: KthLevel(Node* root, int key)

Purpose:
- Prints all nodes present at the Kth level of the binary tree.

Logic:
1. If the node is NULL, stop recursion.
2. If key becomes 1, print the current node.
3. Recursively move to left and right subtree
   while decreasing the key value.
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

//Find Kth level of BT //
void KthLevel(Node* root, int key){
    if(root == NULL){
        return;
    }

    if(key == 1){
        cout<<root->data<<" ";
        return;
    }

    KthLevel(root->left,key-1);
    KthLevel(root->right,key-1);
}

int main(){
    vector<int>preOrder = {1,2,7,-1,-1,-1,3,4,-1,-1,5,-1,-1};
    Node* root = buildTree(preOrder);

    KthLevel(root,3);
}

// key represents the level number to print