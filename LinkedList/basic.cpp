/*
1.create a node
2.create a continous list
*/
#include<iostream>
using namespace std;

 class Node{
    public:
    int data;
    Node* next;

    Node(int val){//to add val in NOde and it is parametrized constructr//
        data=val;
        next=nullptr;
    }
 };

 class List{
    Node* head;
    Node* tail;
public:
    List(){//default constructor//
        head = tail = nullptr;
    }

    //Push front in LL//
    void Push_front(int val){
        Node* newnode = new Node(val);
        //If Null//
        if(head == nullptr){
            head = tail = newnode;
            return;
        }
        //not NULL//
        else{
            newnode->next = head;
            head = newnode;
        }
    }

    // Print LL //
    void printLL(){
        Node* temp = head;
        while(temp!=nullptr){
            cout<<temp->data<<" -> ";
            temp = temp->next;
        }
    }
 };

 int main(){
    List l;
    l.Push_front(1);
    l.Push_front(2);
    l.Push_front(3);
    l.printLL();
 }
