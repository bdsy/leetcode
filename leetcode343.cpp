/*
给定一个正整数 n，将其拆分为至少两个正整数的和，并使这些整数的乘积最大化。 返回你可以获得的最大乘积。

例如，给定 n = 2，返回1（2 = 1 + 1）；给定 n = 10，返回36（10 = 3 + 3 + 4）。

注意：你可以假设 n 不小于2且不大于58。
*/

class Solution {
public:
    int integerBreak(int n) {
        int result = 1;
        if(n == 2){
            return(1);
        }
        if(n == 3){
            return(2);
        }


        while(n > 4){
            result *= 3;
            n -= 3;
        }
        result *= n;
        return(result);
    }
};
