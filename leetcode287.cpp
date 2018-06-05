/*
给定一个包含 n + 1 个整数的数组 nums，其数字都在 1 到 n 之间（包括 1 和 n），可知至少存在一个重复的整数。假设只有一个重复的整数，找出这个重复的数。
*/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int l,r,m,n,left,right,i;

        n = nums.size();
        l = 1;
        r = n-1;
        while(l < r){
            m = (l+r)/2;
            left = 0;
            right = 0;
            for(i = 0; i < n; ++i){
                if(nums[i] <= m && nums[i] >= l){
                    left += 1;
                }
                else if(nums[i] > m && nums[i] <= r){
                    right += 1;
                }
            }
            if(left > m-l+1){
                r = m;
            }
            else{
                l = m+1;
            }
        }        
        return(l);
    }
};


