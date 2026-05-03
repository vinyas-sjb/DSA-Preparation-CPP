/*
============================================================
Problem: Delete Node in Binary Search Tree (BST)
============================================================

Concept:
- BST property: left < root < right

Cases:
1. No child → delete node
2. One child → replace with child
3. Two children →
   - Find inorder successor (leftmost of right subtree)
   - Replace value
   - Delete successor

Time Complexity: O(h)
Space Complexity: O(h)
============================================================
*/

#include<iostream>
using namespace std;

/*---------------- Node Definition ----------------*/
class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(NULL), right(NULL) {}
};

/*----------- Inorder Successor --------------------*/
// Returns smallest node in given subtree
Node* getInorderSuccessor(Node* root){
    while(root && root->left){
        root = root->left;
    }
    return root;
}

/*--------------- Delete Function ------------------*/
Node* deleteNode(Node* root, int key){
    if(root == NULL) return NULL;

    // Search for node
    if(key < root->data){
        root->left = deleteNode(root->left, key);
    }
    else if(key > root->data){
        root->right = deleteNode(root->right, key);
    }
    else{
        // Case 1 & 2: 0 or 1 child
        if(root->left == NULL){
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if(root->right == NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Case 3: 2 children
        Node* IS = getInorderSuccessor(root->right);
        root->data = IS->data;
        root->right = deleteNode(root->right, IS->data);
    }
    return root;
}

/*--------------- Inorder Traversal ----------------*/
void inorder(Node* root){
    if(root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

/*---------------------- Main ----------------------*/
int main(){
    /*
        BST:
              3
             / \
            2   5
           /   / \
          1   4   6
    */

    Node* root = new Node(3);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(1);
    root->right->left = new Node(4);
    root->right->right = new Node(6);

    cout << "Before: ";
    inorder(root);

    root = deleteNode(root, 5);

    cout << "\nAfter: ";
    inorder(root);

    return 0;
}

/*
Inorder Successor (BST)

- Successor = next greater node
- Found using BST property

Logic:
1. If right subtree exists:
   → go right, then find leftmost node
2. If no right subtree:
   → move from root and track last greater ancestor

Time Complexity: O(h)
(h = height of BST)
*/