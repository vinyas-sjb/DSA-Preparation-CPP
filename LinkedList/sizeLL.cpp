/*
Problem: Size of LinkedList
Platform: Self problem 
Time Complexity: O(n)→ because each node is visited once.
Space Complexity: O(1)→ only a counter and a pointer are used.
*/

#include<iostream>
using namespace std;


class Node{
    public:
    int data;
    Node*next;

    Node(int val){
        data=val;
        next=nullptr;
    }
};
class List{
    Node* head;
    Node* last;
    public:
    List(){
        head = last = nullptr;
    }

    void push_front(int val){
        Node* newnode = new Node(val);
        if(head == nullptr){
            head = newnode;
            return;
        }else{
            newnode->next = head;
            head = newnode;
        }
    }

    void printLL(){
        Node* temp=head;
        while(temp!=nullptr){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }

    int sizeLL(){
        Node* temp=head;
        int count=0;
        while(temp!=nullptr){
            temp=temp->next;
            count++;
        }
        return count;
    }
};

int main(){
    List l;
    l.push_front(1);
    l.push_front(2);
    l.push_front(3);
    l.push_front(4);
    l.push_front(5);
    l.printLL();
    int size = l.sizeLL();

    if(size%2==0){
        cout<<"size os even : "<<size<<endl; 
    }else{
        cout<<"size is odd : "<<size<<endl;
    }
}