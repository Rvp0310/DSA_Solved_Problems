/* 
Date: December 21, 2025
Platform: GeeksForGeeks (https://www.geeksforgeeks.org/batch/gfg-160-problems/track/linked-list-gfg-160/problem/lru-cache)
-----------------------------------------------------------
Problem Statement: 
Design a data structure that works like a LRU Cache. Here cap denotes the capacity of the cache and Q denotes the number of queries. Query can be of two types:

PUT x y: sets the value of the key x with value y
GET x: gets the value of key x if present else returns -1.
The LRUCache class has two methods get() and put() which are defined as follows.

get(key): returns the value of the key if it already exists in the cache otherwise returns -1.
put(key, value): if the key is already present, update its value. If not present, add the key-value pair to the cache. If the cache reaches its capacity it should remove the least recently used item before inserting the new item.
In the constructor of the class the capacity of the cache should be initialized.
-----------------------------------------------------------
Approach:

-----------------------------------------------------------
Time Complexity: O(n)
Space Complexity: O(1)
*/

# include <iostream>
# include <unordered_map>

using namespace std;

struct Node{
    int key;
    int value;
    Node* next;
    Node* prev;
    Node(int k, int v){
        key = k;
        value = v;
        next = nullptr;
        prev = nullptr;
    }
};

class LRUCache {
  public:
  int capacity;
  unordered_map<int, Node*> cacheMap;
  Node *head;
  Node *tail;
    LRUCache(int cap) {
        this -> capacity = cap;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head -> next = tail;
        tail -> prev = head;
    }

    int get(int key) {
        if(cacheMap.find(key) == cacheMap.end()){
            return -1;
        }
        
        Node *node = cacheMap[key];
        
        Node *prevnode = node -> prev;
        Node *nextnode = node -> next;
        prevnode -> next = nextnode;
        nextnode -> prev = prevnode;
        
        Node *secnode = head -> next;
        head -> next = node;
        node -> prev = head;
        secnode -> prev = node;
        node -> next = secnode;
        return node -> value;
    }

        
    void put(int key, int value) {
        Node *newNode;
        if (cacheMap.find(key) == cacheMap.end()){
            if(cacheMap.size() == capacity){
                Node *lru = tail -> prev;
                tail -> prev = lru -> prev;
                tail -> prev -> next = tail;
                
                cacheMap.erase(lru -> key);
                delete lru;
            }
            newNode = new Node(key, value);
        } else {
            newNode = cacheMap[key];
            newNode -> value = value;
            Node *prevNode = newNode -> prev;
            Node *nextNode = newNode -> next;
            prevNode -> next = nextNode;
            nextNode -> prev = prevNode;
        }
        Node *nextnode = head -> next;
        head -> next = newNode;
        newNode -> next = nextnode;
        newNode -> prev = head;
        nextnode -> prev = newNode;
        cacheMap[key] = newNode;
    }
};

int main() {
    int capacity;
    cout << "Enter the capacity of cache:" << endl;
    cin >> capacity;

    LRUCache cache(capacity);

    while (true) {
        string command;
        cout << "Enter the operation to perform(In capital letters, enter anything else to exit):" << endl;
        cin >> command;

        if (command == "PUT") {
            int key, value;
            cout << "Enter the key and value of new node or to update a node (space separated):" << endl;
            cin >> key >> value;
            cache.put(key, value);
        }
        else if (command == "GET") {
            int key;
            cout << "Enter the key to extract (-1 if key not present):" << endl;
            cin >> key;
            cout << cache.get(key) << endl;
        }
        else {
            cout << "Invalid command" << endl;
            break;
        }
    }

    return 0;
}