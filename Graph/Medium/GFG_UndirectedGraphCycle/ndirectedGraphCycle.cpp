/* 
Date: April 3, 2026
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/batch/gfg-160-problems/track/graph-gfg-160/problem/detect-cycle-in-an-undirected-graph)
-----------------------------------------------------------
Problem Statement:
Given an undirected graph with V vertices and E edges, represented as a 2D vector edges[][], where each entry edges[i] = [u, v] denotes an edge between vertices u and v, determine whether the graph contains a cycle or not.

Note: The graph can have multiple component.
-----------------------------------------------------------
Approach:

-----------------------------------------------------------
Time Complexity: O(V + E)
Space Complexity: O(V)
*/
#include <iostream>
#include <unordered_set>
#include <string>
#include <sstream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
  public:
  
    bool bfs(int u, vector<vector<int>>& adj, vector<bool>& visited){
        queue<pair<int, int>> q;
        visited[u] = true;
        
        q.push({u, -1});
          
        while(!q.empty()){
            auto [node, parent] = q.front();
            q.pop();
            
            for(int i: adj[node]){
                if(!visited[i]){
                    visited[i] = true;
                    q.push({i, node});
                }
                else if (parent != i) {
                    return true;
                }
            }
        }
        
        return false;
    }
  
    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        
        for(vector<int> edge: edges){
            int u = edge[0], v = edge[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<bool> visited(V, false);
        
        for(int i = 0; i < V; i++){
            if(!visited[i]){
                if (bfs(i, adj, visited)){
                    return true;
                }
            }
        }
        
        return false;
    }
};

int main() {
    vector<vector<int>> mat;
    unordered_set<int> unique;

    cout << "Enter the edge list of undirected graph pair by pair in new lines, enter empty string when done:" << endl;
    while(true) {
        string s;
        getline(cin, s);

        if(s == ""){
            break;
        }

        stringstream ss(s);
        int num;
        vector<int> nums;
        while(ss >> num){
            nums.push_back(num);
            if(unique.find(num) == unique.end()){
                unique.insert(num);
            }
        }
        mat.push_back(nums);
    }

    int V = unique.size();

    cout << "Edge List:" << endl;
    for(int i = 0; i < mat.size(); i++){
        for(int n: mat[i]){
            cout << n << "\t";
        }
        cout << "\n";
    }
    cout << endl;

    Solution s;

    if (s.isCycle(V, mat)){
        cout << "A cycle exist in given graph." << endl;
    } else {
        cout << "There is no cycle in given graph." << endl;
    }
    
    return 0;
}