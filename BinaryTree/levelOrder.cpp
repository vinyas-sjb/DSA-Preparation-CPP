#include<iostream>
#include<vector>
#include<queue>
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
static int idx=-1;
Node* buildTree( vector<int>preOrder){
    idx++;
    if(preOrder[idx] == -1){
        return NULL;
    }
    Node* root = new Node(preOrder[idx]);
    root->left = buildTree(preOrder);
    root->right = buildTree(preOrder);
    return root;

}

// postOrder traversal //
void postOrder(Node* root){
    if(root == NULL){
        return;
    }
     postOrder(root->left);
     postOrder(root->right);
     cout<<root->data<<" ";
}

// level order sequence //
void levelOrder(Node* root){
    queue<Node*>q;
    q.push(root);

    while(q.size() > 0){
        Node* curr = q.front();
        q.pop();

        cout<<curr->data<<" ";
        if(curr->left!=NULL){
            q.push(curr->left);
        }
        if(curr->right!=NULL){
            q.push(curr->right);
        }
    }
    cout<<endl;

}

int main(){
    vector<int>preOrder = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    Node* root = buildTree(preOrder);
    cout<<"postOrder sequence is : ";
    postOrder(root);
    cout<<endl;

    cout<<"level order sequence is : ";
    levelOrder(root);
    
}