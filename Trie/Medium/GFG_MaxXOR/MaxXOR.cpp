/* 
Date: May 8, 2026
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/batch/gfg-160-problems/track/tries-gfg-160/problem/maximum-xor-of-two-numbers-in-an-array)
-----------------------------------------------------------
Problem Statement:
Given an array arr[] of non-negative integers of size n. Find the maximum possible XOR between two numbers present in the array.
-----------------------------------------------------------
Approach:
A Trie is used to store the binary representation of numbers bit by bit from the 31st bit to the 0th bit. While inserting a number, each bit is placed in either the zero or one branch. To maximize XOR for a number, the traversal always tries to move in the opposite bit direction because 1 XOR 0 = 1 gives a larger contribution to the result. For every bit, if the opposite bit exists in the Trie, that path is chosen and the corresponding power of 2 is added to the XOR value; otherwise the same bit path is followed. Each number is checked against previously inserted numbers to find the best possible XOR, and the maximum among all such values is returned.
-----------------------------------------------------------
Time Complexity: O(n log n)
Space Complexity: O(n)
*/

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

class Node {
      public:
      Node* zero;
      Node* one;
      Node () {
          zero = nullptr;
          one = nullptr;
      }
};

class Trie {
    public:
    Node* root;
    
    Trie () {
        root = new Node();
    }
    
    void insert(int n){
        Node* curr = root;
        
        for(int i = 31; i >= 0; i--){
            int bit = (n >> i) & 1;
            
            if(bit == 0){
                if(curr -> zero == NULL){
                    curr -> zero = new Node();
                }
                curr = curr -> zero;
            } else {
                if(curr -> one == NULL){
                    curr -> one = new Node();
                }
                curr = curr -> one;
            }
        }
    }
    
    int findXOR(int n){
        Node* curr = root;
        int res = 0;
        
        for(int i = 31; i >= 0; i--){
            int bit = (n >> i) & 1;
            
            if(bit == 0){
                if(curr -> one){
                    curr = curr -> one;
                    res += (1 << i);
                }
                else {
                    curr = curr -> zero;
                }
            } else {
                if(curr -> zero){
                    curr = curr -> zero;
                    res += (1 << i);
                }
                else {
                    curr = curr -> one;
                }
            }
        }
        
        return res;
    }
};

class Solution {
  public:
    int maxXor(vector<int> &arr) {
        int res = 0;
        Trie* t = new Trie();
        t -> insert(arr[0]);
        
        for(int i = 1; i < arr.size(); i++){
            res = max(t -> findXOR(arr[i]), res);
            t -> insert(arr[i]);
        }
        
        return res;
    }
};


int main(){
    string input;
    cout << "Enter the elements of array (space separated, enter when done):" << endl;
    getline(cin, input);

    stringstream ss(input);
    vector<int> nums;
    int num;

    while(ss >> num){
        nums.push_back(num);
    }

    cout << "\nArray Elements:" <<endl;
    for(int i = 0; i < nums.size(); i++){
        cout << nums[i] << "\t";
    }

    Solution s;
    cout << "\n\nMax XOR obtained between 2 numbers from array is " << s.maxXor(nums) << endl;

    return 0;

}
