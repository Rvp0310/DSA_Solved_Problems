/* 
Date: April 10, 2026
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/batch/gfg-160-problems/track/graph-gfg-160/problem/detect-cycle-in-a-directed-graph)
-----------------------------------------------------------
Problem Statement:
Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, check whether it contains any cycle or not.
The graph is represented as a 2D vector edges[][], where each entry edges[i] = [u, v] denotes an edge from vertex u to v.
-----------------------------------------------------------
Approach:
Build the adjacency list and compute indegree of each node, then push all nodes with indegree 0 into a queue since they have no incoming edges. Perform a BFS-like process where each removed node is counted as visited and its neighbors’ indegree is reduced; if any neighbor’s indegree becomes 0, push it into the queue. In a valid DAG, all nodes will eventually be processed, but if a cycle exists, some nodes will never reach indegree 0 and remain unprocessed. So after the traversal, if the number of visited nodes is less than V, a cycle is present.
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

using namespace std;

class Solution {
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        vector<vector<int>> adj(V);
        
        for(vector<int> edge: edges){
            adj[edge[0]].push_back(edge[1]);
        }
        
        vector<int> indegree(V, 0);
        
        for(int i = 0; i < V; i++){
            for(int v: adj[i]){
                indegree[v]++;
            }
        }
        
        queue<int> q;
        
        for(int i = 0; i < V; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        
        int visited = 0;
        
        while(!q.empty()){
            int front = q.front();
            q.pop();
            visited++;
            for(int v: adj[front]){
                indegree[v]--;
                if(indegree[v] == 0){
                    q.push(v);
                }
            }
        }
        
        return (visited != V);
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

    if(s.isCyclic(V, mat)){
        cout << "Cycle present in given graph." << endl;
    } else {
        cout << "Cycle not present in given graph." << endl;
    }

    return 0;
}