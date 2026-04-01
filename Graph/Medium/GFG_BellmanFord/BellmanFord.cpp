/* 
Date: April 1, 2026
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/batch/gfg-160-problems/track/graph-gfg-160/problem/distance-from-the-source-bellman-ford-algorithm)
-----------------------------------------------------------
Problem Statement:
Given an weighted graph with V vertices numbered from 0 to V-1 and E edges, represented by a 2d array edges[][], where edges[i] = [u, v, w] represents a direct edge from node u to v having w edge weight. You are also given a source vertex src.

Your task is to compute the shortest distances from the source to all other vertices. If a vertex is unreachable from the source, its distance should be marked as 108. Additionally, if the graph contains a negative weight cycle, return [-1] to indicate that shortest paths cannot be reliably computed.
-----------------------------------------------------------
Approach:
Start by assuming all distances are infinite except the source (0), then repeatedly relax all edges, meaning for each edge (u -> v) check if going through u gives a shorter path to v and update if it does. This relaxation is done V-1 times because the longest possible path without cycles has at most V-1 edges. One extra iteration is used to detect negative cycles—if any distance still updates, it means a cycle is reducing cost indefinitely, so no valid shortest path exists.
-----------------------------------------------------------
Time Complexity: O(V * E)
Space Complexity: O(V)
*/
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        vector<int> dist(V, 1e8);
        
        dist[src] = 0;
        
        for(int i = 0; i < V; i++){
            for(vector<int>& edge: edges){
                int u = edge[0], v = edge[1], w = edge[2];
                
                if(dist[u] != 1e8 && dist[u] + w < dist[v]){
                    if(i == V - 1) 
                        return {-1};
                        
                    dist[v] = dist[u] + w;
                }
            }
        }
        
        return dist;
    }
};

int main() {
    vector<vector<int>> graph;
    int V, src;

    cout << "Enter no.of nodes:" << endl;
    cin >> V;

    cin.ignore();

    cout << "Enter edge info of graph in start node, end node and distance order (separated by space, enter nothing after defining all edges):" << endl;
    while(true){
        string input;
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
    };

    cout << "Enter src node index:" << endl;
    cin >> src;

    cout << "Edge list:" << endl;
    for(int i = 0; i < graph.size(); i++){
        cout << i << ":\t";
        for(int n: graph[i]){
            cout << n << "\t";
        }
        cout << "\n";
    }
    cout << endl;

    Solution s;
    vector<int> result = s.bellmanFord(V, graph, src);

    cout << "Shortest Path from " << src << " to all other index:" << endl;
    for(int i = 0; i < V; i++){
        cout << i << ":\t" << result[i] << endl;
    }
    
    return 0;
}