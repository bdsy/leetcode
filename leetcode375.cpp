/*
我们正在玩一个猜数游戏，游戏规则如下：
我从 1 到 n 之间选择一个数字，你来猜我选了哪个数字。
每次你猜错了，我都会告诉你，我选的数字比你的大了或者小了。
然而，当你猜了数字 x 并且猜错了的时候，你需要支付金额为 x 的现金。直到你猜到我选的数字，你才算赢得了这个游戏。
 */

class Solution {
public:
    int getMoneyAmount(int n) {
        if(n == 1){
            return(0);
        }
        vector<vector<int>> record(n+1,vector<int>(n+1,INT_MAX));
        int length, i, j;

        for(length = 1; length <= n; ++length){
            for(i = 1; i <= n-length+1; ++i){
                if(length != 1){
                    record[i][i+length-1] = min(record[i][i+length-1],i+record[i+1][i+length-1]);
                    record[i][i+length-1] = min(record[i][i+length-1],i+length-1+record[i][i+length-2]);
                    for(j = i+1; j < i+length-1; ++j){
                        record[i][i+length-1] = min(record[i][i+length-1], j+max(record[i][j-1],record[j+1][i+length-1]));
                    }
                }
                else{
                    record[i][i] = 0;
                }
            }
        }
        return(record[1][n]);
    }
};
