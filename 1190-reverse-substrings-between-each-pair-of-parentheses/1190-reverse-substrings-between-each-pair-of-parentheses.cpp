class Solution {
public:
    void pushInStack(stack<char>&st ,string& str){
        for(char& ele:str) st.push(ele);
    }

    string reverseParentheses(string s) {
        int n=s.size();
        stack<char>st;
        int i=0;
        string ans="";
        
        while(i<n){
            if(s[i]!='(' && st.empty()) ans+=s[i];

            else if(s[i]!=')'){
                st.push(s[i]);
            }
            else{ //s[i]==')'
                string str="";
                while(!st.empty()){
                    char ch=st.top();   st.pop();
                    if(ch=='(') break;
                    string t=""; t+=ch; //Convert Char to String
                    str+=t;
                }
                if(st.empty()) ans+=str;
                else pushInStack(st,str);
            }
            i++;
        }
        return ans;
    }
};