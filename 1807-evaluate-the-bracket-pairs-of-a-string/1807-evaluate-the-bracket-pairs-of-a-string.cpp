class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string,string> mp;
        for(auto& vec: knowledge) mp[vec[0]]=vec[1];

        int i=0;
        int n=s.size();
        bool open=false;
        string str="";
        string ans="";

        while(i<n){
            if(s[i]=='(') {
                ans+=str;
                str="";
                open=true;
                i++;
                continue;
            }
            else if(s[i]==')'){
                ans+=(mp.count(str))?mp[str]:"?";
                str="";
                open=false;
            }
            else str.push_back(s[i]);

            i++;
        }
        ans+=str;
        return ans;
    }
};