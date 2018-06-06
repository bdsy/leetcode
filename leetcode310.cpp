/*
编写一段程序来查找第 n 个超级丑数。
超级丑数是指其所有质因数都在长度为 k 的质数列表 primes 中的正整数。
*/

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int k = primes.size();
        int i,j,m,p,q;
        vector<int> nums(n+1,1);
        vector<int> point(k,1);
        
        for(i = 2; i <= n; ++i){
            int min_num = INT_MAX;
            for(j = 0; j < k; ++j){
                if(primes[j]*nums[point[j]] < min_num){
                    min_num = primes[j]*nums[point[j]];
                }
            }
            
            nums[i] = min_num;
            
            for(j = 0; j < k; ++j){
                if(primes[j]*nums[point[j]] == min_num){
                    point[j] += 1;
                }
            }
            
            
        }
        return(nums[n]);
    }
};
