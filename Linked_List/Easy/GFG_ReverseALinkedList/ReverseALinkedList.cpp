/* 
Date: December 15, 2025
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/batch/gfg-160-problems/track/linked-list-gfg-160/problem/reverse-a-linked-list)
-----------------------------------------------------------
Problem Statement: 
You are given the head of a singly linked list. You have to reverse the linked list and return the head of the reversed list.
-----------------------------------------------------------
Approach:
Start with two pointers: one pointing to NULL (this will become the previous node) and one pointing to the head of the list (the current node). While the current node is not NULL, first store its next node so the rest of the list is not lost. Then reverse the link by making the current node point to the previous node. After that, move the previous pointer to the current node and move the current pointer to the stored next node. When the loop ends, the previous pointer points to the new head of the reversed list, which is returned.
-----------------------------------------------------------
Time Complexity: O(n)
Space Complexity: O(1)
*/

# include <iostream>
# include <string>
#include <sstream>

using namespace std;

class Node {
 public:
    int data ;
    Node *next ;

    Node(int x) {
        data = x ;
        next = NULL ;
    }
};

class Solution {
  public:
    Node* reverseList(Node* head) {
        Node* prev_node = NULL;
        Node* curr_node = head;
        while(curr_node != NULL){
            Node* next_node = curr_node -> next;
            curr_node -> next = prev_node;
            prev_node = curr_node;
            curr_node = next_node;
        }
        return prev_node;
    }
};

void printList(Node *node){
    while(node != nullptr) {
        cout << node -> data << " ";
        if(node -> next != NULL){
            cout << "-> ";
        } 
        node = node -> next;
    }
    cout << endl;
}

int main(){
    Node *head = NULL, *tail = NULL;
    cout << "Enter the elements of linked list (space separated):" << endl;
    string input;
    getline(cin, input);
    stringstream ss(input);
    int x;
    while(ss >> x){
        Node* newNode = new Node(x);

        if(head == NULL){
            head = newNode;
            tail = newNode;
        } else {
            tail -> next = newNode;
            tail = newNode;
        }
    }

    cout << "Originally:" << endl;
    printList(head);

    Solution s;
    head = s.reverseList(head);

    cout << "Reversed:" << endl;
    printList(head);
    
    return 0;
}