/* 
Date: December 31, 2025
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/batch/gfg-160-problems/track/tree-gfg-160/problem/maximum-path-sum-from-any-node)
-----------------------------------------------------------
Problem Statement: 
Given the root of a binary tree, your task is to find the maximum path sum. The path may start and end at any node in the tree.
-----------------------------------------------------------
Approach:
The solution uses a post-order traversal to compute the maximum path sum efficiently. For each node, the maximum contribution from its left and right subtrees is calculated, but negative contributions are ignored by clamping them to zero, since including a negative path would reduce the total sum. At every node, the algorithm considers the path that passes through that node as a potential answer by adding the node’s value with the best contributions from both children, and updates a global maximum if this sum is larger. The recursive function then returns the maximum sum of a path starting at the current node and extending upward to its parent, which is the node’s value plus the larger of the left or right contributions. By visiting each node once and maintaining the global maximum, the maximum path sum between any two nodes in the tree is obtained.
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
    int MaxSumRec(Node *root, int& res) {
        if(root == NULL){
            return 0;
        }
        
        int l = max(0, MaxSumRec(root -> left, res));
        int r = max(0, MaxSumRec(root -> right, res));
        
        res = max((root -> data) + l + r, res);
        
        return ((root -> data) + max(l, r));
    }
    
    int findMaxSum(Node *root) {
        int res = root -> data;
        
        MaxSumRec(root, res);
        
        return res;
    }
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

    Solution obj;
    cout << "The max sum from the tree: " << obj.findMaxSum(root);

    return 0;
}
