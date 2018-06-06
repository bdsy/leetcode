/*
序列化二叉树的一种方法是使用前序遍历。当我们遇到一个非空节点时，我们可以记录下这个节点的值。如果它是一个空节点，我们可以使用一个标记值记录，例如 #。
*/


class Solution {
public:
    vector<string> &split(const string &str, char delim, vector<string> &elems, bool skip_empty = true) {
    istringstream iss(str);
    for (string item; getline(iss, item, delim); )
        if (skip_empty && item.empty()) continue;
        else elems.push_back(item);
    return elems;
    }
    
    bool isValidSerialization(string preorder) {
        vector<string> node;
        split(preorder, ',',node);
        int n = node.size();
        int i,j,k;
        stack<int> p;
        p.push(1);
        i = 0;
        int temp;
        while(i < n){
            if(p.empty()){
                return(false);
            }
            if(isdigit(node[i][0])){
                temp = p.top();
                p.pop();
                if(temp == 1){
                    p.push(0);
                }
                else{
                    p.push(1);
                    p.push(0);
                }
            }
            else{
                if(p.empty()){
                    return(false);
                }
                if(p.top() == 1){
                    p.pop();
                }
                else{
                    p.pop();
                    p.push(1);
                }
            }
            i += 1;
        }
        if(p.empty()){
            return(true);
        }
        else{
            return(false);
        }
    }
};
