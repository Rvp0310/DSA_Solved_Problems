/* 
Date: December 31, 2025
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/batch/gfg-160-problems/track/tree-gfg-160/problem/construct-tree-1)
-----------------------------------------------------------
Problem Statement: 
Given two arrays representing the inorder and preorder traversals of a binary tree, your task is to construct the binary tree and return its root.

Note: The inorder and preorder traversals contain unique values, and every value present in the preorder traversal is also found in the inorder traversal.
-----------------------------------------------------------
Approach:
The tree is constructed using the fact that the first element of the preorder traversal is always the root of the current subtree. A hash map is created from the inorder traversal to quickly find the index of any value. Starting from the preorder array, each chosen root splits the inorder range into left and right subtrees based on its index. A recursive function builds the tree by advancing the preorder index, creating the root node, and then recursively constructing the left subtree from the left part of the inorder array and the right subtree from the right part. This continues until the inorder range becomes invalid, which marks the base case. By processing each node once and using the map for constant-time lookups, the binary tree is rebuilt efficiently.
-----------------------------------------------------------
Time Complexity: O(n)
Space Complexity: O(h)
*/

#include <iostream>
#include <vector>
#include <unordered_map>
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
  
    Node *buildTreeRec(unordered_map<int, int>& mp, vector<int>& preorder, int& preIn, int left, int right){
        if (left > right){
            return NULL;
        }  
        
        Node *root = new Node(preorder[preIn]);
        
        int index = mp[preorder[preIn]];
        preIn++;
        
        root -> left = buildTreeRec(mp, preorder, preIn, left, index - 1);
        root -> right = buildTreeRec(mp, preorder, preIn, index + 1, right);
        
        return root;
    }
    
    Node *buildTree(vector<int> &inorder, vector<int> &preorder) {
        unordered_map<int, int> mp;
        for(int i = 0; i < inorder.size(); i++){
            mp[inorder[i]] = i;
        }
        
        int preIndex = 0;
        Node *root = buildTreeRec(mp, preorder, preIndex, 0, inorder.size() - 1);
        
        return root;
    }

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
};

int main() {
    int n;
    cout << "Enter number of nodes:" << endl;
    cin >> n;

    vector<int> inorder(n), preorder(n);

    cout << "Enter inorder traversal:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> inorder[i];
    }

    cout << "Enter preorder traversal:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> preorder[i];
    }

    Solution sol;
    Node* root = sol.buildTree(inorder, preorder);

    // Level order print to verify tree
    cout << "Level order traversal of constructed tree:" << endl;
    vector<vector<int>> res = sol.levelOrder(root);

    for(vector<int> row: res){
        for(int el: row){
            cout << el << "\t";
        }
        cout << endl;
    }
    return 0;
}
