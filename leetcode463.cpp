/*
给定一个包含 0 和 1 的二维网格地图，其中 1 表示陆地 0 表示水域。网格中的格子水平和垂直方向相连（对角线方向不相连）。整个网格被水完全包围，但其中恰好有一个岛屿（或者说，一个或多个表示陆地的格子相连组成的岛屿）。岛屿中没有“湖”（“湖” 指水域在岛屿内部且不和岛屿周围的水相连）。格子是边长为 1 的正方形。网格为长方形，且宽度和高度均不超过 100 。计算这个岛屿的周长。
*/

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int i,j,n,count,m;

        n = grid.size();
        if(n == 0){
            return(0);
        }
        m = grid[0].size();
        if(m == 0){
            return(0);
        }

        count = 0;
        for(i = 0; i < n; ++i){
            for(j = 0; j < m; ++j){
                if(grid[i][j] == 0){
                    continue;
                }
                if(i == 0 || grid[i-1][j] == 0){
                    count += 1;
                }
                if(i == n-1 || grid[i+1][j] == 0){
                    count += 1;
                }
                if(j == 0 || grid[i][j-1] == 0){
                    count += 1;
                }
                if(j == m-1 || grid[i][j+1] == 0){
                    count += 1;
                }
            }
        }

        return(count);
    }
};
