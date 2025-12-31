/* 
Date: December 31, 2025
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/batch/gfg-160-problems/track/tree-gfg-160/problem/maximum-path-sum-from-any-node)
-----------------------------------------------------------
Problem Statement: 
Given the root of a binary tree, your task is to find the maximum path sum. The path may start and end at any node in the tree.
-----------------------------------------------------------
Approach:

-----------------------------------------------------------
Time Complexity: O(n)
Space Complexity: O(n)
*/

#include <iostream>
#include <vector>

using namespace std;

class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
  public:
    
};

int main() {
    /*
        Tree used for testing:
                1
              /   \
             2     3
            / \     \
           4   5     6
    */

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    int k = 9;

    Solution obj;
    cout << "The count of paths with sum " << k << " from the tree: "<< endl;

    return 0;
}
