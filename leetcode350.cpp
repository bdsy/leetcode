/*
给定两个数组，写一个方法来计算它们的交集。
例如:
给定 nums1 = [1, 2, 2, 1], nums2 = [2, 2], 返回 [2, 2].
注意：
   输出结果中每个元素出现的次数，应与元素在两个数组中出现的次数一致。
   我们可以不考虑输出结果的顺序。
*/

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> d;
        int n = nums1.size();
        int m = nums2.size();
        int i,j;
        vector<int> result;

        for(i = 0; i < n; ++i){
            if(d.find(nums1[i]) == d.end()){
                d[nums1[i]] = 0;
            }
            d[nums1[i]] += 1;
        }

        for(i = 0; i < m; ++i){
            if(d.find(nums2[i]) != d.end()){
                d[nums2[i]] -= 1;
                if(d[nums2[i]] == 0){
                    d.erase(nums2[i]);
                }
                result.push_back(nums2[i]);
            }
        }

        return(result);

    }
};
