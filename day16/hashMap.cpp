#include<iostream>
#include<map>
using namespace std;

class MyHashMap {
public:
    map<int,int> m;   
    MyHashMap() {
        // m = new map<int,int>;
    }
    
    void put(int key, int value) {
        for(auto it=m.find(key); it!=m.end(); it++){
            it->second = value;
            return;
        }
        m.insert({key,value});
    }
    
    int get(int key) {
        for(auto it=m.find(key); it!=m.end(); it++){
            return it->second;
        }
    return -1;
    }
    
    void remove(int key) {
        m.erase(key);
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
