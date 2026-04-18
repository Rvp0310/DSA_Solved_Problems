/* 
Date: April 18, 2026
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/batch/gfg-160-problems/track/graph-gfg-160/problem/alien-dictionary)
-----------------------------------------------------------
Problem Statement:
A new alien language uses the English alphabet, but the order of letters is unknown. You are given a list of words[] from the alien language’s dictionary, where the words are claimed to be sorted lexicographically according to the language’s rules.

Your task is to determine the correct order of letters in this alien language based on the given words. If the order is valid, return a string containing the unique letters in lexicographically increasing order as per the new language's rules. If there are multiple valid orders, return any one of them.

However, if the given arrangement of words is inconsistent with any possible letter ordering, return an empty string ("").

A string a is lexicographically smaller than a string b if, at the first position where they differ, the character in a appears earlier in the alien language than the corresponding character in b. If all characters in the shorter word match the beginning of the longer word, the shorter word is considered smaller.

Note: Your implementation will be tested using a driver code. It will print true if your returned order correctly follows the alien language’s lexicographic rules; otherwise, it will print false.
-----------------------------------------------------------
Approach:
Treat this like a topological sort on characters. First, mark all characters that actually appear in the given words. Then, compare adjacent words to find the first different character — this tells the order (like u → v, meaning u comes before v). Build a graph using these relations and maintain an indegree array. If a longer word comes before its prefix (like "abc" before "ab"), return invalid. After building the graph, use BFS (Kahn’s algorithm): push all characters with indegree 0 into a queue, pop one by one, add to result, and reduce indegree of neighbors. If at the end some characters still have indegree > 0, it means a cycle exists, so return empty; otherwise return the constructed order.
-----------------------------------------------------------
Time Complexity: O(V + E)
Space Complexity: O(V + E)
*/
#include <iostream>
#include <queue>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
  public:
    string findOrder(vector<string> &words) {
        vector<vector<int>> graph(26);
        vector<int> indegree(26, 0);
        vector<bool> exists(26, false);
        
        for(string& word: words){
            for(char c: word){
                exists[c - 'a'] = true;
            }
        }
        
        for(int i = 0; i + 1 < words.size(); i++){
            string w1 = words[i], w2 = words[i + 1];
            
            int len = min(w1.length(), w2.length());
            
            int j = 0;
            
            while(j < len && w1[j] == w2[j]){
                j++;
            }
            
            if(j < len){
                int u = w1[j] - 'a';
                int v = w2[j] - 'a';
                
                graph[u].push_back(v);
                indegree[v]++;
            } else if (w2.length() < w1.length()){
                return "";
            }
        }
        
        queue<int> q;
        
        for(int i = 0; i < 26; i++){
            if(exists[i] && indegree[i] == 0){
                q.push(i);
            }
        }
        
        string r = "";
        while(!q.empty()){
            int t = q.front();
            q.pop();
            
            char c = (char)(t + 'a');
            r += c;
            for(int i: graph[t]){
                indegree[i]--;
                if(indegree[i] == 0){
                    q.push(i);
                }
            }
        }
        
        for(int i = 0; i < 26; i++){
            if(exists[i] && indegree[i] != 0){
                return "";
            }
        }
        
        return r;
    }
};

int main() {
    vector<string> words;

    cout << "Enter words (one per line, empty line to stop):" << endl;
    while (true) {
        string s;
        getline(cin, s);
        if (s == "") break;
        words.push_back(s);
    }

    Solution sol;
    string order = sol.findOrder(words);

    if(order == ""){
        cout << "Invalid ordering (cycle or wrong input)" << endl;
    } else {
        cout << "Alien Dictionary Order: " << order << endl;
    }

    return 0;
}