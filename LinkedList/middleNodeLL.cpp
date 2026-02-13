/*
Problem: Reverse a Linked List
Platform: LeetCode
Approach: First create a LL then reverse it
Time Complexity: O(n)
Space Complexity: O(1)
*/

#include<iostream>
using namespace std;

//create Node of data to store value and next to point to address of next node//
class Node{
    public:
    int data;
    Node* next;
    Node(int val){
        data=val;
        next=NULL;
    }
};

class List{
    Node* head;
    public:
    List(){
        head = NULL;
    }

    /*insert elements to node or push_front*/
    void insert(int val){
        Node* newNode = new Node(val);
        if(head == NULL){
            head = newNode;
            return;
        }else{
        newNode->next = head;
        head = newNode;
        }
    }

    /*head is already a member of List class,
    so we can directly use it inside this function.
    No need to pass head as a parameter.*/ 
    void middleNodeLL(){
        Node* slow=head;
        Node* fast=head;

        if(head == NULL){
            cout<<"list is empty";
            return;
        }

        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        cout<<"Middle node value : "<<slow->data<<" ";
    }
};

int main(){
    List l;
    l.insert(1);
    l.insert(2);
    l.insert(3);
    l.insert(4);
    l.insert(5);
    l.middleNodeLL();
    return 0;
}