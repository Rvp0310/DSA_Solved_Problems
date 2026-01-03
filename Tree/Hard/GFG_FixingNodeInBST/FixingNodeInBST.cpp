/* 
Date: January 3, 2026
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/batch/gfg-160-problems/track/tree-gfg-160/problem/fixed-two-nodes-of-a-bst)
-----------------------------------------------------------
Problem Statement: 
Given the root of a Binary search tree(BST), where exactly two nodes were swapped by mistake. Your task is to fix (or correct) the BST by swapping them back. Do not change the structure of the tree.
Note: It is guaranteed that the given input will form BST, except for 2 nodes that will be wrong. All changes must be reflected in the original Binary search tree(BST).----------------------
-----------------------------------------------------------
Approach:
The approach fixes the BST by performing an inorder traversal, which should produce a sorted sequence in a valid BST. While traversing, we keep track of the previous node and detect violations where the previous node’s value is greater than the current node’s value. The first violation identifies the first and middle nodes, and if a second violation occurs later, it identifies the last node. After the traversal, if two non-adjacent nodes were swapped, we swap the first and last node values; if the swapped nodes are adjacent in inorder, we swap the first and middle node values. This restores the BST without altering its structure. The time complexity is O(n) for traversing all nodes, and space complexity is O(1) as only a few pointers are used.
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
    void correctBSTUtil(Node* root, Node*& first, Node*& middle, Node*& prev, Node*& last){
        if (root == NULL){
            return;
        }
        
        correctBSTUtil(root -> left, first, middle, prev, last);
        
        if(prev && (prev -> data > root -> data)){
            if(!first){
                first = prev;
                middle = root;
            } else {
                last = root;
            }
        }
        
        prev = root;
        
        correctBSTUtil(root -> right, first, middle, prev, last);
        
    }
    
    void correctBST(Node* root) {
        Node *first = NULL, *middle = NULL, *last = NULL, *prev = NULL;
        
        correctBSTUtil(root, first, middle, prev, last);
        
        if(first && last) {
            swap(first -> data, last -> data);
        } else if (first && middle){
            swap(first -> data, middle -> data);
        }
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
                4
              /   \
             3     5
            /     / \
           1     7   9
    */

    Node* root = new Node(4);
    root->left = new Node(3);
    root->right = new Node(5);   // should be 7
    root->left->left = new Node(1);
    root->right->left = new Node(7);    // should be 5
    root->right->right = new Node(9);

    Solution s;
    s.correctBST(root);
    s.levelOrder(root);

    return 0;
}
