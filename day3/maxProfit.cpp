#include<bits/stdc++.h>
#include<vector>
using namespace std;

int maxProfit(vector<int> prices){
    int minPrice = INT_MAX;
    int maxProfit = 0;
    for(int i=0; i<prices.size(); i++){
        //we keep track of the minimum share price 
        if(minPrice > prices[i]){
            minPrice = prices[i];
        }
        // maximum profit will be when 
        // we buy minimum price share 
        // and sell at maximum price
        if(prices[i]-minPrice > maxProfit){
            maxProfit = prices[i]-minPrice;
        }
    }
}

// brute force
int maxPrice(vector<int> prices){
    int minprice = INT_MAX;
    int maxprofit = 0;
    for(int i=0; i<prices.size(); i++){
        for(int j=i+1; j<prices.size(); j++){
            if(prices[j]-prices[i] > maxprofit){
                maxprofit = prices[j] - prices[i];
            }
        }
    } 
    return maxprofit;
}

int main(){

}