/*
给定一个无序的整数数组，找到其中最长上升子序列的长度。
*/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int i,j,n,m,l,r;
        vector<int> d(1,INT_MIN);
        
        n = nums.size();
        if(n <= 1){
            return(n);
        }

        d.push_back(nums[0]);
        m = 1;
        for(i = 1; i < n; ++i){
            if(nums[i] > d[m]){
                d.push_back(nums[i]);
                m += 1;
            }
            else if(nums[i] < d[1]){
                d[1] = nums[i];
            }
            else if(nums[i] < d[m] && nums[i] > d[1]){
                int p = 1;
                int q = m;
                int k;
                while(p < q){
                    k = (p+q)/2;
                    if(d[k] < nums[i]){
                        p = k+1;
                    }
                    else{
                        q = k;
                    }
                }
                d[p] = nums[i];
            }
        } 
        return(m);     
    }
};
