class Solution {
public:
    int longestValidParentheses(string s) {
        int n=s.size();
        int i=0;
       
        int ans=0;

        int open=0;
        int close=0;

        while(i<n){
            if(s[i]=='(') open++;
            else close++;

            if(close>open){
               open=close=0;
            }
            else if(open==close) {
                ans=max(ans,open+close);
            }
            i++;
        }
        
        open=close=0;
        i=n-1;
        while(i>=0){
            if(s[i]==')') close++;
            else open++;

            if(open>close){
                open=close=0;
            }
            else if(open==close){
                ans=max(ans,open+close);
            }
            i--;
        }
        return ans;
    }
};