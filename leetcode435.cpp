/*
给定一个区间的集合，找到需要移除区间的最小数量，使剩余区间互不重叠。
输入: [ [1,2], [2,3], [3,4], [1,3] ]
输出: 1
解释: 移除 [1,3] 后，剩下的区间没有重叠
*/

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    int eraseOverlapIntervals(vector<Interval>& intervals) {
        auto cmp =[](Interval p, Interval q){
            if(p.end < q.end){
                return(true);
            }
            else if(p.end == q.end){
                return(p.start > q.start);
            }
            else{
                return(false);
            }
        };

        sort(intervals.begin(), intervals.end(), cmp);

        int count = 0;
        int i,j,n;
        n = intervals.size();
        i = 0;
        j = 1;
        while(j < n){
            if(intervals[i].end > intervals[j].start){
                count += 1;
                j += 1;
            }
            else{
                i = j;
                j += 1;
            }
        }
        return(count);
    }
};
