/*
两个整数之间的汉明距离指的是这两个数字对应二进制位不同的位置的数目。
给出两个整数 x 和 y，计算它们之间的汉明距离。
*/

class Solution {
public:
    int hammingDistance(int x, int y) {
        int i,j,n,m;
        int count = 0;

        for(i = 0; i < 32; ++i){
            if(((x>>i)&1) != ((y>>i)&1)){
                count += 1;
            }
        }

        return(count);
    }
};
