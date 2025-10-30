#include<iostream>
#include<vector>
using namespace std;

// iterative method
int maxProfit(vector<int>& prices) {
    vector<int> profits;
    profits.push_back(0);
    int maxProfit = 0;
    for(int i = 1; i < prices.size(); i++){
        int profit = prices[i] - prices[i -1];
        if(profit + profits[i - 1] < 0){
            profits.push_back(0);
        }else{
            profits.push_back(profit + profits[i - 1]);
        }
        maxProfit = max(maxProfit, profits[i]);
    }
    return maxProfit;
}