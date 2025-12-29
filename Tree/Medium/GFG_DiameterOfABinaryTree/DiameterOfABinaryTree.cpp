/* 
Date: December 29, 2025
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/batch/gfg-160-problems/track/tree-gfg-160/problem/level-order-traversal)
-----------------------------------------------------------
Problem Statement: 
Given the root of a binary tree, your task is to find the diameter of the binary tree.

The diameter (also called the width) of a binary tree is defined as the number of edges on the longest path between any two leaf nodes. Note that this path may or may not pass through the root of the tree.
-----------------------------------------------------------
Approach:
The diameter is computed using a single depth-first traversal of the tree. For each node, the heights of its left and right subtrees are calculated recursively. The sum of these two heights represents the number of edges on the longest path passing through that node. A global variable tracks the maximum such value encountered during traversal. While unwinding the recursion, each call returns the height of the current subtree, defined as one plus the maximum of its left and right subtree heights. This ensures that both height and diameter are determined in one pass through the tree.
-----------------------------------------------------------
Time Complexity: O(n)
Space Complexity: O(n)
*/

#include <iostream>

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
    int maxDiameter = 0;

    int diameterRec(Node* root){
        if (root == NULL){
            return 0;
        }
        
        int Lheight = diameterRec(root -> left);
        int Rheight = diameterRec(root -> right);
        
        if(Lheight + Rheight > maxDiameter){
            maxDiameter = Lheight + Rheight;
        }
        
        return 1 + max(Lheight, Rheight);
    }
    
    int diameter(Node* root) {
        maxDiameter = 0;
        diameterRec(root);
        return maxDiameter;
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
    cout << "Diameter of Binary tree: " << obj.diameter(root) << endl;    

    return 0;
}
