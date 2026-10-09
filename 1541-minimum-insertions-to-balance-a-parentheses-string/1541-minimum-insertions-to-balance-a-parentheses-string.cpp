class Solution {
public:
    int minInsertions(string s) {
        int n=s.size();
        int i=0;
        int c=0;
        int ans=0;
        while(i<n){
            if(s[i]=='(')  c++;
            else{
                if(i+1<n){
                   if(c==0 && s[i+1]=='(') ans+=2;
                   else if(c==0 && s[i+1]==')') {ans+=1; i++;}
                   else if(s[i+1]=='(') {ans++; c--;}
                   else if(s[i+1]==')') {c--; i++;}
                }
                else{
                    if(c==0) ans+=2;
                    else {ans++; c--;}
                }
            }
            i++;
        }   
        ans+=c*2;
        return ans;
    }
};