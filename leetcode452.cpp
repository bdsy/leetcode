/*
在二维空间中有许多球形的气球。对于每个气球，提供的输入是水平方向上，气球直径的开始和结束坐标。由于它是水平的，所以y坐标并不重要，因此只要知道开始和结束的x坐标就足够了。开始坐标总是小于结束坐标。平面内最多存在104个气球。
一支弓箭可以沿着x轴从不同点完全垂直地射出。在坐标x处射出一支箭，若有一个气球的直径的开始和结束坐标为 xstart，xend， 且满足  xstart ≤ x ≤ xend，则该气球会被引爆。可以射出的弓箭的数量没有限制。 弓箭一旦被射出之后，可以无限地前进。我们想找到使得所有气球全部被引爆，所需的弓箭的最小数量。
*/

class Solution {
public:
    int findMinArrowShots(vector<pair<int, int>>& points) {
        auto cmp =[](pair<int, int> p, pair<int, int> q){
            if(p.second < q.second){
                return(true);
            }
            else{
                return(false);
            }
        };
        sort(points.begin(), points.end(), cmp);


        int i,j,n,m,count;
        n = points.size();
        vector<int> pick(n,1);
        count = 0;
        i = 0;
        while(i < n){
            if(pick[i] == 0){
                i += 1;
                continue;
            }

            count += 1;
            for(j = i; j < n; ++j){
                if(points[j].first <= points[i].second){
                    pick[j] = 0;
                }
            }

            i += 1;
        }

        return(count);
    }
};
