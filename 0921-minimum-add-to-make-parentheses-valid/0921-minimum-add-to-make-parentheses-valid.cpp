class Solution {
public:
    int minAddToMakeValid(string s) {
        int n=s.size();
        if(n==0) return 0;

        int ans=0,c=0;

        for(int i=0;i<n;i++){
            if(s[i]=='(') c++;
            else c--;
            if(c<0){
                ans++;
                c=0;
            }
        }  
        return ans+c;  
    }
};