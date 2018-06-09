/*
给出一个由无重复的正整数组成的集合, 找出其中最大的整除子集, 子集中任意一对 (Si, Sj) 都要满足: Si % Sj = 0 或 Sj % Si = 0。
如果有多个目标子集，返回其中任何一个均可。
*/

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int i,j,n,m;
        vector<int> result;
        sort(nums.begin(), nums.end());
        n = nums.size();
        vector<int> k_num(n,1);
        vector<int> pos(n,0);
        int max_num = 1;
        int max_pos = 0;

        if(n == 0){
            return(result);
        }

        for(i = 1; i < n; ++i){
            pos[i] = i;
            for(j = 0; j < i; ++j){
                if(nums[i]%nums[j] == 0 && k_num[j]+1 > k_num[i]){
                    k_num[i] = k_num[j]+1;
                    pos[i] = j;
                    if(k_num[i] > max_num){
                        max_num = k_num[i];
                        max_pos = i;
                    }
                }
            }
        }


        while(pos[max_pos] != max_pos){
            result.push_back(nums[max_pos]);
            max_pos = pos[max_pos];
        }
        result.push_back(nums[max_pos]);
        return(result);
    }
};
