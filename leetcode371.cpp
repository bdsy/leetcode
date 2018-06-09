/*
不使用运算符 + 和-，计算两整数a 、b之和。
若 a = 1 ，b = 2，返回 3。
*/

class Solution {
public:
    int getSum(int a, int b) {
        int sums = a;

        while(b != 0){
            sums = a^b;
            b = b&a;
            b = (b<<1);
            a = sums;
        }

        return(sums);
    }
};
