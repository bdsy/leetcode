/*
Given a list of airline tickets represented by pairs of departure and arrival airports [from, to], reconstruct the itinerary in order. All of the tickets belong to a man who departs from JFK. Thus, the itinerary must begin with JFK.

Note:
If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical order when read as a single string. For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].
All airports are represented by three capital letters (IATA code).
You may assume all tickets form at least one valid itinerary.
Example 1:
tickets = [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]
Return ["JFK", "MUC", "LHR", "SFO", "SJC"].
Example 2:
tickets = [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
Return ["JFK","ATL","JFK","SFO","ATL","SFO"].
Another possible reconstruction is ["JFK","SFO","ATL","JFK","ATL","SFO"]. But it is larger in lexical order.



*/


class Solution {
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        map<string,vector<string>> p;
        int i,j,n,m;
        map<string,int> d;
        vector<string> result;

        n = tickets.size();
        m = n;
        for(i = 0; i < n; ++i){
            if(d.find(tickets[i].first+tickets[i].second) == d.end()){
                d[tickets[i].first+tickets[i].second] = 1;
            }
            else{
                d[tickets[i].first+tickets[i].second] += 1;
            }

            p[tickets[i].first].push_back(tickets[i].second);
        }

        map<string,vector<string>>::iterator it = p.begin();
        for(; it != p.end(); ++it){
            sort(it->second.begin(),it->second.end());
        }

        n = p["JFK"].size();

        for(i = 0; i < n; ++i){
            string ch = "JFK";
            ch.append(p["JFK"][i]);
            d[ch] -= 1;
            if(find_path(p["JFK"][i],d,p,1,m,result)){
                result.push_back("JFK");
                break;
            }
            d[ch] += 1;
        }

        reverse(result.begin(),result.end());
        return(result);
    }

    bool find_path(string node, map<string,int> &d, map<string,vector<string>> &p,int k,int m,vector<string>& result){
        if(k == m){
            result.push_back(node);
            return(true);
        }

        int n = p[node].size();
        for(int i = 0; i < n; ++i){
            string ch = "";
            ch.append(node);
            ch.append(p[node][i]);
            if(d[ch] > 0){
                d[ch] -= 1;
                if(find_path(p[node][i],d,p,k+1,m,result)){
                    result.push_back(node);
                    return(true);
                }
                d[ch] += 1;
            }
        }

        return(false);
    }
};
