/*
Date: January 2, 2026
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/batch/gfg-160-problems/track/tree-gfg-160/problem/mirror-tree)
-----------------------------------------------------------
Problem Statement:
Given the root of a binary tree, convert the binary tree to its Mirror tree.

Note: Mirror of a Binary Tree T is another Binary Tree M(T) with left and right children of all non-leaf nodes interchanged.
-----------------------------------------------------------
Approach:
The binary tree is converted into its mirror by swapping the left and right child of every node. A level-order traversal (using a queue) is used to visit each node exactly once. Starting from the root, each node is dequeued, its left and right pointers are swapped, and then its non-null children are added back to the queue. This process continues until all nodes are processed, ensuring that the structure of the tree is mirrored at every level. The auxiliary level-order printing logic is only for verification and does not affect the mirroring operation itself.
-----------------------------------------------------------
Time Complexity: O(n)
Space Complexity: O(n)
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    // Constructor
    Node(int val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

class Solution
{
public:
    void mirror(Node *root)
    {
        if (root == NULL)
        {
            return;
        }

        queue<Node *> q;
        q.push(root);

        while (!q.empty())
        {
            Node *curr = q.front();
            q.pop();

            swap(curr->left, curr->right);

            if (curr->left)
            {
                q.push(curr->left);
            }

            if (curr->right)
            {
                q.push(curr->right);
            }
        }

        return;
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

    int main()
    {
        /*
            Tree used for testing:
                    1
                  /   \
                 2     3
                /
               4
        */

        Node *root = new Node(1);
        root->left = new Node(2);
        root->right = new Node(3);
        root->left->left = new Node(4);

        Solution obj;

        cout << "Mirrored Tree Level Order Traversal (-1 for null node):" << endl;
        obj.mirror(root);

        obj.levelOrder(root);

        return 0;
    }
