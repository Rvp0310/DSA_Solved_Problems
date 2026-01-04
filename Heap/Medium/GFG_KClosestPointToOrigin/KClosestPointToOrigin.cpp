/* 
Date: January 4, 2026
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/batch/gfg-160-problems/track/heap-gfg-160/problem/find-median-in-a-stream-1587115620)
-----------------------------------------------------------
Problem Statement:
Given a data stream arr[] where integers are read sequentially, the task is to determine the median of the elements encountered so far after each new integer is read.

The median is defined as follows:

1. Odd number of elements: The median is the middle element when the current set of numbers is sorted.
2. Even number of elements: The median is the arithmetic mean (average) of the two middle elements when the current set of numbers is sorted.
-----------------------------------------------------------
Approach:
The approach uses a max-heap to efficiently track the k closest points to the origin. For each point, we compute its squared distance from the origin to avoid unnecessary square roots. If the heap size is less than k, we push the point. If the heap is full and the current point is closer than the farthest point in the heap, we pop the farthest point and push the current one. After processing all points, the heap contains the k closest points, which are then extracted into a result vector.
-----------------------------------------------------------
Time Complexity: O(n log k)
Space Complexity: O(k)
*/

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <queue>

using namespace std;

class Solution {
  public:
    static int sqDist (vector<int>& p) {
        return ((p[0] * p[0]) + (p[1] * p[1]));
    }
  
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, vector<int>>> maxH;
        
        for(int i = 0; i < points.size(); i++){
            int dist = sqDist(points[i]);
            if(maxH.size() < k){
                maxH.push({dist, points[i]});
            } else if(dist < maxH.top().first){
                maxH.pop();
                maxH.push({dist, points[i]});
            }
        }
        
        vector<vector<int>> res;
        while(!maxH.empty()){
            res.push_back(maxH.top().second);
            maxH.pop();
        }
        
        return res;
    }
};

int main() {
    string input;
    cout << "Enter points (x y) separated by space (both coordinates and points), one point after another:" << endl;
    getline(cin, input);

    stringstream ss(input);
    vector<vector<int>> points;
    int x, y;
    while(ss >> x >> y){
        points.push_back({x, y});
    }

    int k;
    cout << "Enter value of k:" << endl;
    cin >> k;

    cout << "Given points:" << endl;
    for(auto &p: points){
        cout << "(" << p[0] << ", " << p[1] << ")\t";
    }
    cout << endl;

    Solution s;
    vector<vector<int>> res = s.kClosest(points, k);

    cout << k << " closest points to origin:" << endl;
    for(auto &p: res){
        cout << "(" << p[0] << ", " << p[1] << ")\t";
    }
    cout << endl;

    return 0;
}
