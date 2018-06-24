/*
给定一个非空的字符串，判断它是否可以由它的一个子串重复多次构成。给定的字符串只含有小写英文字母，并且长度不超过10000。
 */

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int i,j,k,n,m;

        n = s.size();
        if(n <= 1){
            return(false);
        }
        for(i = 1; i < n; ++i){
            if(s[i] == s[0]){
                for(j = i; j < n; j += i){
                    if(s.substr(0,i) != s.substr(j,i)){
                        break;
                    }
                }
                if(j >= n){
                    return(true);
                }
            }
        }

        return(false);
    }
};
