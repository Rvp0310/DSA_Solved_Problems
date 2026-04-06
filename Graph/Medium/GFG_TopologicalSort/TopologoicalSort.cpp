/* 
Date: April 6, 2026
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/batch/gfg-160-problems/track/graph-gfg-160/problem/topological-sort)
-----------------------------------------------------------
Problem Statement:
Given a Directed Acyclic Graph (DAG) of V (0 to V-1) vertices and E edges represented as a 2D list of edges[][], where each entry edges[i] = [u, v] denotes a directed edge u -> v. Return the topological sort for the given graph.

Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that for every directed edge u -> v, vertex u comes before v in the ordering.
Note: As there are multiple Topological orders possible, you may return any of them. If your returned Topological sort is correct then the output will be true else false.
-----------------------------------------------------------
Approach:
Build the adjacency list from the edges and compute indegree of every node (how many incoming edges it has). Push all nodes with indegree 0 into a queue since they have no dependency and can come first. Then repeatedly remove a node from the queue, add it to the result, and reduce the indegree of its neighbors. If any neighbor’s indegree becomes 0, push it into the queue. Continue this process until the queue is empty, and the order in which nodes are processed gives a valid topological sort.
-----------------------------------------------------------
Time Complexity: O(n * m)
Space Complexity: O(n * m)
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
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        for(int i = 0; i < edges.size(); i++){
            adj[edges[i][0]].push_back(edges[i][1]);
        }
        
        vector<int> indegree(V, 0);
        vector<int> list;
        queue<int> q;
        
        for(int i = 0; i < V; i++){
            for(int next: adj[i]){
                indegree[next]++;
            }
        }
        
        for(int i = 0; i < V; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        
        while(!q.empty()){
            int top = q.front();
            q.pop();
            list.push_back(top);
            
            for(int next: adj[top]){
                indegree[next]--;
                if(indegree[next] == 0){
                    q.push(next);
                }
            }
        }
        
        return list;
    }
};

int main() {
    vector<vector<int>> mat;
    unordered_set<int> unique;

    cout << "Enter the edge list of directed graph pair by pair in new lines, enter empty string when done:" << endl;
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

    vector<int> res = s.topoSort(V, mat);
    
    cout << "Topological Sort Order:" << endl;
    for(int node: res){
        cout << node << "\t";
    }

    return 0;
}