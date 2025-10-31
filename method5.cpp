#include<iostream>
using namespace std;

int maxProfit(vector<int>& profits, int start, int end){
    if(start > end){
        return 0;
    }
    int mid = start + (end - start) / 2;
    int leftMaxProfit = maxProfit(profits, start, mid - 1);
    int rightMaxProfit = maxProfit(profits, mid + 1, end);
    int leftSum = 0;
    int maxLeftSum = 0;
    for(int i = mid - 1; i >= start; i--){
        leftSum += profits[i];
        maxLeftSum = max(maxLeftSum, leftSum);
    }
    int rightSum = 0;
    int maxRightSum = 0;
    for(int i = mid + 1; i <= end; i++){
        rightSum += profits[i];
        maxRightSum = max(maxRightSum, rightSum);
    }
    return max({leftMaxProfit, rightMaxProfit, profits[mid] + maxLeftSum + maxRightSum});
}
int maxProfit(vector<int>& prices) {
    vector<int> profits;
    for(int i = 1; i < prices.size(); i++){
        profits.push_back(prices[i]- prices[i - 1]);
    }
    int start = 0;
    int end = profits.size() - 1;
    return maxProfit(profits, start, end);
}