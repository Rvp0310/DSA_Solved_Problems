/* 
Date: April 11, 2026
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/batch/gfg-160-problems/track/graph-gfg-160/problem/bridge-edge-in-graph)
-----------------------------------------------------------
Problem Statement:
Given an undirected graph with V vertices numbered from 0 to V-1 and E edges, represented by 2d array edges[][], where edges[i]=[u,v] represents the edge between the vertices u and v. Determine whether a specific edge between two vertices (c, d) is a bridge.

Note:

An edge is called a bridge if removing it increases the number of connected components of the graph.
if there’s only one path between c and d (which is the edge itself), then that edge is a bridge.
-----------------------------------------------------------
Approach:
Remove the given edge (c, d) from the graph while building the adjacency list, then perform a DFS starting from node c to see which nodes are still reachable. If node d is no longer reachable after removing that edge, it means that edge was the only connection between them, so it is a bridge; otherwise, if d is still reachable through some other path, the edge is not a bridge.
-----------------------------------------------------------
Time Complexity: O(V + E)
Space Complexity: O(V + E)
*/
#include <iostream>
#include <unordered_set>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class Solution {
  public:
  
    void dfs(vector<vector<int>>& adj, int start, vector<bool>& visited){
        visited[start] = true;
        for(int v: adj[start]){
            if(!visited[v]){
                dfs(adj, v, visited);
            }
        }
    }
    
    bool isBridge(int V, vector<vector<int>> &edges, int c, int d) {
        vector<vector<int>> adj(V);
        
        for(vector<int> edge: edges){
            if(!((edge[0] == c && edge[1] == d) || (edge[1] == c && edge[0] == d))){
                adj[edge[0]].push_back(edge[1]);
                adj[edge[1]].push_back(edge[0]);
            }
        }
        
        vector<bool> visited(V, false);
        
        dfs(adj, c, visited);
        
        return !visited[d];
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

    int idx, c, d;
    cout << "Enter the edge index to check:" << endl;
    cin >> idx;

    c = mat[idx][0];
    d = mat[idx][1];

    cout << endl;
    Solution s;

    if (s.isBridge(V, mat, c, d)){
        cout << "Given Edge is a Bridge." << endl;
    } else {
        cout << "Given Edge is not a Bridge." << endl;
    }
    
    return 0;
}