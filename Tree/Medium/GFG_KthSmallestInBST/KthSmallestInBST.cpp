/* 
Date: January 2, 2026
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/batch/gfg-160-problems/track/tree-gfg-160/problem/find-k-th-smallest-element-in-bst)
-----------------------------------------------------------
Problem Statement: 
Given the root of a BST and an integer k, the task is to find the kth smallest element in the BST. If there is no kth smallest element present then return -1.
-----------------------------------------------------------
Approach:
The solution uses Morris Inorder Traversal to find the k-th smallest element in a Binary Search Tree without using extra space. Since an inorder traversal of a BST visits nodes in sorted order, the algorithm traverses the tree while counting visited nodes. If a node has no left child, it is visited directly and the count is incremented. If a left child exists, the algorithm finds the inorder predecessor and temporarily links it to the current node to return after completing the left subtree. Each time a node is visited, the count is checked against k, and when they match, the node’s value is returned. Temporary links are removed to restore the original tree structure. If traversal finishes without reaching the k-th node, -1 is returned.
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
    int kthSmallest(Node *root, int k) {
        Node *curr = root;
        int count = 0;
        
        while(curr != NULL){
            if (curr -> left == NULL) {
                count++;
                if (count == k) {
                    return curr -> data;
                }
                
                curr = curr -> right;
            } else {
                Node *prev = curr -> left;
                while(prev -> right != NULL && prev -> right != curr){
                    prev = prev -> right;
                }
                
                if (prev -> right == NULL) {
                    prev -> right = curr;
                    curr = curr -> left;
                } else {
                    count++;
                    if (count == k) {
                        return curr -> data;
                    }
                    prev -> right = NULL;
                    curr = curr -> right;
                }
            }
        }
        
        return -1;
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

    int k = 3;

    Solution obj;
    cout << "The " << k << "th smallest node in given tree: " << obj.kthSmallest(root, k) << endl;

    return 0;
}
