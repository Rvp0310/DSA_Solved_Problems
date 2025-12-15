/* 
Date: December 15, 2025
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/batch/gfg-160-problems/track/linked-list-gfg-160/problem/rotate-a-linked-list)
-----------------------------------------------------------
Problem Statement: 
You are given the head of a singly linked list, you have to left rotate the linked list k times. Return the head of the modified linked list.
-----------------------------------------------------------
Approach:
The length of the linked list is found by traversing it once, and the rotation count k is reduced using modulo to avoid extra full rotations. If the effective rotation becomes zero, the list remains unchanged. Otherwise, the last node is linked to the head to temporarily make the list circular. Starting from the original head, the pointer is moved k steps to reach the node just before the new head. The link is then broken at this point, and the next node becomes the new head of the rotated list.
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
    Node* rotate(Node* head, int k) {
        if (k == 0 || head == NULL){
            return head;
        }
        
        int l = 1;
        Node* curr_node = head;
        while(curr_node -> next != NULL){
            curr_node = curr_node -> next;
            l++;
        }
        
        k = k % l;
        if(k == 0){
            return head;
        }
        
        curr_node -> next = head;
        curr_node = head;
        
        for(int i = 1; i < k; i++){
            curr_node = curr_node -> next;
        }
        
        head = curr_node -> next;
        curr_node -> next = NULL;
        
        return head;
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

    cout << "Enter the count to rotate by:" << endl;
    cin >> x;

    cout << "Originally:" << endl;
    printList(head);

    Solution s;
    head = s.rotate(head, x);

    cout << "Rotated " << x <<" times:" << endl;
    printList(head);
    
    return 0;
}