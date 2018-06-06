/*
给定不同面额的硬币 coins 和一个总金额 amount。编写一个函数来计算可以凑成总金额所需的最少的硬币个数。如果没有任何一种硬币组合能组成总金额，返回 -1。
*/

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<long long> d(amount+1,amount+1);
        d[0] = 0;
        long long i,j,m;
        sort(coins.begin(),coins.end());
        
        for(i = coins[0]; i <= amount; ++i){
            for(j = 0; j < n &&coins[j] <= i; ++j){
                d[i] = min(d[i], d[i-coins[j]]+1);
            }
            
        }
        
        return((d[amount] == amount+1) ? -1:d[amount]);
    }
};
