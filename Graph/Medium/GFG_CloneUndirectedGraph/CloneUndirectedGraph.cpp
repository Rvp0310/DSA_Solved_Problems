/*
Date: April 15, 2026
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/batch/gfg-160-problems/track/graph-gfg-160/problem/clone-graph)
-----------------------------------------------------------
Problem Statement:
Given a connected undirected graph represented by adjacency list, adjList[][] with n nodes, having a distinct label from 0 to n-1, where each adj[i] represents the list of vertices connected to vertex i.

Create a clone of the graph, where each node in the graph contains an integer val and an array (neighbors) of nodes, containing nodes that are adjacent to the current node.
-----------------------------------------------------------
Approach:
Start from the given node and create its copy, then use a map to keep track of already cloned nodes so the same node is not recreated multiple times. Perform a BFS traversal using a queue, and for each original node, go through its neighbors; if a neighbor is not yet cloned, create its copy, store it in the map, and push the original neighbor into the queue for further traversal. Then connect the cloned current node to the cloned neighbors using the map. This way, both structure and connections of the graph are recreated, and finally return the clone of the starting node.
-----------------------------------------------------------
Time Complexity: O(V + E)
Space Complexity: O(V + E)
*/
#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

// Definition for a Node
struct Node
{
    int val;
    vector<Node *> neighbors;
    Node()
    {
        val = 0;
        neighbors = vector<Node *>();
    }
    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node *>();
    }
    Node(int _val, vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};

// Clone the graph
class Solution
{
public:
    Node *cloneGraph(Node *node)
    {

        if (!node)
            return nullptr;

        map<Node *, Node *> mp;

        Node *clone = new Node(node->val);

        mp[node] = clone;

        queue<Node *> q;

        q.push(node);

        while (!q.empty())
        {
            Node *org = q.front();
            q.pop();

            for (auto neighbour : org->neighbors)
            {
                if (mp.find(neighbour) == mp.end())
                {
                    Node *copy = new Node(neighbour->val);
                    mp[neighbour] = copy;
                    q.push(neighbour);
                }

                mp[org]->neighbors.push_back(mp[neighbour]);
            }
        }

        return mp[node];
    }
};

// Build graph
Node *buildGraph()
{
    Node *node1 = new Node();
    node1->val = 0;
    Node *node2 = new Node();
    node2->val = 1;
    Node *node3 = new Node();
    node3->val = 2;
    Node *node4 = new Node();
    node4->val = 3;

    node1->neighbors = {node2, node3};
    node2->neighbors = {node1, node3};
    node3->neighbors = {node1, node2, node4};
    node4->neighbors = {node3};

    return node1;
}

// Compare two graphs for structural and value equality
bool compareGraphs(Node *node1, Node *node2,
                   map<Node *, Node *> &visited)
{
    if (!node1 || !node2)
        return node1 == node2;

    if (node1->val != node2->val || node1 == node2)
        return false;

    visited[node1] = node2;

    if (node1->neighbors.size() != node2->neighbors.size())
        return false;

    for (size_t i = 0; i < node1->neighbors.size(); ++i)
    {
        Node *n1 = node1->neighbors[i];
        Node *n2 = node2->neighbors[i];

        if (visited.count(n1))
        {
            if (visited[n1] != n2)
                return false;
        }
        else
        {
            if (!compareGraphs(n1, n2, visited))
                return false;
        }
    }

    return true;
}

// Driver Code
int main()
{
    Node *original = buildGraph();

    Solution s;
    Node *cloned = s.cloneGraph(original);
    map<Node *, Node *> visited;
    cout << (compareGraphs(original, cloned, visited) ? "true" : "false") << endl;
    return 0;
}