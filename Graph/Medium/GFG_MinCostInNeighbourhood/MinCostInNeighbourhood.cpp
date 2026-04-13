/*
Date: April 13, 2026
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/batch/gfg-160-problems/track/graph-gfg-160/problem/minimum-cost-to-connect-all-houses-in-a-city)
-----------------------------------------------------------
Problem Statement:
Given a 2D array houses[][], consisting of n 2D coordinates {x, y} where each coordinate represents the location of each house, the task is to find the minimum cost to connect all the houses of the city.

The cost of connecting two houses is the Manhattan Distance between the two points (xi, yi) and (xj, yj) i.e., |xi – xj| + |yi – yj|, where |p| denotes the absolute value of p.
-----------------------------------------------------------
Approach:
Treat each house as a node and the cost between any two houses as the Manhattan distance, so the problem becomes finding a Minimum Spanning Tree (MST). Start from any house (here index 0) and use a min-heap to always pick the next closest unvisited house. Each time a house is picked, add its cost to the total and mark it visited, then push distances from this house to all remaining unvisited houses into the heap. This way, at every step the cheapest connection is chosen, gradually connecting all houses with minimum total cost.
-----------------------------------------------------------
Time Complexity: O(n^2 log n)
Space Complexity: O(n^2)
*/

#include <iostream>
#include <queue>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class Solution
{
public:
    int manhattan(vector<int> &a, vector<int> &b)
    {
        return abs(a[0] - b[0]) + abs(a[1] - b[1]);
    }

    int minCost(vector<vector<int>> &houses)
    {
        int n = houses.size();

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;

        int totalCost = 0;
        minHeap.push({totalCost, 0});

        vector<bool> visited(n, false);

        while (!minHeap.empty())
        {
            pair<int, int> house = minHeap.top();
            minHeap.pop();
            int cost = house.first;
            int u = house.second;

            if (visited[u])
                continue;

            visited[u] = true;
            totalCost += cost;

            for (int i = 0; i < n; i++)
            {
                if (!visited[i])
                {
                    int dist = manhattan(houses[u], houses[i]);
                    minHeap.push({dist, i});
                }
            }
        }

        return totalCost;
    }
};

int main()
{
    vector<vector<int>> mat;

    cout << "Enter the coordinates (x y) of houses, each in new line, enter empty string when done:" << endl;
    while (true)
    {
        string s;
        getline(cin, s);

        if (s == "")
        {
            break;
        }

        stringstream ss(s);
        int num;
        vector<int> nums;
        while (ss >> num)
        {
            nums.push_back(num);
        }
        mat.push_back(nums);
    }

    cout << "House: Coordinates" << endl;
    for (int i = 0; i < mat.size(); i++)
    {
        cout << i <<":\t";
        for (int n : mat[i])
        {
            cout << n << ", ";
        }
        cout << "\n";
    }

    cout << endl;
    Solution s;

    cout << "Minimum cost for given neighbourhood: " << s.minCost(mat) << endl;

    return 0;
}