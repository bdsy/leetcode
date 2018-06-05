/*
给定一个整数数组，其中第 i 个元素代表了第 i 天的股票价格 。​

设计一个算法计算出最大利润。在满足以下约束条件下，你可以尽可能地完成更多的交易（多次买卖一支股票）:

你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
卖出股票后，你无法在第二天买入股票 (即冷冻期为 1 天)。
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> p(n+1,0);
        vector<int> b(n+1,0);
        vector<int> q(n+1,0);
        int i,j;
        
        b[0] = INT_MIN;
        for(i = 0; i < n; ++i){
            p[i+1] = max(p[i], b[i]+prices[i]); 
            b[i+1] = max(b[i], q[i]-prices[i]);
            q[i+1] = max(q[i], p[i]);
        }
        return(max(q[n],p[n]));
    }
};
