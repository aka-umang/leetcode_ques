class Solution {
public:
    vector<string>ans;
    int N;
    void solve(string &str,int open_count,int close_count){
        if(close_count>open_count) return;
        if(str.size()==2*N){
            ans.push_back(str);
            return;
        }
        if(open_count<N){
            str.push_back('(');
            solve(str,open_count+1,close_count);
            str.pop_back();
        }
        if(close_count<N){
            str.push_back(')');
            solve(str,open_count,close_count+1);
            str.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        N=n;
        string str="";
        solve(str,0,0);
        return ans;
    }
};