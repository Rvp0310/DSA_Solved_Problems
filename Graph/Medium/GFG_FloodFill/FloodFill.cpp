/*
Date: April 14, 2026
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/batch/gfg-160-problems/track/graph-gfg-160/problem/flood-fill-algorithm1856)
-----------------------------------------------------------
Problem Statement:
You are given a 2D grid image[][], where each image[i][j] represents the color of a pixel in the image. Also provided a coordinate (sr, sc) representing the starting pixel (row and column) and a new color value newColor.

Your task is to perform a flood fill starting from the pixel (sr, sc), changing its color to newColor and the color of all the connected pixels that have the same original color. Two pixels are considered connected if they are adjacent horizontally or vertically (not diagonally) and have the same original color.
-----------------------------------------------------------
Approach:
Start from the given pixel (sr, sc) and note its original color, since only pixels with this same color should be changed. Use BFS (queue) to explore all connected pixels in 4 directions (up, down, left, right). For each pixel, check its neighbors and if they are within bounds and have the same original color, change them to the new color and push them into the queue. Continue this process until all reachable same-colored pixels are updated. If the original color is already equal to the new color, no changes are needed.
-----------------------------------------------------------
Time Complexity: O(n * m)
Space Complexity: O(n * m)
*/
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor) {
        int n = image.size(), m = image[0].size();
        int oldColor = image[sr][sc];
        image[sr][sc] = newColor;

        if (oldColor == newColor)
        {
            return image;
        }

        vector<pair<int, int>> dirs = {{0, -1}, {-1, 0}, {1, 0}, {0, 1}};

        queue<pair<int, int>> q;
        q.push({sr, sc});

        while (!q.empty())
        {
            pair<int, int> curr = q.front();
            q.pop();
            int x = curr.first, y = curr.second;

            for (auto dir : dirs)
            {
                int nx = (x + dir.first), ny = (y + dir.second);

                if (nx < n && nx >= 0 && ny < m && ny >= 0 && image[nx][ny] == oldColor)
                {
                    image[nx][ny] = newColor;
                    q.push({nx, ny});
                }
            }
        }

        return image;
    }
};

int main()
{
    vector<vector<int>> mat;

    cout << "Enter the image matrix:" << endl;
    int row = 0;
    while (true)
    {
        string s;
        getline(cin, s);

        if (s == "")
        {
            break;
        }

        stringstream ss(s);
        int c;
        vector<int> r;
        while (ss >> c)
        {
            r.push_back(c);
        }
        mat.push_back(r);

        row++;
    }

    cout << "Image Before Flood Fill:" << endl;
    for (int i = 0; i < mat.size(); i++)
    {
        for (int n : mat[i])
        {
            cout << n << "\t";
        }
        cout << "\n";
    }
    cout << endl;

    int x, y, col;

    cout << "Enter coordinates to start flood fill with:" << endl;
    cin >> x >> y;

    cout << "Enter new color:" << endl;
    cin >> col;

    Solution s;
    vector<vector<int>> res = s.floodFill(mat, x, y, col);

    cout << "Image After Floodfill: " << endl;
    for(vector<int> row: res){
        for(int p: row){
            cout << p << "\t";
        }
        cout << endl;
    }
    return 0;
}