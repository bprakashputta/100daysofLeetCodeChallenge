#include<iostream>
using namespace std;

class Solution {
public:
    int arrangeCoins(int n) {
        int lvl = 0;
        int temp = n;
        int i = 1;
        while(temp>i){
            temp = temp - i;
            lvl++;
            i = i+1;
        }
        if(temp == i){
            lvl++;
        }
    return lvl;
    }
};