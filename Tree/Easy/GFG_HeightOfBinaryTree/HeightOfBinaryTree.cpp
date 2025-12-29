/* 
Date: December 29, 2025
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/batch/gfg-160-problems/track/tree-gfg-160/problem/height-of-binary-tree)
-----------------------------------------------------------
Problem Statement: 
Given the root of a binary tree, your task is to find the maximum depth of the tree.

Note: The maximum depth or height of the tree is the number of edges in the tree from the root to the deepest node.
-----------------------------------------------------------
Approach:
The idea is to recursively compute the height of the left and right subtrees for each node. The height of the current node is then calculated by 1 + max(leftHeight, rightHeight). The recursion bottoms out when we reach to a null node, which contributes a height of 0.
-----------------------------------------------------------
Time Complexity: O(n)
Space Complexity: O(n)
*/

#include <iostream>
#include <vector>
#include <queue>

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
    int height(Node* root) {
        if (root == NULL) {
            return -1;
        }
        
        int Lheight = height(root -> left);
        int Rheight = height(root -> right);
        
        return max(Lheight, Rheight) + 1;
    }
};

int main() {
    /*
        Tree used for testing:
                1
              /   \
             2     3
            /
           4   
    */

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);

    Solution obj;
    
    cout << "Height of the binary Tree: " << obj.height(root);

    return 0;
}
