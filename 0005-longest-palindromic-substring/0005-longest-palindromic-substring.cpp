class Solution {
public:
    
    int finder(string &s, int i, int j){
        int n=s.size();
        if(j==n) return -1;
        int maxi=0;

        while(i>=0 && j<n){    
            if(s[i]==s[j]){
                maxi=max(maxi,j-i+1);
                i--;
                j++;
            }
            else return maxi;
        }
        return maxi;
    }

    string longestPalindrome(string s) {
       int n=s.size();
       //if(n==1) return s;
       int ans=1;
       int idx=0;
       for(int i=0;i<n;i++){
            int c1=finder(s,i,i);
            int c2=finder(s,i,i+1);

            if(ans<c1){
                ans=c1;
                idx=i+1-ceil(c1/2.0);
            }
            if(ans<c2){
                ans=c2;
                idx=i+1-ceil(c2/2);
            }
       } 

       return s.substr(idx,ans);
    }
};