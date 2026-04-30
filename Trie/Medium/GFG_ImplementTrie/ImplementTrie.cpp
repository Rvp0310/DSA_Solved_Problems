/* 
Date: April 30, 2026
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/batch/gfg-160-problems/track/tries-gfg-160/problem/trie-insert-and-search0651)
-----------------------------------------------------------
Problem Statement:
Implement Trie class and complete insert(), search() and isPrefix() function for the following queries :

Type 1 : (1, word), calls insert(word) function and insert word in the Trie
Type 2 : (2, word), calls search(word) function and check whether word exists in Trie or not.
Type 3 : (3, word), calls isPrefix(word) function and check whether word exists as a prefix of any string in Trie or not.
-----------------------------------------------------------
Approach:
A Trie stores words character by character using child pointers for 26 lowercase letters. Starting from the root node, each character moves to its corresponding index (ch - 'a'). In insert(), if a child node does not exist, a new node is created, then traversal continues. After the last character, isLeaf is marked true to represent a complete word. In search(), characters are followed one by one; if any path is missing, the word does not exist. After traversal, the word is valid only if isLeaf is true. In isPrefix(), traversal is similar, but reaching the end of the prefix is enough, so no leaf check is required.
-----------------------------------------------------------
Time Complexity:
Insert  : O(n)
Search  : O(n)
Prefix  : O(n)

Space Complexity: O(total characters inserted)
*/

#include <iostream>
#include <string>
using namespace std;

class Trie {
  public:
  
    Trie* children[26];
    bool isLeaf;

    Trie() {
        isLeaf = false;
        for(int i = 0; i < 26; i++){
            children[i] = nullptr;
        }
    }

    void insert(string &word) {
        Trie* node = this;
        
        for(char ch: word){
            int idx = ch - 'a';
            
            if(node->children[idx] == nullptr){
                node->children[idx] = new Trie();
            }
            
            node = node->children[idx];
        }
        
        node->isLeaf = true;
    }

    bool search(string &word) {
        Trie* node = this;
        
        for(char ch: word){
            int idx = ch - 'a';
            
            if(node->children[idx] == nullptr){
                return false;
            }
            
            node = node->children[idx];
        }
        
        return node->isLeaf;
    }

    bool isPrefix(string &word) {
        Trie* node = this;
        
        for(char ch: word){
            int idx = ch - 'a';
            
            if(node->children[idx] == nullptr){
                return false;
            }
            
            node = node->children[idx];
        }
        
        return true;
    }
};

int main() {
    Trie t;
    
    while(true){
        int choice;
        string word;
        
        cout << "\n1. Insert Word\n";
        cout << "2. Search Word\n";
        cout << "3. Check Prefix\n";
        cout << "4. Exit\n";
        cout << "Enter choice:\n";
        cin >> choice;
        
        if(choice == 4){
            break;
        }
        
        cout << "Enter word:\n";
        cin >> word;
        
        if(choice == 1){
            t.insert(word);
            cout << "Word Inserted.\n";
        }
        else if(choice == 2){
            if(t.search(word)){
                cout << "Word Found.\n";
            } else {
                cout << "Word Not Found.\n";
            }
        }
        else if(choice == 3){
            if(t.isPrefix(word)){
                cout << "Prefix Exists.\n";
            } else {
                cout << "Prefix Does Not Exist.\n";
            }
        }
        else{
            cout << "Invalid Choice.\n";
        }
    }

    return 0;
}