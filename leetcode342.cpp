/*
给定一个整数 (32位有符整数型)，请写出一个函数来检验它是否是4的幂。

示例:
当 num = 16 时 ，返回 true 。 当 num = 5时，返回 false。

问题进阶：你能不使用循环/递归来解决这个问题吗？
*/

class Solution {
public:
    bool isPowerOfFour(int num) {
        int i,j,n,state;

        if(num <= 0){
            return(false);
        }
        if(num == 1){
            return(true);
        }
        state = false;
        for(i = 0; i < 32; ++i){
            if((num >> i) & 1 == 1){
                if(i % 2 == 1){
                    return(false);
                }

                if(state == false){
                    state = true;
                }
                else{
                    return(false);
                }
            }
        }

        return(state);
    }
};
