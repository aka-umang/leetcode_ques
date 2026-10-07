class Solution {
public:
    unordered_set<string>st;
    int maxi;
    int n;
    void solve(string &s,string &curr,int maxLen,int i,int count){
        if(i==n){
            if(count==0){
                if(st.empty())  maxi=maxLen;
                else if(maxLen>maxi){
                    maxi=maxLen;
                    st.clear();
                }
                
                if(maxLen==maxi) st.insert(curr);
            }
            return;
        }
        if(count<0) return;

        if(s[i]!='(' && s[i]!=')'){
            curr.push_back(s[i]);
            solve(s,curr,maxLen,i+1,count);
            curr.pop_back();
            return;
        }
        else{
            curr.push_back(s[i]);
            solve(s,curr,maxLen+1,i+1,(s[i]=='(')?count+1:count-1);
            curr.pop_back();
            solve(s,curr,maxLen,i+1,count);
        }
    }
    vector<string> removeInvalidParentheses(string s) {
        vector<string>ans;
        maxi=0;
        n=s.size();
        string curr="";
        solve(s,curr,0,0,0);

        for(auto& str:st){
            ans.push_back(str);
        }
        return ans;
    }
};