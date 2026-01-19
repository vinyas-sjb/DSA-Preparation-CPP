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

    //Push back in LL//

    void push_back(int val){
        Node* newnode = new Node(val);
        // if null //
        if(head == nullptr){
            head = tail = newnode;
        }
        // if not null //
        else{
            tail->next = newnode;
            tail = newnode;
        }
    }

    // Pop front //
    void pop_front(){
        Node* temp = head;
        //if null //

        if(head == nullptr){
            cout<<"Nothing to pop list is empty"<<endl;
            return;
        }

        //not null//
        head = head->next;
        temp->next = nullptr;
        delete temp;
    }

    // pop back //
    void pop_back(){
        Node* temp = head;
        //if null//
        if(head == nullptr){
            cout<<"list is empty";
            return;
        }
        //not null //
        while(temp->next!= tail){
            temp = temp->next;
        }
        temp->next = nullptr;
        delete tail;
        tail = temp;

    }

    //search element/key in LL//
    int search(int key){
        Node* temp = head;
        int idx = 0;
        while(temp!= nullptr){
            if(temp->data == key){
            return idx;
        }
        temp = temp->next;
        idx++;
        }
        
        return -1;
    }

    //insert in middle of LL //
    void insert(int val,int pos){
        Node* newnode = new Node(val);
        Node* temp = head;
        if(pos<0){
            cout<<"invalid \n";
            return;
        }
        if(pos == 0){
            Push_front(val);
            return;
        }

        for(int i=0;i<pos-1;i++){
            if(temp == nullptr){
                cout<<"invalid position";
                return;
            }
            temp = temp->next;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }

    // Print LL //
    void printLL(){
        Node* temp = head;
        while(temp!=nullptr){
            cout<<temp->data<<" -> ";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;
    }
 };

 int main(){
    List l;
    l.Push_front(1);
    l.Push_front(2);
    l.Push_front(3);
    l.insert(5,1);
    
    cout<<l.search(2)<<endl;;

    l.printLL();
 }
