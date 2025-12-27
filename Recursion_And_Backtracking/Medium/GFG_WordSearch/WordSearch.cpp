/* 
Date: December 27, 2025
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/batch/gfg-160-problems/track/recursion-and-backtracking-gfg-160/problem/word-search)
-----------------------------------------------------------
Problem Statement:
You are given a matrix mat[][] of size n*m containing english alphabets and a string word. Check if the word exists on the mat[][] or not. The word can be constructed by using letters from adjacent cells, either horizontally or vertically. The same cell cannot be used more than once.
-----------------------------------------------------------
Approach:
The matrix is searched using backtracking with depth-first search. Each cell is treated as a possible starting point for the word. When the first character matches, a recursive search is started from that cell to match the remaining characters. From any position, movement is allowed only in four directions: up, down, left, and right. To avoid reusing the same cell, the current cell is temporarily marked as visited during recursion and restored after backtracking. If all characters of the word are matched in sequence, the search returns true. If no valid path forms the word after checking all possible starting positions, the function returns false.
-----------------------------------------------------------
Time Complexity: O(n * m * 3^k)
Space Complexity: O(k)
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
  public:
  
    bool findMatch(vector<vector<char>> &mat, string &word, int x, int y, int wIdx) {
        int n = mat.size();
        int m = mat[0].size();
        int wLen = word.length();
        
        if (wIdx == wLen) {
            return true;
        }
        
        if (x < 0 || y < 0 || x >= n || y >= m) {
            return false;
        }
        
        if (mat[x][y] == word[wIdx]) {
           char temp = mat[x][y];
           mat[x][y] = '#';
           bool res = findMatch(mat, word, x + 1 , y, wIdx + 1) || findMatch(mat, word, x - 1 , y, wIdx + 1) || findMatch(mat, word, x , y + 1, wIdx + 1) || findMatch(mat, word, x, y - 1, wIdx + 1);
           
           mat[x][y] = temp;
           return res;
        }
        
        return false;
    }
    
    bool isWordExist(vector<vector<char>> &mat, string &word) {
        int n = mat.size();
        int m = mat[0].size();
        int wLen = word.length();
        
        if (wLen > n * m) {
            return false;
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == word[0]) {
                    if (findMatch(mat, word, i , j, 0)) {
                        return true;    
                    }
                }
            } 
        }
        
        return false;
    }
};

int main() {

    cout << "Enter the dimension of word search matrix (no.of row and column space separated):" << endl;
    int n, m;
    cin >> n >> m;

    cout << "Enter the elements of matrix for word search:" << endl;
    vector<vector<char>> mat(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mat[i][j];
        }
    }

    string word;
    cout << "Enter the string to search:" << endl; 
    cin >> word;

    cout << "\nMatrix:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << mat[i][j] << "\t";
        }
        cout << endl;
    }

    Solution obj;
    cout << (obj.isWordExist(mat, word) ? "word exists in the matrix." : "word does not exist in the matrix.");

    return 0;
}
