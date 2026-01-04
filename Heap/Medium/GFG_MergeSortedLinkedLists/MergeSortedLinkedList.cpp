/* 
Date: January 4, 2026
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/batch/gfg-160-problems/track/heap-gfg-160/problem/merge-k-sorted-linked-lists)
-----------------------------------------------------------
Problem Statement:
Given an array arr[] of n sorted linked lists of different sizes. Your task is to merge all these lists into a single sorted linked list and return the head of the merged list.
-----------------------------------------------------------
Approach:
The approach uses a min-heap to efficiently merge k sorted linked lists. Each node from all lists is pushed into the min-heap, which ensures that the smallest element is always at the top. After all nodes are in the heap, we pop them one by one to build a new merged sorted linked list.
-----------------------------------------------------------
Time Complexity: O(n log k)
Space Complexity: O(k)
*/

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <queue>

using namespace std;

class Node {
  public:
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};


class Solution {
  public:
    Node* mergeKLists(vector<Node*>& arr) {
        priority_queue<int, vector<int>, greater<int>> minH;
        
        for(Node* head: arr){
            while(head != NULL){
                minH.push(head -> data);
                head = head -> next;
            }
        }
        
        Node* head = new Node(minH.top());
        minH.pop();
        Node* curr = head;
        
        while(!minH.empty()){
            Node *newNode = new Node(minH.top());
            curr -> next = newNode;
            curr = newNode;
            minH.pop();
        }
        
        return head;
    }
};

int main() {
    int k;
    cout << "Enter number of linked lists:" << endl;
    cin >> k;
    cin.ignore();

    vector<Node*> lists(k);

    cout << "Enter elements for each linked list (space separated, one line per list):" << endl;
    for(int i = 0; i < k; i++){
        string line;
        getline(cin, line);
        stringstream ss(line);
        int val;
        Node *dummy = new Node(0);
        Node *curr = dummy;
        while(ss >> val){
            curr->next = new Node(val);
            curr = curr->next;
        }
        lists[i] = dummy->next;
        delete dummy;
    }

    Solution s;
    Node* mergedHead = s.mergeKLists(lists);

    cout << "Merged sorted linked list:" << endl;
    Node* curr = mergedHead;
    while(curr){
        cout << curr->data << "\t";
        curr = curr->next;
    }
    cout << endl;

    return 0;
}
