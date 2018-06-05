/*
给定一种 pattern(模式) 和一个字符串 str ，判断 str 是否遵循相同的模式。

这里的遵循指完全匹配，例如， pattern 里的每个字母和字符串 str 中的每个非空单词之间存在着双向连接的对应模式。

pattern = "abba", str = "dog cat cat dog"       true
pattern = "abba", str = "dog cat cat fish"      false
pattern = "aaaa", str = "dog cat cat dog"       false
pattern = "abba", str = "dog dog dog dog"       false
*/

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        map<string,string> d;
        map<string,string> p;

        int i,j,n,m;
        n = pattern.size();
        m = str.size();
        if(n != m){
            return(false);
        }      

        for(i = 0; i < n; ++i){
            if(d.find(pattern[i]) == d.end() && p.find(str[i]) == p.end()){
                d[pattern[i]] = str[i];
                p[str[i]] = pattern[i];
            }
            else if(d.find(pattern[i]) != d.end() && p.find(str[i]) != p.end() && d[pattern[i]] == p[str[i]]){
                continue;
            }
            else{
                return(false);
            }
        }

        return(true);
    }
};
