/* 
Date: December 31, 2025
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/batch/gfg-160-problems/track/tree-gfg-160/problem/boundary-traversal-of-binary-tree)
-----------------------------------------------------------
Problem Statement: 
Given a root of a Binary Tree, return its boundary traversal in the following order:

Left Boundary: Nodes from the root to the leftmost non-leaf node, preferring the left child over the right and excluding leaves.

Leaf Nodes: All leaf nodes from left to right, covering every leaf in the tree.

Reverse Right Boundary: Nodes from the root to the rightmost non-leaf node, preferring the right child over the left, excluding leaves, and added in reverse order.

Note: The root is included once, leaves are added separately to avoid repetition, and the right boundary follows traversal preference not the path from the rightmost leaf.
-----------------------------------------------------------
Approach:
The boundary traversal is built by collecting nodes in three distinct phases while avoiding duplicates. First, the root is added if it is not a leaf. Next, the left boundary is traversed iteratively starting from the root’s left child, always preferring the left child over the right and stopping before leaf nodes. After that, all leaf nodes are added using a recursive traversal from left to right to ensure every leaf is included exactly once. Finally, the right boundary is traversed starting from the root’s right child, preferring the right child over the left, excluding leaves, and storing these nodes temporarily so they can be added to the result in reverse order. Combining these steps produces the boundary traversal in the required order.
-----------------------------------------------------------
Time Complexity: O(n)
Space Complexity: O(h)
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
    bool isLeaf(Node *root){
        return (root -> left == NULL) && (root -> right == NULL);
    }
    
    void leftTraversal(Node* root, vector<int>& res){
        if (root == NULL){
            return;
        }
        
        Node *curr = root;
        
        while(!isLeaf(curr)){
            res.push_back(curr -> data);
            
            if(curr -> left){
                curr = curr -> left;
            } else {
                curr = curr -> right;
            }
        }
    }
    
    void rightTraversal(Node* root, vector<int>& res){
        if (root == NULL){
            return;
        }
        
        Node *curr = root;
        vector<int> temp;
        
        while(!isLeaf(curr)){
            temp.push_back(curr -> data);
            
            if(curr -> right){
                curr = curr -> right;
            } else {
                curr = curr -> left;
            }
        }
        
        for(int i = temp.size() - 1; i >= 0; i--){
            res.push_back(temp[i]);
        }
    }
    
    void leafTraversal(Node* root, vector<int>& res){
        if(!root){
            return;
        }
        
        if(isLeaf(root)){
            res.push_back(root -> data);
        } else {
            if(root -> left){
                leafTraversal(root -> left, res);
            }
            if(root -> right){
                leafTraversal(root -> right, res);
            }
        }
    }
  
    vector<int> boundaryTraversal(Node *root) {
        if(!root)
            return {-1};
        
        vector<int> res;
        
        if(!isLeaf(root))
            res.push_back(root -> data);
        
        leftTraversal(root -> left, res);
        
        leafTraversal(root, res);
        
        rightTraversal(root-> right, res);
        
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
    vector<int> res = obj.boundaryTraversal(root);
    cout << "Given Binary Tree Boundary:" << endl;
    for(int el: res){
        cout << el << endl;
    }    

    return 0;
}
