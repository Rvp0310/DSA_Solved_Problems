/* 
Date: December 18, 2025
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/batch/gfg-160-problems/track/linked-list-gfg-160/problem/detect-loop-in-linked-list)
-----------------------------------------------------------
Problem Statement: 
You are given the head of a singly linked list. You have to determine whether the given linked list contains a loop or not. A loop exists in a linked list if the next pointer of the last node points to any other node in the list (including itself), rather than being null.

Note: Internally, pos(1 based index) is used to denote the position of the node that tail's next pointer is connected to. If pos = 0, it means the last node points to null. Note that pos is not passed as a parameter.
-----------------------------------------------------------
Approach: (Floyd’s Cycle Detection)
Two pointers are used to move through the list at different speeds. One pointer moves one step at a time, while the other moves two steps at a time. If the list has a loop, the faster pointer will eventually catch up to the slower one inside the loop. When both pointers meet, a loop is confirmed. If the faster pointer reaches the end of the list, no loop exists.
-----------------------------------------------------------
Time Complexity: O(n)
Space Complexity: O(1)
*/

# include <iostream>

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
    bool detectLoop(Node* head) {
        Node *slow = head, *fast = head;
        
        while(fast && slow && fast -> next){
            slow = slow -> next;
            fast = fast -> next -> next;
            if(slow == fast){
                return true;
            }
        }
        
        return false;
    }
};

int main(){
    Node *head = NULL;
    // Creating nodes
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);

    // next pointers
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n2;    // remove for no loop condition

    head = n1;

    Solution s;
    bool loop = s.detectLoop(head);

    if(loop){
        cout << "Loop Detected" << endl;
    } else {
        cout << "No Loop Present" << endl;
    }
    
    return 0;
}