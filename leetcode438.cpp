/*
给定一个字符串 s 和一个非空字符串 p，找到 s 中所有是 p 的字母异位词的子串，返回这些子串的起始索引。
字符串只包含小写英文字母，并且字符串 s 和 p 的长度都不超过 20100。
说明：
字母异位词指字母相同，但排列不同的字符串。
不考虑答案输出的顺序。
*/

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size();
        int m = p.size();
        int i,j,k,count;
        map<char, int> record;
        map<char, int> now;
        vector<int> result;
        
        count = 0;
        for(i = 0; i < m; ++i){
            if(record.find(p[i]) == record.end()){
                count += 1;
                record[p[i]] = 0;
            }
            record[p[i]] += 1;
        }
        
        i = 0;
        k = 0;
        j = 0;
        while(i <= n-m){
            while(j < i+m && j < n){
                if(record.find(s[j]) != record.end()){
                    if(now.find(s[j]) == now.end()){
                        now[s[j]] = 0;
                    }
                    now[s[j]] += 1;
                    if(now[s[j]] == record[s[j]]){
                        k += 1;
                    }
                    if(now[s[j]] == record[s[j]]+1){
                        k -= 1;
                    }
                }
                else{
                    now.clear();
                    k = 0;
                    i = j+1;
                }
                
                j += 1;
            }
            
            if(count == k){
                result.push_back(i);
            }
            
            if(now.find(s[i]) != now.end() && now[s[i]] == record[s[i]]){
                k -= 1;
            }
            else if(now.find(s[i]) != now.end() && now[s[i]] == record[s[i]]+1){
                k += 1;
            }
            
            if(now.find(s[i]) != now.end()){
                now[s[i]] -= 1;
            }
            
            i += 1;
        }
        return(result);
    }
};
