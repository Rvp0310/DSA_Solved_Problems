/* 
Date: March 27, 2026
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/batch/gfg-160-problems/track/graph-gfg-160/problem/depth-first-traversal-for-a-graph)
-----------------------------------------------------------
Problem Statement:
Given a connected undirected graph containing V vertices represented by a 2-d adjacency list adj[][], where each adj[i] represents the list of vertices connected to vertex i. Perform a Depth First Search (DFS) traversal starting from vertex 0, visiting vertices from left to right as per the given adjacency list, and return a list containing the DFS traversal of the graph.

Note: Do traverse in the same order as they are in the given adjacency list.
-----------------------------------------------------------
Approach:
Traversal goes as deep as possible along a path before backtracking, typically using recursion (or a stack). Start from a node, mark it visited, add it to the result, then recursively visit each unvisited neighbor in order. It keeps diving deeper until no unvisited neighbor is left, then backtracks to explore other paths.
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
  
    void dfsRec(vector<vector<int>>& adj, vector<bool>& visited, int s,vector<int>& res){
        visited[s] = true;
        res.push_back(s);
        
        for(int i : adj[s]){
            if(!visited[i]){
                dfsRec(adj, visited, i, res);
            }
        }
    }
    
    vector<int> dfs(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<bool> visited(n, false);
        vector<int> res;
        
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                dfsRec(adj, visited, i, res);
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
    vector<int> result = s.dfs(graph);

    cout << "BFS Traversal of Given Graph:" << endl;
    for(int i: result){
        cout << i << "\t";
    }
    
    return 0;
}