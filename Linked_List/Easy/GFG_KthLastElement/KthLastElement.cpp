/*
Date: June 5, 2026
Platform: GFG (https://www.geeksforgeeks.org/problems/nth-node-from-end-of-linked-list/1?page=3&sortBy=submissions)
-----------------------------------------------------------
Problem Statement:
Given the head of a linked list and an integer k, return the kth node from the end of the linked list. If k is greater than the number of nodes in the list, return -1.
-----------------------------------------------------------
Approach:

-----------------------------------------------------------
Time Complexity: O(n)
Auxiliary Space: O(1)
*/

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};

class Solution {
  public:
    int getKthFromLast(Node* head, int k) {
        Node* curr = head;
        
        for(int i = 1; i < k; i++){
            if(curr -> next == nullptr){
                return -1;
            }
            curr = curr -> next;
        }
        
        Node *prevK = head;
        while(curr -> next != nullptr){
            prevK = prevK -> next;
            curr = curr -> next;
        }
        
        return prevK -> data;
    }
};

int main(){
    string input;
    cout << "Enter the elements(space separated):" << endl;
    getline(cin, input);

    stringstream ss(input);
    int num;
    Node* head = nullptr;
    Node* prev;
    while(ss >> num){
        if(head == nullptr){
            head = new Node(num);
            prev = head;
            continue;
        }
        Node *curr = new Node(num);
        prev -> next = curr;
        prev = curr;
    }

    cout << "Enter K:" << endl;
    cin >> num;

    cout << "Given LL:" << endl;
    Node* curr = head;
    while(curr != nullptr){
        cout << curr -> data << endl;
        curr = curr -> next;
    }

    Solution s;
    cout << num << "th last element: " << s.getKthFromLast(head, num) << endl;

    return 0;
}