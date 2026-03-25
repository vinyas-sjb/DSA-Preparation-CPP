/*
Problem: Diameter of Binary Tree (Optimized Solution)

Definition:
- The diameter of a binary tree is the length of the longest path 
  between any two nodes in the tree.
- This path may or may not pass through the root node.

Optimized Idea:
- Instead of calculating height separately for each node,
  we compute the height and update the diameter in the same traversal.
- While calculating the height of a node, we also check the diameter
  passing through that node.

Diameter Calculation:
For each node:
diameter = height(left subtree) + height(right subtree)

Approach:
1. Traverse the tree recursively.
2. Compute the height of the left subtree.
3. Compute the height of the right subtree.
4. Calculate the diameter passing through the current node.
5. Update the global maximum diameter variable.
6. Return the height of the current node to its parent.

Traversal Used:
The recursion follows Postorder Traversal
(Left → Right → Root).

Why Time Complexity is O(n):
- Each node is visited only once.
- Height and diameter are calculated in the same traversal.

Time Complexity: O(n)
Space Complexity: O(h)
- h is the height of the tree due to recursion stack.
*/

/*
Function: height(Node* root)

Purpose:
- Computes the height of the binary tree while simultaneously
  updating the diameter of the tree.

Logic:
1. Recursively calculate the height of the left subtree.
2. Recursively calculate the height of the right subtree.
3. Compute diameter through the current node:
      leftHeight + rightHeight
4. Update the global variable `ans` if this diameter is larger.
5. Return max(leftHeight, rightHeight) + 1 as the height.

Time Complexity: O(n)
Space Complexity: O(h)
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
Node* buildTree(vector<int>&preOrder){
    idx++;
    if(preOrder[idx]==-1){
        return NULL;
    }
    Node* root = new Node(preOrder[idx]);
    root->left = buildTree(preOrder);
    root->right = buildTree(preOrder);
    return root;

}

//calculte the diameter of BT in optimised solution 0(n)//
int ans=0;
int height(Node* root){
    if(root==NULL) return 0;

    int lHt = height(root->left);
    int rHt = height(root->right);
    int currDia = lHt+rHt;
    ans = max(ans,currDia);
    return max(lHt,rHt)+1;
}

int diameterOfBT(Node* root){
    height(root);

    return ans;
}

int main(){
    vector<int>preOrder = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    Node* root = buildTree(preOrder);

    cout<<"the maximum diamter of BT is : "<<diameterOfBT(root)<<endl;
    return 0;
}
