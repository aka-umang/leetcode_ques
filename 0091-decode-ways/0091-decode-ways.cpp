class Solution {
public:
    int n;
    int solve(string &s) {
        int dp_i=-1;
        int dp_i_plus_1=1;
        int dp_i_plus_2=-1;
      
        for(int i=n-1;i>=0;i--){
            if(s[i]=='0'){
                dp_i=0;
                dp_i_plus_2=dp_i_plus_1;
                dp_i_plus_1=dp_i;
                continue;
            }
            
            int count=dp_i_plus_1; //1->9 
            if(i+1<n && (s[i]=='1' || s[i]=='2' && s[i+1]<='6')){  //10->19
                count+=dp_i_plus_2;
            } 

            dp_i=count;
            dp_i_plus_2=dp_i_plus_1;
            dp_i_plus_1=dp_i;
        }

        return dp_i;
    }
    
    int numDecodings(string s) {
        n=s.size();
        return solve(s);  
    }
};