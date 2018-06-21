/*
给定一个以字符串表示的非负整数 num，移除这个数中的 k 位数字，使得剩下的数字最小。
注意:
m的长度小于 10002 且 ≥ k。
num 不会包含任何前导零
 */

class Solution {
public:
    string removeKdigits(string num, int k) {
        int i,j,n,m,q;
        n = num.size();
        if(k >= n){
            return("0");
        }

        vector<int> del(n,0);

        for(i = 0; i < k; ++i){
            for(j = 0; j < n; ++j){
                if(del[j] == 0){
                    break;
                }
            }

            for(q = j+1; q < n; ++q){
                if(del[q] == 0 && num[q] < num[j]){
                    break;
                }
                else if(del[q] == 0 && num[q] > num[j]){
                    j = q;
                }
            }

            del[j] = 1;
        }

        string result = "";
        for(j = 0; j < n; ++j){
            if(del[j] == 0){
                if(result == ""){
                    if(num[j] != '0'){
                        result += (num[j]);
                    }
                }
                else{
                    result += (num[j]);
                }
            }
        }
        if(result == ""){
            result = "0";
        }
        return(result);
    }
};
