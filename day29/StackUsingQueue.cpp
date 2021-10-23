#include<iostream>
#include<queue>
using namespace std;

class StackUsingQueue
{
private:
    /* data */
    queue<int> q;
public:
    StackUsingQueue();

    void push(int x){
        q.push(x);
        for(int i=0; i<q.size()-1; i++){
            q.push(q.front());
            q.pop();
        }
    }    

    void pop(){
        q.pop();
    }
    
    void top(){
        q.front();
    }

    ~StackUsingQueue();
};