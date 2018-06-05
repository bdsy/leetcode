/*
给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。
*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i,j,n,m,zero,one;
        n = nums.size();

        one = 0;
        for(zero = 0; zero < n; ++zero){
            if(nums[zero] == 0){
                for(one = max(one,zero+1); one < n; ++one){
                    if(nums[one] != 0){
                        nums[zero] = nums[one];
                        nums[one] = 0;
                        break;
                    }
                }
                if(one == n){
                    return;
                } 
            }
        }

        return;      
    }
};
