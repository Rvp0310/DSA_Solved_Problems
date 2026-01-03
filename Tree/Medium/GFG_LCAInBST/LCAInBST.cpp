/* 
Date: January 3, 2026
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/batch/gfg-160-problems/track/tree-gfg-160/problem/lowest-common-ancestor-in-a-bst)
-----------------------------------------------------------
Problem Statement: 
Given the root of a Binary Search Tree (with all values unique) and two nodes n1 and n2 (n1 != n2). You may assume that both nodes exist in the tree. Find the Lowest Common Ancestor (LCA) of the given two nodes in the BST.

Note: LCA between two nodes n1 and n2 is defined as the deepest node that has both n1 and n2 as descendants (where we allow a node to be a descendant of itself).----------------------
-----------------------------------------------------------
Approach:
The approach leverages the properties of a Binary Search Tree to efficiently find the Lowest Common Ancestor (LCA). Starting at the root, we compare the root’s value with the values of the two target nodes. If both target nodes are smaller than the root, the LCA must lie in the left subtree, so we move left; if both are larger, we move right. If the root’s value lies between the two node values (or matches one of them), then the current root is the LCA, as one node lies on either side or is the root itself. This iterative method ensures we traverse only the necessary path in the BST. The time complexity is O(n) in the worst case for a skewed tree and O(log n) on average for a balanced BST, and space complexity is O(1) since no extra structures are needed.
-----------------------------------------------------------
Time Complexity: O(n)
Space Complexity: O(1)
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

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class Solution {
  public:
    Node* LCA(Node* root, Node* n1, Node* n2) {
        while(root != NULL){
            if ((root -> data > n1 -> data) && (root -> data > n2 -> data)) {
                root = root -> left;
            } else if ((root -> data < n1 -> data) && (root -> data < n2 -> data)) {
                root = root -> right;
            } else {
                break;
            }
        }
        
        return root;
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

    Node *n1 = root -> left;
    Node *n2 = root -> right -> right;
    Solution obj;
    cout << "The LCA with n1 and n2 as " << n1 -> data << " and " << n2 -> data << " respectively is: " << obj.LCA(root, n1, n2) -> data << endl;

    return 0;
}
