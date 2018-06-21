/*
二进制手表顶部有 4 个 LED 代表小时（0-11），底部的 6 个 LED 代表分钟（0-59）

给定一个非负整数 n 代表当前 LED 亮着的数量，返回所有可能的时间。

输入: n = 1
返回: ["1:00", "2:00", "4:00", "8:00", "0:01", "0:02", "0:04", "0:08", "0:16", "0:32"]
 */

class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        int i,j,n;

        vector<string> result;

        for(i = 0; i <= num; ++i){
            if(i > 4 || num-i > 6){
                continue;
            }
            vector<string> hour = hour_calc(i);

            vector<string> minutes = minutes_calc(num-i);
            for(auto &s1: hour){
                cout<<num-i<<":"<<endl;
                for(auto &s2: minutes){
                    cout<<s2<<" ";
                    result.push_back(s1+":"+s2);
                }
                cout<<endl;
            }
        }

        return(result);
    }

    vector<string> hour_calc(int n){
        vector<string> result;
        int i,num;

        if(n == 0){
            result.push_back("0");
            return(result);
        }

        for(i = n-1; i < 4; ++i){
            for(auto& j : hour_count(n-1,i-1)){
                if((1<<i)+j < 12){
                    result.push_back(to_string((1<<i)+j));
                }

            }

        }

        return(result);
    }

    vector<int> hour_count(int n, int end){
        int i;
        vector<int> result;
        if(n == 0){
            result.push_back(0);
            return(result);
        }

        for(i = n-1; i <= end; ++i){
            for(auto& j: hour_count(n-1, i-1)){
                if((1<<i)+j < 12){
                    result.push_back(((1<<i)+j));
                }

            }

        }

        return(result);
    }


    vector<string> minutes_calc(int n){
        vector<string> result;
        int i,num;

        if(n == 0){
            result.push_back("00");
            return(result);
        }

        for(i = n-1; i < 6; ++i){
            for(auto& j: minutes_count(n-1,i-1)){
                if((1<<i) + j >= 10 && ((1<<i) + j < 60)){
                    result.push_back(to_string((1<<i)+j));
                }
                else if((1<<i) + j < 10){
                    result.push_back("0"+to_string((1<<i)+j));
                }
            }

        }

        return(result);
    }

    vector<int> minutes_count(int n, int end){
        int i;

        vector<int> result;
        if(n == 0){
            result.push_back(0);
            return(result);
        }

        for(i = n-1; i <= end; ++i){
            for(auto& j : minutes_count(n-1, i-1)){
                result.push_back(((1<<i)+j));
            }

        }

        return(result);
    }
};
