/* 
Date: January 29, 2025
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/batch/gfg-160-problems/track/searching-gfg-160/problem/allocate-minimum-number-of-pages0937)
-----------------------------------------------------------
Problem Statement: [originally a medium level problem]
Given an array arr[] of integers, where each element arr[i] represents the number of pages in the i-th book. You also have an integer k representing the number of students. The task is to allocate books to each student such that:
 - Each student receives atleast one book.
 - Each student is assigned a contiguous sequence of books.
 - No book is assigned to more than one student.
The objective is to minimize the maximum number of pages assigned to any student. In other words, out of all possible allocations, find the arrangement where the student who receives the most pages still has the smallest possible maximum.
Note: If it is not possible to allocate books to all students, return -1.
-----------------------------------------------------------
Approach:
Use binary search to minimize the maximum number of pages assigned to any student. Set the search space from the largest single book (lower bound) to the total sum of all pages (upper bound). For each midpoint, simulate allocation: iterate through the books, assigning pages to the current student until adding another book exceeds the current limit—then assign to a new student.  
Count how many students are needed. If the number of students is within the allowed limit (k or fewer), the allocation is feasible—try minimizing further.  
Otherwise, increase the page limit. The lowest feasible maximum is returned.
-----------------------------------------------------------
Time Complexity: O( n × log(sum(arr)))
Space Complexity: O(1)
*/

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
  public:
    int check(vector<int> &books, int maxPages){
        int currpages =0, student = 1;
        for(int pages : books){
            if(currpages + pages > maxPages){
                currpages = pages;
                student++;
            }
            else{
                currpages += pages;
            }
        }
        return student;
    }
    
    int findPages(vector<int> &arr, int k) {
        int n = arr.size();
        if(n < k){
            return -1;
        }
        else if(n == k){
            return *max_element(arr.begin(), arr.end());
        }
        int l = *max_element(arr.begin(), arr.end()), r = accumulate(arr.begin(), arr.end(), 0), maxmin = 0;
        while(l <= r){
            int m = (l + r) / 2, studentsReq = check(arr, m);
            if(studentsReq <= k){
                maxmin = m;
                r = m - 1;
            }
            else{
                l = m + 1;
            }
        }
        return maxmin;
    }
};

int main(){
    string input;
    cout << "Enter the no.of pages to be allocated (separated by space):" << endl;
    getline(cin, input);
    stringstream ss(input);
    int num;
    vector<int> nums;
    while (ss >> num){
        nums.push_back(num);
    }
    int c;
    cout << "Enter the no.of students:" << endl;
    cin >> c;
    Solution s;
    cout << "The minimum pages that could be allocated to a stusent in this case is " << s.findPages(nums, c) << ", which is the largest among all possible ways." << endl;
    return 0;
}