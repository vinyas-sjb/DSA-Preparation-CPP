/*
Problem: Transform a Binary Tree into a Sum Tree

Definition:
- In a Sum Tree, each node stores the sum of the values
  of its left and right subtrees in the original tree.

Example:

Original Tree:
        1
       / \
      2   3
         / \
        4   5

After Transformation:
        15
       /  \
      2    12
          /  \
         4    5

Approach:
1. Traverse the tree using postorder traversal.
2. Recursively compute the sum of the left subtree.
3. Recursively compute the sum of the right subtree.
4. Update the current node value by adding both subtree sums.
5. Return the updated sum to the parent node.

Traversal Used:
Postorder Traversal (Left → Right → Root)

Time Complexity: O(n)
- Each node is visited exactly once.

Space Complexity: O(h)
- h is the height of the tree due to recursion stack.
*/

/*
Function: BuildTree()

Purpose:
- Constructs a binary tree using preorder traversal.
- Value -1 represents a NULL node.

Traversal Order:
Root → Left → Right

Logic:
1. Read the current value from the preorder array.
2. If the value is -1, return NULL.
3. Create a node with the current value.
4. Recursively build the left subtree.
5. Recursively build the right subtree.
*/

/*
Function: printPreOrder()

Purpose:
- Prints the preorder traversal of the binary tree.

Traversal Order:
Root → Left → Right

Used to verify the tree structure before
and after transformation.
*/

/*
Function: sumTree()

Purpose:
- Converts the binary tree into a Sum Tree.

Logic:
1. Recursively calculate the sum of the left subtree.
2. Recursively calculate the sum of the right subtree.
3. Update the current node value as:
   root->data = root->data + leftSum + rightSum
4. Return the updated value to the parent node.
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
Node* BuildTree(vector<int>& preOrder){
    idx++;
    if(preOrder[idx]==-1) return NULL;

    Node* root = new Node(preOrder[idx]);
    root->left = BuildTree(preOrder);
    root->right = BuildTree(preOrder);

    return root;
}

// Print preOrder //
void printPreOrder(Node* root){
    if(root==NULL) return;

    cout<<root->data<<" ";
    printPreOrder(root->left);
    printPreOrder(root->right);

}

// transform to sum Tree //
int sumTree(Node* root){
    if(root == NULL) return 0;

    int leftSum = sumTree(root->left);
    int rightSum = sumTree(root->right);
    root->data += leftSum+rightSum;
    return root->data;
}

int main(){
    vector<int>preOrder = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    Node* root = BuildTree(preOrder);

    cout<<"Before Transformation : ";
    printPreOrder(root);
    cout<<endl;

    sumTree(root);
    
    cout<<"After Transformation : ";
    printPreOrder(root);
    cout<<endl;
    
    return 0;
}

/*
Static index is used to track the current position
in the preorder array while building the tree.
*/

/*
Example Output:

Before Transformation:
1 2 3 4 5

After Transformation:
15 2 12 4 5
*/