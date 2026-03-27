/* 
Date: March 27, 2026
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/batch/gfg-160-problems/track/graph-gfg-160/problem/bfs-traversal-of-graph)
-----------------------------------------------------------
Problem Statement:
Given a connected undirected graph containing V vertices, represented by a 2-d adjacency list adj[][], where each adj[i] represents the list of vertices connected to vertex i. Perform a Breadth First Search (BFS) traversal starting from vertex 0, visiting vertices from left to right according to the given adjacency list, and return a list containing the BFS traversal of the graph.

Note: Do traverse in the same order as they are in the given adjacency list.
-----------------------------------------------------------
Approach:
Traversal happens level by level starting from the source node, using a queue to process nodes in the order they are discovered. Mark the start node as visited, push it into the queue, then repeatedly pop a node, add it to the result, and push all its unvisited neighbors (marking them visited immediately to avoid duplicates). This ensures closest nodes are visited first before going deeper.
-----------------------------------------------------------
Time Complexity: O(V + E)
Space Complexity: O(V + E)
*/

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
  public:
  
    void bfsRec(vector<vector<int>> &adj, vector<bool>& visited, int& s, vector<int>& res){
        queue<int> q;
        visited[s] = true;
        q.push(s);
        
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            res.push_back(curr);
            
            for(int i: adj[curr]){
                if(!visited[i]){
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
    }
    
    vector<int> bfs(vector<vector<int>> &adj) {
        int n = adj.size();
        vector<bool> visited(n, false);
        vector<int> res;
        
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                bfsRec(adj, visited, i, res);
            }
        }
        return res;
    }
};

int main() {
    vector<vector<int>> graph;
    int idx = 0;
    while(true){
        string input;
        cout << "Enter the adjacent elements of " << idx << " (separated by space, enter nothing after defining all nodes):" << endl;
        getline(cin, input);
        if(input == ""){
            break;
        }

        stringstream ss(input);
        int num;
        vector<int> nums;
        while(ss >> num){
            nums.push_back(num);
        }

        graph.push_back(nums);
        idx++;
    };

    cout << "Adjacency list:" << endl;
    for(int i = 0; i < graph.size(); i++){
        cout << i << ":\t";
        for(int n: graph[i]){
            cout << n << "\t";
        }
        cout << "\n";
    }
    cout << endl;

    Solution s;
    vector<int> result = s.bfs(graph);

    cout << "BFS Traversal of Given Graph:" << endl;
    for(int i: result){
        cout << i << "\t";
    }
    
    return 0;
}