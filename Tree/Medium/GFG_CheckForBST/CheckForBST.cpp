/* 
Date: January 3, 2026
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/batch/gfg-160-problems/track/tree-gfg-160/problem/check-for-bst)
-----------------------------------------------------------
Problem Statement: 
Given the root of a binary tree. Check whether it is a BST or not.

A BST is defined as follows:

The left subtree of a node contains only nodes with data less than the node's data.
The right subtree of a node contains only nodes with data greater than the node's data.
Both the left and right subtrees must also be binary search trees.
Note: We are considering that BSTs can not contain duplicate Nodes
----------------------
Approach:
The approach checks if a binary tree is a BST using Morris Inorder Traversal, which allows traversal without recursion or a stack, achieving O(1) extra space. It iterates through the tree in inorder, which for a BST must produce a strictly increasing sequence. A variable `prec` keeps track of the previously visited node’s value. For each node visited, it compares the node’s value with `prec`; if the current value is not greater than `prec`, the function immediately returns false. Otherwise, it updates `prec` and continues. The traversal handles left subtrees by temporarily linking the rightmost node of the left subtree back to the current node, removing the link after processing. This ensures all nodes are visited in proper inorder sequence. Time complexity is O(n) since each node is visited at most twice, and space complexity is O(1) because no extra stack or recursion is used.
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
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

class Solution {
  public:
    bool isBST(Node* root) {
        Node *curr = root;
        int prec = INT_MIN;
        
        while(curr != nullptr){
            if(curr -> left == nullptr){
                if(curr -> data <= prec){
                    return false;
                }
                prec = curr -> data;
                curr = curr -> right;
            } else {
                Node *prev = curr -> left;
                while(prev -> right != nullptr && prev -> right != curr){
                    prev = prev -> right;
                }
                
                if(prev -> right == nullptr){
                    prev -> right = curr;
                    curr = curr -> left;
                } else {
                    if(prec >= curr -> data){
                        return false;
                    }
                    
                    prev -> right = nullptr;
                    prec = curr -> data;
                    curr = curr -> right;
                }
            }
        }
        
        return true;
    }
};

int main() {
    /*
        Tree used for testing:
        (not a BST)
                1
              /   \
             2     3
            / \     \
           4   5     6

        (is a BST)
                4
              /   \
             3     7
            /     / \
           1     5   9
    */

    // is BST
    Node* BST_root = new Node(4);
    BST_root->left = new Node(3);
    BST_root->right = new Node(7);
    BST_root->left->left = new Node(1);
    BST_root->right->left = new Node(5);
    BST_root->right->right = new Node(9);

    // is not BST
    Node* NonBST_root = new Node(1);
    NonBST_root->left = new Node(2);
    NonBST_root->right = new Node(3);
    NonBST_root->left->left = new Node(4);
    NonBST_root->left->right = new Node(5);
    NonBST_root->right->right = new Node(6);

    Solution obj;
    if(obj.isBST(BST_root)){
        cout << "The tree is a BST." << endl;
    } else {
        cout << "The tree is not a BST." << endl;
    }

    return 0;
}
