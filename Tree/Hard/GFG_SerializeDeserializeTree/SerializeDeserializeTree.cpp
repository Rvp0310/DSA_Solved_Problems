/* 
Date: January 3, 2026
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/batch/gfg-160-problems/track/tree-gfg-160/problem/serialize-and-deserialize-a-binary-tree)
-----------------------------------------------------------
Problem Statement: 
You are given the root of a binary tree. You have to perform Serialization and Deserialization. Serialization is to store a tree in an array so that it can be later restored and deserialization is reading tree back from the array. Complete the functions:

serialize() : stores the tree into an array and returns the array.
deSerialize() : deserializes the array to the tree and returns the root of the tree.
Note: Multiple nodes can have the same data and the node values are always positive integers. Your code will be correct if the tree returned by deSerialize(serialize(input_tree)) is same as the input tree. Driver code will print the level order traversal of the tree returned by deSerialize(serialize(input_tree)).----------------------
Approach:
The approach uses level-order traversal (BFS) to serialize the tree by storing each node’s value in an array and using a sentinel like -1 for null children, ensuring the exact structure is captured. For deserialization, the array is read sequentially to rebuild the tree: the first element becomes the root, and a queue tracks nodes whose children are yet to be assigned, attaching left and right children according to the next values in the array while skipping -1s, continuing until the array is fully processed. This BFS-based method preserves both node values and tree structure. The time complexity is O(n) since each node is visited once, and space complexity is O(n) due to the queue and the resulting array.
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
    vector<int> serialize(Node *root) {
        queue<Node*> q;
        vector<int> res;
        
        q.push(root);
        
        while(!q.empty()){
            Node *curr = q.front();
            q.pop();
            
            if(curr == nullptr){
                res.push_back(-1);
                continue;
            }
            
            res.push_back(curr -> data);
            q.push(curr -> left);
            q.push(curr -> right);
        }
        
        return res;
    }

    Node *deSerialize(vector<int> &arr) {
        if (arr[0] == -1){
            return nullptr;
        }
        
        Node *root = new Node(arr[0]);
        queue<Node*> q;
        q.push(root);
        
        int i = 1;
        while(!q.empty()){
            Node *curr = q.front();
            q.pop();
            
            if(i < arr.size() && arr[i] != -1){
                Node *left = new Node(arr[i]);
                curr -> left = left;
                q.push(left);
            }
            i++;
            
            if(i < arr.size() && arr[i] != -1){
                Node *right = new Node(arr[i]);
                curr -> right = right;
                q.push(right);
            }
            i++;
        }
        
        return root;
    }

    int getHeight(Node *root, int h)
    {
        if (root == nullptr)
            return h - 1;
        return max(getHeight(root->left, h + 1), getHeight(root->right, h + 1));
    }

    void levelOrder(Node *root)
    {
        queue<pair<Node *, int>> q;
        q.push({root, 0});

        int lastLevel = 0;

        // function to get the height of tree
        int height = getHeight(root, 0);

        // printing the level order of tree
        while (!q.empty())
        {
            auto top = q.front();
            q.pop();
            Node *node = top.first;
            int lvl = top.second;

            if (lvl > lastLevel)
            {
                cout << "\n";
                lastLevel = lvl;
            }

            // all levels are printed
            if (lvl > height)
                break;

            if (node->data != -1)
                cout << node->data << " ";

            // printing null node
            else
                cout << "N ";

            // null node has no children
            if (node->data == -1)
                continue;

            if (node->left == nullptr)
                q.push({new Node(-1), lvl + 1});
            else
                q.push({node->left, lvl + 1});

            if (node->right == nullptr)
                q.push({new Node(-1), lvl + 1});
            else
                q.push({node->right, lvl + 1});
        }
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
    vector<int> result = obj.serialize(root);
    
    cout << "Serialize Output:" << endl;
    for (int el: result){
        cout << el << "\t";
    }

    Node *newRoot = obj.deSerialize(result);
    cout << "\n\nDeserialize Output:" << endl;
    obj.levelOrder(newRoot);

    return 0;
}
