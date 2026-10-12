class Solution {
public:
    int n;
    int MOD=1e9+7;

    bool isStar(char& ch) {return ch=='*';}
    
    int solve(string &s){
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
            
            //1->9
            long long count=dp_i_plus_1;
            if(isStar(s[i]))  {count=(count+8LL*dp_i_plus_1)%MOD;}
            
            if(i+1<n){
                // dd
                if(isdigit(s[i+1]) && (s[i]=='1' || (s[i]=='2' && s[i+1]<='6'))) {
                    count=(count+1LL*dp_i_plus_2)%MOD;
                }
                else if(isStar(s[i+1])){ 
                    //1* , **
                    if(s[i]=='1' || isStar(s[i]))   {count=(count+9LL*dp_i_plus_2)%MOD;}
                    //2* , **
                    if(s[i]=='2' || isStar(s[i]))  { count=(count+6LL*dp_i_plus_2)%MOD;}
                }//*d
                else if(isStar(s[i]) && isdigit(s[i+1])){
                    count=(count+1LL*dp_i_plus_2)%MOD; //1d
                    if(s[i+1]<='6') count=(count+1LL*dp_i_plus_2)%MOD; //2d   
                }
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