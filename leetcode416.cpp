/*
Given a non-empty array containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.

Note:
Each of the array element will not exceed 100.
The array size will not exceed 200.

Input: [1, 5, 11, 5]

Output: true

Explanation: The array can be partitioned as [1, 5, 5] and [11].
*/


class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int i,num,j;
        int n = nums.size();
        
        for(i = 0; i < n; ++i){
            sum += nums[i];
        }
        if(sum % 2 == 1){
            return(false);
        }
        
        sum = sum/2;
        vector<int> result(sum+1,0);
        result[0] = 1;
        
        for(j = 0; j < n; ++j){
            for(int i = sum-nums[j]; i >= 0; --i){
                if(result[i] == 1){
                    result[i+nums[j]] = 1;
                }
            }
        }
        
        return(result[sum] == 1);
    }
};
