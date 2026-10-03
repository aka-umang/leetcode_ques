class Solution {
public:
    string removeStars(string s) {
        int n=s.size();
        string ans="";
        int i=0;
        while(i<n){
            if(s[i]=='*'){
                ans.pop_back();
            }
            else{
                ans.push_back(s[i]);
            }
            i++;
        }
        return ans;
    }
};