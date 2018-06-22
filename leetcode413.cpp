/*
如果一个数列至少有三个元素，并且任意两个相邻元素之差相同，则称该数列为等差数列。
数组 A 包含 N 个数，且索引从0开始。数组 A 的一个子数组划分为数组 (P, Q)，P 与 Q 是整数且满足 0<=P<Q<N 。
如果满足以下条件，则称子数组(P, Q)为等差数组：
元素 A[P], A[p + 1], ..., A[Q - 1], A[Q] 是等差的。并且 P + 1 < Q 。
函数要返回数组 A 中所有为等差数组的子数组个数。
*/

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int i,j,n,start,end,dis,result;
        n = A.size();

        if(n <= 2){
            return(0);
        }

        result = 0;
        start = 0;
        dis = A[1]-A[0];
        end = 1;
        j = 2;
        while(j < n){
            if(A[j]-A[j-1] == dis){
                end = j;
            }
            else{
                if(end - start >= 2){
                    result += (end-start)*(end-start-1)/2;
                }

                start = j-1;
                end = j;
                dis = A[j]-A[j-1];
            }

            j += 1;
        }

        if(end - start >= 2){
            result += (end-start)*(end-start-1)/2;
        }

        return(result);
    }
};
