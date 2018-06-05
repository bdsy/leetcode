/*
给定一个整数数组  nums，求出数组从索引 i 到 j  (i ≤ j) 范围内元素的总和，包含 i,  j 两点。
*/

class NumArray {
public:
    vector<int> sums;
    NumArray(vector<int> nums) {
        sums.push_back(0);
        int i, j, n;
        n = nums.size();
        
        for(i = 0; i < n; ++i){
            sums.push_back(sums[i]+nums[i]);
        }
    }
    
    int sumRange(int i, int j) {
        return(sums[j+1]-sums[i]);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */
