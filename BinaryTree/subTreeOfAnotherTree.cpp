
/*
Function: isIdentical(Node* p, Node* q)

Purpose:
- Check whether two binary trees are identical.

Definition:
- Two trees are identical if they have the same structure
  and the same data in corresponding nodes.

Approach:
1. If either node is NULL, return (p == q).
   - Returns true if both are NULL.
   - Returns false if only one is NULL.
2. Recursively check the left subtree of both trees.
3. Recursively check the right subtree of both trees.
4. Compare the data of the current nodes.
5. Return true only if left subtree, right subtree,
   and current node values are all equal.

Time Complexity: O(n)
- Each node is visited once during comparison.

Space Complexity: O(h)
- h = height of the tree (due to recursion stack).
*/


/*
Function: isSubtree(Node* root, Node* subRoot)

Purpose:
- Determine whether subRoot exists as a subtree
  inside the main binary tree (root).

Definition:
- A subtree is a node in the main tree along with
  all its descendants that exactly match subRoot.

Approach:
1. If the main tree node (root) is NULL, return false.
2. Check if the trees starting at root and subRoot
   are identical using isIdentical().
3. If identical, return true.
4. Otherwise recursively check:
   - Left subtree of root
   - Right subtree of root
5. If either side returns true, subRoot exists
   as a subtree.

Time Complexity: O(n * m)
- n = number of nodes in main tree
- m = number of nodes in subtree
- For each node of root we may compare the subtree.

Space Complexity: O(h)
- h = height of the tree due to recursion stack.
*/



#include<iostream>
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
    // after getting root in these two now check if they are identical or not //
    if(p==NULL || q==NULL){
        return p==q;
    }

    bool leftNode = isIdentical(p->left,q->left);
    bool rightNode = isIdentical(p->right,q->right);
    return leftNode && rightNode && p->data == q->data;
}

bool isSubtree(Node* root, Node* subRoot){
    // now check root element in rootTree which equal in subRoot Tree//
    if(root == NULL || subRoot == NULL){
        return root==subRoot;
    }
    
    if(root->data == subRoot->data && isIdentical(root,subRoot)){
        return true;
    }

    return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(4);
    root->right->right = new Node(5);

    Node* subRoot = new Node(3);
    subRoot->left = new Node(4);
    subRoot->right = new Node(5);

    if(isSubtree(root,subRoot)){
        cout<<"subtree found";
    }else{
        cout<<"subTree not found";
    }
}