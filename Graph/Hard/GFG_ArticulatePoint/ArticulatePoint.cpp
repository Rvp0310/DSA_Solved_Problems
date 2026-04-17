/* 
Date: April 17, 2026
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/batch/gfg-160-problems/track/graph-gfg-160/problem/articulation-point2616)
-----------------------------------------------------------
Problem Statement:
You are given an undirected graph with V vertices and E edges. The graph is represented as a 2D array edges[][], where each element edges[i] = [u, v] indicates an undirected edge between vertices u and v.
Your task is to return all the articulation points (or cut vertices) in the graph.
An articulation point is a vertex whose removal, along with all its connected edges, increases the number of connected components in the graph.

Note: The graph may be disconnected, i.e., it may consist of more than one connected component.
If no such point exists, return {-1}.
-----------------------------------------------------------
Approach:
Use DFS to track two things for every node: when it was first visited (disc) and the earliest node it can reach (low). While traversing, for every neighbor, if it is not visited, treat it as a tree edge, go deeper, and after returning update `low[u] = min(low[u], low[v])` because the child might connect back to an ancestor. If the neighbor is already visited and it is not the parent, it is a back edge, so update `low[u] = min(low[u], disc[v])` since it directly connects to an earlier node. A node becomes an articulation point if removing it breaks this connection, meaning for some child 'v', `low[v] >= disc[u]` (child cannot reach above parent). The root node is handled separately: it is an articulation point only if it has more than one child in DFS. Run this for all components and collect all such nodes.
-----------------------------------------------------------
Time Complexity: O(V + E)
Space Complexity: O(V)
*/
#include <iostream>
#include <unordered_set>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <array>

using namespace std;

class Solution {
  public:
  
    void findPoints(int start, vector<vector<int>>& adj, vector<int>& dist, vector<int>& low, vector<int>& parent, vector<int>& childrens, vector<bool>& visited, vector<bool>& AP){
        int n = adj.size();
        
        vector<array<int, 3>> stack(n * 2);
        
        int top = 0, time = 0;
        
        stack[top++] = {start, 0, 0};
        
        while(top > 0){
            int u = stack[top-1][0], idx = stack[top-1][1], state = stack[top-1][2];
            top--;
            
            if(state == 0){
                if(!visited[u]){
                    visited[u] = true;
                    dist[u] = low[u] = ++time;
                }
                
                if(idx < (int)adj[u].size()){
                    int v = adj[u][idx];
                    
                    stack[top++] = {u, idx + 1, 0};
                    
                    if(!visited[v]){
                        parent[v] = u;
                        childrens[u]++;
                        stack[top++] = {v, 0, 0};
                    }
                    else if (v != parent[u]){
                        low[u] = min(low[u], dist[v]);
                    } 
                } else {
                    stack[top++] = {u, 0, 1};
                }
            }
            else {
                if(top > 0){
                    int p = stack[top - 1][0];
                    low[p] = min(low[p], low[u]);
                    if(parent[p] != -1 && dist[p] <= low[u]){
                        AP[p] = true;
                    }
                } else if (childrens[start] > 1){
                    AP[start] = true;
                }
            }
        }
    }
    vector<int> articulationPoints(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        
        for(vector<int> pair: edges){
            adj[pair[0]].push_back(pair[1]);
            adj[pair[1]].push_back(pair[0]);
        }
        
        vector<int> low(V, 0), dist(V, 0), parent(V, -1), childrens(V, 0);
        vector<bool> visited(V, false), AP(V, false);
        
        for(int i = 0; i < V; i++){
            if(!visited[i]){
                findPoints(i, adj, dist, low, parent, childrens, visited, AP);
            }
        }
        
        vector<int> res;
        for(int i = 0; i < V; i++){
            if(AP[i]){
                res.push_back(i);
            }
        }
        
        return (res.empty()? vector<int> {-1} : res);
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

    vector<int> r = s.articulationPoints(V, mat);
    
    if(r[0] == -1){
        cout << "No articulate point in given graph" << endl;
    } else {
        cout << "Articulate Points: ";
        for(int ap: r){
            cout << ap << ", ";
        }

        cout << endl;
    }
    return 0;
}