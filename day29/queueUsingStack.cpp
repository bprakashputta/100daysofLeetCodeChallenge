#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

class MyQueue {
  
    public:
        stack<int> input, output;   
        void push(int x) {
            input.push(x);
        }

        void pop() {
            if(output.empty()==false){
                output.pop();
            }else{
                while(!input.empty()){
                    output.push(input.top());
                    input.pop();
                }
                output.pop();
            }
        }

        int front() {
            if(output.empty()==false){
                return output.top();
            }else{
                while(!input.empty()){
                    output.push(input.top());
                    input.pop();
                }
                return output.top();
            }
        }
};

int main() {
    MyQueue q1;
    int q, type, x;
    cin >> q;
    
    for(int i = 0; i < q; i++) {
        cin >> type;
        if(type == 1) {
            cin >> x;
            q1.push(x);
        }
        else if(type == 2) {
            q1.pop();
        }
        else cout << q1.front() << endl;
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
