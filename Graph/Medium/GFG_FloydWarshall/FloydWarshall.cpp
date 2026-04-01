/* 
Date: April 1, 2026
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/batch/gfg-160-problems/track/graph-gfg-160/problem/implementing-floyd-warshall2042)
-----------------------------------------------------------
Problem Statement:
You are given a weighted directed graph, represented by an adjacency matrix, dist[][] of size n x n, where dist[i][j] represents the weight of the edge from node i to node j. If there is no direct edge, dist[i][j] is set to a large value (i.e., 108) to represent infinity.
The graph may contain negative edge weights, but it does not contain any negative weight cycles.

Your task is to find the shortest distance between every pair of nodes i and j in the graph.

Note: Modify the distances for every pair in place.
-----------------------------------------------------------
Approach:
Every node is treated as an intermediate point and the algorithm checks whether going from i -> k -> j is shorter than the current direct distance i -> j. This is done for all triples (i, j, k) by gradually allowing more nodes as intermediates. If a shorter path is found through k, the distance matrix is updated in place. By the end, every dist[i][j] holds the shortest possible path considering all nodes as potential bridges.
-----------------------------------------------------------
Time Complexity: O(V ^ 3)
Space Complexity: O(1)
*/
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
  public:
    void floydWarshall(vector<vector<int>> &dist) {
        int n = dist.size(), INF = 1e8;
        
        for(int k = 0; k < n; k++){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                   if(dist[i][k] != INF && dist[k][j] != INF){
                       dist[i][j] = min(dist[i][k] + dist[k][j], dist[i][j]);
                   }
                }
            }
        }

        cout << "Shortest Path Matrix:" << endl;
        for(int i = 0; i < dist.size(); i++){
            cout << i << ":\t";
            for(int n: dist[i]){
                cout << n << "\t";
            }
            cout << "\n";
        }
        cout << endl;
    }
};

int main() {
    int V, src;

    cout << "Enter no.of nodes:" << endl;
    cin >> V;

    cin.ignore();

    vector<vector<int>> graph(V, vector<int> (V));

    cout << "Enter adjacency matrix:" << endl;
    for (int i = 0; i < V; i++){
        for(int j = 0; j < V; j++){
            cin >> graph[i][j];
        }
    }

    cout << "Adjacency Matrix:" << endl;
    for(int i = 0; i < graph.size(); i++){
        cout << i << ":\t";
        for(int n: graph[i]){
            cout << n << "\t";
        }
        cout << "\n";
    }
    cout << endl;

    Solution s;
    s.floydWarshall(graph);
    
    return 0;
}