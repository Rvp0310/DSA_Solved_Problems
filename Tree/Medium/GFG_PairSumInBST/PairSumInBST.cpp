/* 
Date: January 2, 2026
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/batch/gfg-160-problems/track/tree-gfg-160/problem/find-a-pair-with-given-target-in-bst
-----------------------------------------------------------
Problem Statement: 
Given a Binary Search Tree(BST) and a target. Check whether there's a pair of Nodes in the BST with value summing up to the target. 
-----------------------------------------------------------
Approach:
Traverse the BST using DFS while maintaining a hash set to store values already visited. For each node, compute the complement required to reach the target (target − node’s value) and check if it exists in the set. If it does, a valid pair is found and the search stops. Otherwise, insert the current node’s value into the set and continue recursively on the left and right subtrees. If traversal completes without finding such a pair, return false. This works efficiently because each node is processed once, and lookups in the hash set take constant time.
-----------------------------------------------------------
Time Complexity: O(n)
Space Complexity: O(n)
*/

#include <iostream>
#include <unordered_set>

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
    bool isTargetSum(Node *root, int target, unordered_set<int>& lookup) {
        if (root == NULL){
            return false;
        }
        
        if(lookup.find(target - (root -> data)) != lookup.end()){
            return true;
        }
        
        lookup.insert(root -> data);
        
        return isTargetSum(root -> left, target, lookup) || isTargetSum(root -> right, target, lookup);;
    }
    
    bool findTarget(Node *root, int target) {
        unordered_set<int> lookup;
        
        return isTargetSum(root, target, lookup);
    }
};

int main() {
    /*
        Tree used for testing:
                4
              /   \
             3     7
            /     / \
           1     5   9
    */

    Node* root = new Node(4);
    root->left = new Node(3);
    root->right = new Node(7);
    root->left->left = new Node(1);
    root->right->left = new Node(5);
    root->right->right = new Node(9);

    int k = 10;

    Solution obj;

    if (obj.findTarget(root, k)){
        cout << "The pair with sum " << k << " exists in given tree." << endl;
    } else {
        cout << "The pair with sum " << k << " does not exist in given tree." << endl;
    }

    return 0;
}
