/*
给定一个经过编码的字符串，返回它解码后的字符串。
编码规则为: k[encoded_string]，表示其中方括号内部的 encoded_string 正好重复 k 次。注意 k 保证为正整数。
你可以认为输入字符串总是有效的；输入字符串中没有额外的空格，且输入的方括号总是符合格式要求的。
此外，你可以认为原始数据不包含数字，所有的数字只表示重复的次数 k ，例如不会出现像 3a 或 2[4] 的输入。
*/


class Solution {
public:
    string decodeString(string s) {
        stack<string> stk;
        int n = s.size();
        int i,j,k,num;
        string temp = "";
        string result;

        i = 0;
        num = 0;
        while(i < n){
            if(s[i] >= '0' && s[i] <= '9'){
                if(temp != ""){
                    stk.push(temp);
                    temp = "";
                }
                num = 10*num + s[i] - '0';

                if(s[i+1] == '['){
                    stk.push(to_string(num));

                    num = 0;
                }
            }
            else if(s[i] == '['){
                if(temp != ""){
                    stk.push(temp);
                }
                temp = "";
            }
            else if(s[i] == ']'){
                if(temp != ""){
                    stk.push(temp);
                }
                temp = "";

                stack<string> temp_save;
                while(!isdigit(stk.top()[0])){
                    temp_save.push(stk.top());
                    stk.pop();
                }

                while(!temp_save.empty()){
                    temp += temp_save.top();
                    temp_save.pop();
                }

                string tmp = stk.top();
                int duplicate = stoi(tmp);

                stk.pop();
                j = 1;
                string save = temp;
                while(j < duplicate){
                    save += temp;
                    j += 1;
                }
                temp = save;
                cout<<save<<endl;
            }
            else{
                temp += s[i];
            }

            i += 1;
        }
        if(temp != ""){
            stk.push(temp);
        }
        stack<string> reverse;
        while(!stk.empty()){
            reverse.push(stk.top());
            stk.pop();
        }
        while(!reverse.empty()){
            result += reverse.top();
            reverse.pop();
        }

        return(result);
    }
};
