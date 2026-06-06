/* 
Date: June 6, 2026
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/problems/finding-middle-element-in-a-linked-list/1?page=4&sortBy=submissions)
-----------------------------------------------------------
Problem Statement:
You are given the head of a linked list, You have to return the value of the middle node of the linked list.

If the number of nodes is odd, return the middle node value.
If the number of nodes is even, there are two middle nodes, so return the second middle node value.
-----------------------------------------------------------
Approach:
Use the slow and fast pointer technique. Move slow by one step and fast by two steps. When fast reaches the end, slow points to the middle node. Return its value.
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

    Node(int x){
        data = x;
        next = nullptr;
    }

};

class Solution {
  public:
    int getMiddle(Node* head) {
        Node* slow = head;
        Node* fast = head;
        
        while(fast && fast -> next){
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        
        return slow -> data;
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

    cout << "Given LL:" << endl;
    Node* curr = head;
    while(curr != nullptr){
        cout << curr -> data << endl;
        curr = curr -> next;
    }

    Solution s;
    cout << "Median: " << s.getMiddle(head) << endl;

    return 0;
}