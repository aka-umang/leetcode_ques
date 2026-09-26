class Solution {
public:
    bool solve(string &s, string &p, int i, int j){
        int n=s.size();
        int m=p.size();
        if(i>=n && j>=m) return true;
        if(j>=m) return false;
        if(p[j]=='.'){
            if(j+1<m && p[j+1]=='*'){
                if(solve(s,p,i,j+1)) return true;
            }
            else if(i<n){
                if(solve(s,p,i+1,j+1)) return true;
            }
        }

        else if(p[j]=='*'){

            //not take
            if(solve(s,p,i,j+1)) return true;

            char prev=p[j-1];
            //Take
            if(i<s.size() && prev=='.'){
                if(solve(s,p,i+1,j)) return true;
            }
            else if(i<s.size() && prev==s[i]){
                if(solve(s,p,i+1,j)) return true;
            }
        }
        else{
            if(j+1<p.size() && p[j+1]=='*'){
                if(solve(s,p,i,j+1)) return true;
            }
            else if(s[i]==p[j]) if(solve(s,p,i+1,j+1)) return true;
        }

        return false;
    }

    bool isMatch(string s, string p) {
        return solve(s,p,0,0);
    }
};