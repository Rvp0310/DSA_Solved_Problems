/* 
Date: January 1, 2026
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/batch/gfg-160-problems/track/tree-gfg-160/problem/k-sum-paths)
-----------------------------------------------------------
Problem Statement: 
Given the root of a binary tree and an integer k, determine the number of downward-only paths where the sum of the node values in the path equals k.

Note: A path can start and end at any node within the tree but must always move downward (from parent to child)
-----------------------------------------------------------
Approach:
The idea is to use a depth-first traversal while keeping track of the cumulative sum from the root to the current node. At each node, the current node’s value is added to a running sum (currSum). If this running sum itself equals k, it forms a valid downward path and is counted.

To efficiently count paths that end at the current node but start somewhere higher up, a hash map is used to store how many times each prefix sum has occurred so far. If (currSum - k) exists in the map, it means there are paths ending at the current node whose sum is exactly k, and their count is added to the result.

Before moving deeper into the tree, the current sum is recorded in the map. The same process is applied recursively to the left and right subtrees. After returning from recursion, the current sum is removed from the map to ensure paths are counted only within the current traversal path. This backtracking step is crucial to avoid mixing paths from different branches.
-----------------------------------------------------------
Time Complexity: O(n)
Space Complexity: O(n)
*/

#include <iostream>
#include <unordered_map>

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
    int countAllPathsUtils(Node *root, int k, int currSum, unordered_map<int, int>& prefSums) {
        if (root == NULL) {
            return 0;
        }
        
        currSum += (root -> data);
        
        int count = 0;
        
        if (currSum == k) {
            count++;
        }
        
        count += prefSums[currSum - k];
        
        prefSums[currSum]++;
        
        count += countAllPathsUtils(root -> left, k, currSum, prefSums);
        count += countAllPathsUtils(root -> right, k, currSum, prefSums);
        
        prefSums[currSum]--;
        
        return count;
    }

    int countAllPaths(Node *root, int k) {
        unordered_map<int, int> prefSums;
        return countAllPathsUtils(root, k, 0, prefSums);
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

    int k = 9;

    Solution obj;
    cout << "The count of paths with sum " << k << " from the tree: " << obj.countAllPaths(root, k) << endl;

    return 0;
}
