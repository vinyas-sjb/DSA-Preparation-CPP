/*
Function: isIdentical(Node* p, Node* q)

Purpose:
- Check whether two binary trees are identical.

Definition:
- Two binary trees are identical if:
  1. Their structure is the same.
  2. The data stored in corresponding nodes is the same.

Approach:
1. If either of the nodes is NULL, return (p == q).
   - This returns true if both are NULL.
   - Returns false if only one is NULL.
2. Recursively check the left subtree of both trees.
3. Recursively check the right subtree of both trees.
4. Check if the current node values are equal.
5. Return true only if:
   - left subtree is identical
   - right subtree is identical
   - current node values are equal.

Time Complexity: O(n)
- Each node of both trees is visited once.

Space Complexity: O(h)
- h = height of the tree (due to recursion stack).
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

bool isIdentical(Node* p, Node* q){
    if(p == NULL || q == NULL){
        return p==q;
    }
    /* another way  
    if(p == NULL && q == NULL)
    return true;
    if(p == NULL || q == NULL)
    return false; 
    */

    bool leftNode = isIdentical(p->left,q->left);
    bool rightNode = isIdentical(p->right,q->right);
    return leftNode && rightNode && p->data == q->data;
}

int main(){
    // first tree nodes //
    Node* p = new Node(1);
    p->left = new Node(2);
    p->right = new Node(3);

    // second tree nodes //
    Node* q = new Node(1);
    q->left = new Node(2);
    q->right = new Node(3);

    if(isIdentical(p,q)){
        cout<<"the given tree is identical";
    }else{
        cout<<"the given tree is not identical";
    }

    return 0;
}

/*
// Base Condition:
// If either of the nodes is NULL, we compare the pointers directly.
// - If both p and q are NULL → return true (both trees ended at the same position).
// - If only one is NULL → return false (tree structures are different).
if (p == NULL || q == NULL) {
    return p == q;
}
*/