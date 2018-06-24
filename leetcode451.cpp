/*
给定一个字符串，请将字符串里的字符按照出现的频率降序排列。
*/

class Solution {
public:
    string frequencySort(string s) {
        int i,j,n,m;
        n = s.size();
        map<char,int> p;
        string result = "";
        vector<string> save(n+1,"");
        for(i = 0; i < n; ++i){
            if(p.find(s[i]) == p.end()){
                p[s[i]] = 0;
            }
            p[s[i]] += 1;
        }

        map<char,int>::iterator it;
        for(it = p.begin(); it != p.end(); ++it){
            for(i = 0; i < it->second; ++i){
                save[it->second] += it->first;
            }
        }

        for(i = n; i >= 1; --i){
            result += save[i];
        }

        return(result);
    }
};
