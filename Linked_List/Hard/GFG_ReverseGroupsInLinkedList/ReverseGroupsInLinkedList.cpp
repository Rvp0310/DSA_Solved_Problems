/* 
Date: December 16, 2025
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/batch/gfg-160-problems/track/linked-list-gfg-160/problem/reverse-a-linked-list-in-groups-of-given-size)
-----------------------------------------------------------
Problem Statement: 
You are given the head of a Singly linked list. You have to reverse every k node in the linked list and return the head of the modified list.
Note: If the number of nodes is not a multiple of k then the left-out nodes at the end, should be considered as a group and must be reversed.
-----------------------------------------------------------
Approach:
The linked list is processed in groups of size k. For each group, the next k nodes are taken and their links are reversed one by one using three pointers, just like a normal linked list reversal. The first node of the group becomes the last node after reversal and is used to connect with the next reversed group. A separate pointer keeps track of the tail of the previous group so that all reversed parts are linked correctly. This process continues until the end of the list, and even the last group with fewer than k nodes is reversed. The head of the first reversed group is returned as the new head of the list.
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
    Node *reverseKGroup(Node *head, int k) {
        if (k == 0 || head == NULL){
            return head;
        }
        
        Node *curr = head, *prevGroupTail = NULL, *newHead = NULL;
        
        while(curr != NULL){
            Node *prev_node = NULL, *groupHead = curr;
            int count = 0;
            
            while(curr != NULL && count < k){
                Node *next_node = curr -> next;
                curr -> next = prev_node;
                prev_node = curr;
                curr = next_node;
                count++;
            }
            
            if(newHead == NULL){
                newHead = prev_node;
            }
            
            if(prevGroupTail != NULL){
                prevGroupTail -> next = prev_node;
            }
            
            prevGroupTail = groupHead;
        }
        
        return newHead;
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

    cout << "Enter the group length:" << endl;
    cin >> x;

    cout << "Originally:" << endl;
    printList(head);

    Solution s;
    head = s.reverseKGroup(head, x);

    cout << "Reversed " << x <<" length groups in list:" << endl;
    printList(head);
    
    return 0;
}