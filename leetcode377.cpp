/*
给定一个由正整数组成且不存在重复数字的数组，找出和为给定目标正整数的组合的个数。
*/

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> result(target+1,0);
        int n = nums.size();
        int i,j,k;
        sort(nums.begin(),nums.end());
        result[0] = 1;


        if(n == 0){
            return(0);
        }

        for(i = nums[0]; i <= target; ++i){
            for(j = 0; j < n && nums[j] <= i; ++j){
                result[i] += result[i-nums[j]];
            }
        }

        return(result[target]);
    }
};
