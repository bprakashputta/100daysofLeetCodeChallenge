#include<iostream>
#include<map>
using namespace std;

class MyHashMap {
public:
    map<int,int>mp;
    MyHashMap() {
        map<int,int>mp;    
    }
    
    void put(int key, int value) {
        for(auto it=mp.find(key); it!=mp.end(); it++){
            it->second = value;
            return;
        }
        mp.insert({key, value});
    }
    
    int get(int key) {
       for(auto it=mp.find(key); it!=mp.end(); it++){
           return it->second;
       }
    return -1;
    }
    
    void remove(int key) {
        mp.erase(key);
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */