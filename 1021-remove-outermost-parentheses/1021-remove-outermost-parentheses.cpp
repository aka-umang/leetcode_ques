class Solution {
public:
    string removeOuterParentheses(string s) {
        int n=s.size();
        int count=0;
        int i=0;
        string res="";
        
        while(i<n){
            if(s[i]=='('){
                if(count!=0) res.push_back(s[i]);
                count++;
            }else{
                count--;
                if(count!=0) res.push_back(s[i]);
            }
            i++;
        }
        return res;
    }
};