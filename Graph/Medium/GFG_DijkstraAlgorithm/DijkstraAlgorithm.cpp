/* 
Date: April 27, 2026
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/batch/gfg-160-problems/track/graph-gfg-160/problem/implementing-dijkstra-set-1-adjacency-matrix)
-----------------------------------------------------------
Problem Statement:
Given an undirected, weighted graph with V vertices numbered from 0 to V-1 and E edges, represented by 2d array edges[][], where edges[i]=[u, v, w] represents the edge between the nodes u and v having w edge weight.
You have to find the shortest distance of all the vertices from the source vertex src, and return an array of integers where the ith element denotes the shortest distance between ith node and source vertex src.

Note: The Graph is connected and doesn't contain any negative weight edge.
It is guaranteed that all the shortest distance will fit in a 32-bit integer.
-----------------------------------------------------------
Approach:
Create a distance array initialized with INT_MAX to represent infinity, and set the source vertex distance as 0. Use a min-priority queue storing {distance, node} so the node with the smallest current distance is processed first.
While the queue is not empty, remove the top element (d, u). If d > dist[u], skip it because a shorter path to u was already found earlier. Otherwise, check all neighbors (v, w) of u. If going through u gives a shorter path (dist[u] + w < dist[v]), update dist[v] and push the new pair into the queue.
-----------------------------------------------------------
Time Complexity: O(V + E)
Space Complexity: O(V + E)
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
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        vector<vector<pair<int, int>>> adj(V);

        for(vector<int> edge : edges){
            adj[edge[0]].push_back({edge[1], edge[2]});
            adj[edge[1]].push_back({edge[0], edge[2]});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(V, INT_MAX);

        dist[src] = 0;
        pq.push({0, src});

        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();

            int d = top.first;
            int u = top.second;

            if(d > dist[u]){
                continue;
            }

            for(auto neighbour : adj[u]){
                int v = neighbour.first;
                int w = neighbour.second;

                if(dist[v] > dist[u] + w){
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }

        return dist;
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

    int src;
    cout << "\nEnter source vertex:\n";
    cin >> src;

    Solution s;
    vector<int> ans = s.dijkstra(V, mat, src);

    cout << "\nShortest Distance from Source " << src << ":\n";

    for(int i = 0; i < ans.size(); i++){
        cout << "Node " << i << " -> ";

        if(ans[i] == INT_MAX){
            cout << "INF";
        } else {
            cout << ans[i];
        }

        cout << endl;
    }

    return 0;
}