/*
Function: height(Node* root)

Purpose:
- Calculate the height of a binary tree.

Definition:
- Height is the number of nodes in the longest path
  from the root node to a leaf node.

Approach:
1. If the node is NULL, return 0.
2. Recursively calculate height of left subtree.
3. Recursively calculate height of right subtree.
4. Return max(leftHeight, rightHeight) + 1.

Time Complexity: O(n)
- Every node is visited exactly once.

Space Complexity: O(h)
- h = height of the tree (recursion stack).
*/

/*
Function: countNodes(Node* root)

Purpose:
- Count the total number of nodes present in a binary tree.

Approach:
1. If the node is NULL, return 0.
2. Recursively count nodes in left subtree.
3. Recursively count nodes in right subtree.
4. Total nodes = leftCount + rightCount + 1 (current node).

Time Complexity: O(n)
- Each node is visited once.

Space Complexity: O(h)
- h = height of the tree due to recursion stack.
*/

/*
Function: sumNodes(Node* root)

Purpose:
- Calculate the sum of all node values in the binary tree.

Approach:
1. If the node is NULL, return 0.
2. Recursively calculate sum of left subtree.
3. Recursively calculate sum of right subtree.
4. Total sum = leftSum + rightSum + root->data.

Time Complexity: O(n)
- Each node is visited once.

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
        data = val;
        left = right = NULL;
    }
};
static int idx=-1;
Node* buildTree(vector<int> &preOrder){
    idx++;
    if(preOrder[idx] == -1){
        return NULL;
    }
    Node* root = new Node(preOrder[idx]);
    root->left = buildTree(preOrder);
    root->right = buildTree(preOrder);

    return root;
}

// height of the tree //
int height(Node* root){
    if(root == NULL){
        return 0;
    }
    int leftHt = height(root->left);
    int rightHt = height(root->right);

    return max(leftHt,rightHt)+1;
}

// count of the nodes //
int count(Node* root){
    if(root == NULL){
        return 0;
    }
    int leftCount = count(root->left);
    int rightCount = count(root->right);
    return leftCount + rightCount + 1;
}

// sum of the tree //
int sum(Node* root){
    if(root == NULL){
        return 0;
    }
    int leftSum = sum(root->left);
    int rightSum = sum(root->right);
    return leftSum + rightSum + root->data;
}

int main(){
    vector<int>preOrder = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    Node* root = buildTree(preOrder);
    
    cout<<"height : "<<height(root)<<endl;
    cout<<"number of nodes in tree is : "<<count(root)<<endl;
    cout<<"sum of all nodes in a tree is : "<<sum(root)<<endl;
    return 0;

}