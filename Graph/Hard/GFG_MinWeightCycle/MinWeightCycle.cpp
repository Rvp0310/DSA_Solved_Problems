/* 
Date: April 28, 2026
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/batch/gfg-160-problems/track/graph-gfg-160/problem/minimum-weight-cycle)
-----------------------------------------------------------
Problem Statement:
Given an undirected, weighted graph with V vertices numbered from 0 to V-1 and E edges, represented by a 2d array edges[][], where edges[i] = [u, v, w] represents the edge between the nodes u and v having w edge weight.
Your task is to find the minimum weight cycle in this graph.
-----------------------------------------------------------
Approach:
For each edge (u, v, w), temporarily treat that edge as removed and use Dijkstra’s algorithm to find the shortest path from u to v. If such a path exists, then adding the removed edge back forms a cycle with total weight shortestPath + w. Repeat this for every edge and keep updating the minimum cycle weight. In the end, the smallest value obtained is the minimum weight cycle in the graph.
-----------------------------------------------------------
Time Complexity: O((V + E) log V)
Space Complexity: O(V)
*/

#include <iostream>
#include <unordered_set>
#include <string>
#include <sstream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

class Solution {
  public:
  
    int shortestPath(vector<vector<pair<int, int>>>& adj, int V, int src, int dest){
        vector<int> dist(V, INT_MAX);
        
        dist[src] = 0;
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        pq.push({0, src});
        
        while(!pq.empty()){
            auto t = pq.top();
            pq.pop();
            
            int d = t.first, u = t.second;
            
            if(d > dist[u]){
                continue;
            }
            
            for(pair<int, int> neighbour: adj[u]){
                int v = neighbour.first, w = neighbour.second;
                
                if ((u == src && v == dest) || (u == dest && v == src)){
                    continue;
                }
                
                if(dist[v] > dist[u] + w){
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }
        
        return dist[dest];
    }
    
    int findMinCycle(int V, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> adj(V);
        
        for(vector<int> edge: edges){
            adj[edge[0]].push_back({edge[1], edge[2]});
            adj[edge[1]].push_back({edge[0], edge[2]});
        }
        
        int minCycle = INT_MAX;
        
        for(vector<int> edge: edges){
            int u = edge[0], v = edge[1], w = edge[2];
            
            int dist = shortestPath(adj, V, u, v);
            
            if(dist != INT_MAX){
                minCycle = min(minCycle, dist + w);
            }
        }
        
        return minCycle;
    }
};

int main() {
    vector<vector<int>> mat;
    unordered_set<int> unique;

    cout << "Enter weighted edge list (u v w) in new lines, enter empty string when done:\n";

    while(true){
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
        }

        if(nums.size() == 3){
            mat.push_back(nums);
            unique.insert(nums[0]);
            unique.insert(nums[1]);
        }
    }

    int V = unique.size();

    cout << "\nEdge List:\n";
    for(int i = 0; i < mat.size(); i++){
        for(int n : mat[i]){
            cout << n << "\t";
        }
        cout << "\n";
    }

    Solution s;

    cout << "\nMin Weight Cycle: " << s.findMinCycle(V, mat) << endl;

    return 0;
}