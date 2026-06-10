/* 
Date: January 4, 2026
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/problems/k-closest-points-to-origin--172242/1)
-----------------------------------------------------------
Problem Statement:
Given an integer k and an array of points points[][], where each point is represented as points[i] = [xi, yi] on the X-Y plane. Return the k closest points to the origin (0, 0).

The distance between two points on the X-Y plane is the Euclidean distance, defined as:
distance = sqrt( (x2 - x1)2 + (y2 - y1)2 )

Note: You can return the k closest points in any order, the driver code will print them in sorted order.
Test Cases are generated such that there will be a unique ans.
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
