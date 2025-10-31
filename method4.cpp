#include<iostream>
using namespace std;

// dp iterative method
int maxProfit(vector<int>& prices) {
    vector<int> smallMaxProfits(2, 0);
    vector<vector<int>>maxProfits(prices.size(), smallMaxProfits);
    maxProfits[0][0] = 0;
    maxProfits[0][1] = 0;
    for(int i = 1; i < prices.size(); i++){
        maxProfits[i][0] = max(maxProfits[i - 1][0], maxProfits[i - 1][1]);
        maxProfits[i][1] = max(prices[i] - prices[i - 1], prices[i] - prices[i - 1] + maxProfits[i-1][1]);
    }
    return max(maxProfits[prices.size() - 1][1], maxProfits[prices.size() - 1][0]);
}