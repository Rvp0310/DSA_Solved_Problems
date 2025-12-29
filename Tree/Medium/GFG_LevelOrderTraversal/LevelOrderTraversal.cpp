/* 
Date: December 29, 2025
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/batch/gfg-160-problems/track/tree-gfg-160/problem/level-order-traversal)
-----------------------------------------------------------
Problem Statement: 
Given the root of a Binary Tree, your task is to return its Level Order Traversal.

Note: A level order traversal is a breadth-first search (BFS) of the tree. It visits nodes level by level, starting from the root, and processes all nodes from left to right within each level before moving to the next.
-----------------------------------------------------------
Approach:
Level order traversal is performed using Breadth-First Search (BFS) with a queue. If the root is null, an empty result is returned. Otherwise, the root node is pushed into a queue. While the queue is not empty, the number of nodes currently in the queue is taken as the size of the current level. All these nodes are processed one by one: their values are added to a temporary list for that level, and their left and right children (if they exist) are pushed into the queue. After finishing one level, the list is added to the result, and the process continues until all nodes are visited.
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
    vector<vector<int>> levelOrder(Node *root) {
        vector<vector<int>> res;
        
        if (root == nullptr) {
            return res;
        }
        
        queue<Node *> q;
        int currLevel = 0;
        
        q.push(root);
        
        while(!q.empty()){
            int len = q.size();
            res.push_back({});
            
            for(int i = 0; i < len; i++){
                Node *node = q.front();
                q.pop();
                
                res[currLevel].push_back(node -> data);
                
                if(node -> left != nullptr)
                    q.push(node -> left);
                if(node -> right != nullptr)
                    q.push(node -> right);
            }
            
            currLevel++;
        }
        
        return res;
    }

    // II aproach: Recursion
    
    // void levelOrderRec(Node *root, int level, vector<vector<int>>& res){
        
    //     if(root == nullptr){
    //         return;
    //     }
        
    //     if(res.size() <= level){
    //         res.push_back({});
    //     }
        
    //     res[level].push_back(root -> data);
        
        
    //     levelOrderRec(root -> left, level + 1, res);
    //     levelOrderRec(root -> right, level + 1, res);
    // }
  
    // vector<vector<int>> levelOrderUsingRec(Node *root) {
    //     vector<vector<int>> res;
        
    //     levelOrderRec(root, 0, res);
        
    //     return res;
    // }
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
    vector<vector<int>> result = obj.levelOrder(root);

    cout << "Level Order Traversal:\n";
    for (auto &level : result) {
        for (int val : level) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
