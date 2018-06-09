/*
给定一个非负整数 n，计算各位数字都不同的数字 x 的个数，其中 0 ≤ x < 10n。
给定 n = 2，返回 91。（答案应该是除[11,22,33,44,55,66,77,88,99]外，0 ≤ x < 100 间的所有数字）
*/

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n >= 10){
            n = 10;
        }
        if(n == 0){
            return(1);
        }
        if(n == 1){
            return(10);
        }


        int i, result;
        result = 10;
        int temp = 9;
        i = 2;
        while(i <= n){
            temp *= (11-i);
            result += temp;
            i += 1;
        }
        return(result);
    }
};
