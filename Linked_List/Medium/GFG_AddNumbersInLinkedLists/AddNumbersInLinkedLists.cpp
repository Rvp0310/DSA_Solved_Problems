/* 
Date: December 17, 2025
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/batch/gfg-160-problems/track/linked-list-gfg-160/problem/add-two-numbers-represented-by-linked-lists)
-----------------------------------------------------------
Problem Statement: 
You are given the head of two singly linked lists head1 and head2 representing two non-negative integers. You have to return the head of the linked list representing the sum of these two numbers.

Note: There can be leading zeros in the input lists, but there should not be any leading zeros in the output list.
-----------------------------------------------------------
Approach:
Leading zeros are first skipped from both linked lists to ensure a clean representation of the numbers. If both lists contain only zeros, a single node with value 0 is returned. Each list is then reversed so that the least significant digits come to the front, making addition straightforward. The two lists are traversed together, adding corresponding digits along with a carry, and new nodes are created for the result. If one list is longer, the remaining digits are added with the carry. Any leftover carry after traversal is added as a new node. While forming the result, nodes are linked in reverse order so that the final list represents the sum in correct forward order without leading zeros.
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
    Node* addTwoLists(Node* head1, Node* head2) {
        
        // skip the trailing zero
        while(head1 != NULL && head1 -> data == 0){
            head1 = head1 -> next;
        }
        while(head2 != NULL && head2 -> data == 0){
            head2 = head2 -> next;
        }
        
        // if one of the list was just zeros
        if(head1 == NULL && head2 == NULL){
            return new Node(0);
        }
        if(head1 == NULL){
            return head2;
        }
        if(head2 == NULL){
            return head1;
        }
        
        
        // reverse the lists
        Node *prev1 = NULL;
        while(head1 != NULL){
            Node* next_node = head1 -> next;
            head1 -> next = prev1;
            prev1 = head1;
            head1 = next_node;
        }
        
        Node *prev2 = NULL;
        while(head2 != NULL){
            Node* next_node = head2 -> next;
            head2 -> next = prev2;
            prev2 = head2;
            head2 = next_node;
        }
        
        head1 = prev1, head2 = prev2;
        
        // now the heads are at the 0th places
        int carry = 0;
        Node *prev = NULL;
        while(head1 != NULL && head2 != NULL){
            Node *curr = new Node((head1 -> data + head2 -> data + carry) % 10);
            curr -> next = prev;
            carry = (head1 -> data + head2 -> data + carry) / 10;
            prev = curr;
            head1 = head1 -> next;
            head2 = head2 -> next;
        }
        
        while(head1 != NULL){
            Node *curr = new Node((head1 -> data + carry) % 10);
            carry = (head1 -> data + carry) / 10;
            curr -> next = prev;
            prev = curr;
            head1 = head1 -> next;
        }
        
        while(head2 != NULL){
            Node *curr = new Node((head2 -> data + carry) % 10);
            carry = (head2 -> data + carry) / 10;
            curr -> next = prev;
            prev = curr;
            head2 = head2 -> next;
        }
        
        
        
        // newHead
        if (carry){
            Node *curr = new Node(carry);
            curr -> next = prev;
            prev = curr;
        }
        return prev;
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
    Node *head1 = NULL, *tail1;
    cout << "Enter the digits in first linked list / number (space separated):" << endl;
    string input1;
    getline(cin, input1);
    stringstream ss1(input1);
    int x;
    while(ss1 >> x){
        Node* newNode1 = new Node(x);

        if(head1 == NULL){
            head1 = newNode1;
            tail1 = newNode1;
        } else {
            tail1 -> next = newNode1;
            tail1 = newNode1;
        }
    }

    Node *head2 = NULL, *tail2;
    cout << "Enter the digits in second linked list / number (space separated):" << endl;
    string input2;
    getline(cin, input2);
    stringstream ss2(input2);
    while(ss2 >> x){
        Node* newNode2 = new Node(x);

        if(head2 == NULL){
            head2 = newNode2;
            tail2 = newNode2;
        } else {
            tail2 -> next = newNode2;
            tail2 = newNode2;
        }
    }

    cout << "First Linked List:" << endl;
    printList(head1);
    cout << "Second Linked List:" << endl;
    printList(head2);
    

    Solution s;
    Node *head = s.addTwoLists(head1, head2);

    cout << "Summed Number/Linked List from above:" << endl;
    printList(head);
    
    return 0;
}