class Solution {
public:
    bool wordPattern(string pattern, string s) {
    
        stringstream tokenize(s);
        string intermediate;
    
        unordered_map<string,char> mp;
        int i=0;
        int n=pattern.size();
        vector<bool>came(26,false);

        while(getline(tokenize, intermediate, ' ')){
            if(i>=n) return false;
            if(mp.count(intermediate)){
                if(mp[intermediate]!=pattern[i]) return false;
            }
            else {
               if(came[pattern[i]-'a']) return false;
               came[pattern[i]-'a']=true;
                mp[intermediate]=pattern[i];
            }
            i++;
        }
        return i>=n;
    }
};