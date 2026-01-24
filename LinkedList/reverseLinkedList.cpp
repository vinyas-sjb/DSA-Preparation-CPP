/*
Problem: Reverse a Linked List
Platform: LeetCode
Approach: First create a LL then reverse it
Time Complexity: O(n)
Space Complexity: O(1)
*/

#include<iostream>
using namespace std;

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

    void push_front(int val){
        Node* newnode = new Node(val);
        if(head == NULL){
            head = newnode;
            return;
        }else{
            newnode->next = head;
            head = newnode;
        }
    }

    void reverseLL(){
        //use 3 pointers prev,curr,next//
        Node* prev = NULL;
        Node* curr = head;
        Node* next = NULL;


        while(curr != NULL){
            next = curr->next;
            curr->next = prev;

            prev = curr;
            curr = next;
        }
        head = prev;
        
    }

    void printLL(){
        Node* temp = head;
        if(head == NULL){
            cout<<"LL is empty ";
            return;
        }

        cout<<"The LL elements are : ";
        while(temp != NULL){
            cout<<temp->data<<"->";
            temp = temp->next;
        }
        cout<<"NULL";
    }
};

int main(){
    List l;
    l.push_front(3);
    l.push_front(2);
    l.push_front(1);

    //before reverse LL //
    l.printLL();
    cout<<endl;

    //after reversing the LL//
    l.reverseLL();
    l.printLL();

    return 0;
}