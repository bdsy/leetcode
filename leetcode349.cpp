/*
给定两个数组，写一个函数来计算它们的交集。
例子:
 给定 num1= [1, 2, 2, 1], nums2 = [2, 2], 返回 [2].
*/

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<int> result;
        map<int,int> d;
        int i,j;
        for(i = 0; i < n; ++i){
            d[nums1[i]] = 1;
        }

        for(i = 0; i < m; ++i){
            if(d.find(nums2[i]) != d.end()){
                result.push_back(nums2[i]);
                d.erase(nums2[i]);
            }
        }

        return(result);

    }
};
