/*
Problem: Palindrome Linked List
Platform: LeetCode
Link: https://leetcode.com/problems/palindrome-linked-list/

Approach:
1. Use slow and fast pointers to find the middle of the linked list.
2. Reverse the second half of the linked list.
3. Compare the first half and the reversed second half.

Patterns Used:
- Slow & Fast Pointer
- Reverse Linked List

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
        data = val;
        next = NULL;
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

    //ex: 1->2->2->3->2->2->1//
    bool ispalindrome(){
        //check the middle using slow/fast approah //
        if (head==NULL || head->next==NULL) return true;
        Node* slow = head;
        Node* fast = head;

        
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }

        /*reverse the second half*/
        Node* prev=NULL;
        while(slow){ /*means slow!=NULL*/
           Node* nextNode=slow->next;;
           slow->next=prev;

            prev=slow;
            slow=nextNode;
        }

        /*compare*/
        Node* left=head;
        Node* right=prev;
        while(right){
            if(left->data != right->data){
                return false;
            }
            left=left->next;
            right=right->next;
        }
        return true;
    }
};
int main(){
    List l;
    l.insert(1);
    l.insert(2);
    l.insert(2);
    l.insert(3);
    l.insert(2);
    l.insert(2);
    l.insert(1);

    int palindrome = l.ispalindrome();
    cout<<(palindrome ? "isPalindrome" : "notPalindrome")<<endl;
}