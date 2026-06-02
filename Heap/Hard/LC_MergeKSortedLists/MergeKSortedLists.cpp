/*
Date: June 1, 2026
Platform: LeetCode (https://leetcode.com/problems/merge-k-sorted-lists/)
alt solution to [Heap/Medium/GFG_MergeSortedLinkedLists/MergeSortedLinkedList.cpp](Heap/Medium/GFG_MergeSortedLinkedLists/MergeSortedLinkedList.cpp)
-----------------------------------------------------------
Problem Statement:
You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.
-----------------------------------------------------------
Approach:
Use a min-heap (priority queue) to keep track of the smallest current node among the k linked lists.
1. Initialize the priority queue and push the head of each non-empty linked list into it.
2. Create a dummy node to serve as the head of the merged linked list and maintain a tail pointer.
3. While the priority queue is not empty:
    a. Pop the smallest node from the priority queue and add it to the merged linked list.
    b. If the popped node has a next node, push that next node into the priority queue.
-----------------------------------------------------------
Time Complexity: O(N log k), where N is the total number of nodes across all linked lists and k is the number of linked lists.
Space Complexity: O(k) for the priority queue, plus O(N) for the merged linked list (not counting the output).
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct Compare {
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val;
    }
};

class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        priority_queue<ListNode*, vector<ListNode*>, Compare> pq;
        
        for (auto &list : lists)
        {
            ListNode *head = list;
            if (head != nullptr) {
                pq.push(head);
            }
        }

        ListNode *dummy = new ListNode();
        ListNode *tail = dummy;

        while (!pq.empty())
        {
            ListNode *minNode = pq.top();
            pq.pop();
            tail->next = minNode;
            tail = tail->next;

            if (minNode->next != nullptr) {
                pq.push(minNode->next);
            }
        }

        return dummy->next;
    }
};

int main(){
    int k;
    cout << "Enter the number of linked lists (k): ";
    cin >> k;

    vector<ListNode *> lists(k);
    for (int i = 0; i < k; ++i)
    {
        int n;
        cout << "Enter the number of elements in list " << i + 1 << ": ";
        cin >> n;

        ListNode *head = nullptr, *tail = nullptr;
        cout << "Enter the elements of list " << i + 1 << " in sorted order: ";
        for (int j = 0; j < n; ++j)
        {
            int val;
            cin >> val;
            ListNode *newNode = new ListNode(val);
            if (!head)
            {
                head = tail = newNode;
            }
            else
            {
                tail->next = newNode;
                tail = tail->next;
            }
        }
        lists[i] = head;
    }

    Solution s;
    ListNode *mergedHead = s.mergeKLists(lists);

    cout << "\nMerged Linked List: ";
    while (mergedHead != nullptr)
    {
        cout << mergedHead->val << " ";
        mergedHead = mergedHead->next;
    }
    cout << endl;

    return 0;
}