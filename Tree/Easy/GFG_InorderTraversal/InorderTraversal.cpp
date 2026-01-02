/* 
Date: January 2, 2026
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/batch/gfg-160-problems/track/tree-gfg-160/problem/inorder-traversal)
-----------------------------------------------------------
Problem Statement: 
Given a root of a Binary Tree, your task is to return its Inorder Traversal.

Note: An inorder traversal first visits the left child (including its entire subtree), then visits the node, and finally visits the right child (including its entire subtree).
-----------------------------------------------------------
Approach:
The inorder traversal is performed using Morris Traversal, which allows traversal without using recursion or an explicit stack. Starting from the root, the algorithm checks if the current node has a left child. If there is no left child, the node’s value is added to the result and traversal moves to the right child. If a left child exists, the algorithm finds the rightmost node in the left subtree (the inorder predecessor). If this predecessor’s right pointer is NULL, it is temporarily linked to the current node and traversal moves to the left child. If the right pointer already points to the current node, the temporary link is removed, the current node’s value is recorded, and traversal proceeds to the right child. This process ensures nodes are visited in left–root–right order while maintaining O(1) extra space.
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
    vector<int> inOrder(Node* root) {
        Node *curr = root;
        vector<int> res;
        
        while(curr != NULL){
            if(curr -> left == NULL){
                res.push_back(curr -> data);
                
                curr = curr -> right;
            } else {
                Node *prev = curr -> left;
                while(prev -> right != NULL && prev -> right != curr){
                    prev = prev -> right;
                }
                
                if(prev -> right == NULL){
                    prev -> right = curr;
                    
                    curr = curr -> left;
                } else {
                    prev -> right = NULL;
                    res.push_back(curr -> data);
                    curr = curr -> right;
                }
            }
        }
        
        return res;
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
    
    vector<int> r = obj.inOrder(root);

    cout << "Height of the binary Tree:" << endl;
    
    for (int el: r) {
        cout << el << endl;
    }

    return 0;
}
