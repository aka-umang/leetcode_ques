class Solution {
public:
    string convert(string s, int n) { //n->numRows
        int k=2; //times==2 prr 2, times==3 prr 4, times==1 and times==last prr 2n-2
      
        int size=s.size();
        if(n==1) return s;
        int times=1;
        string ans="";
        while(times<=n){ //jitni rows utni brr chlegi
            int i=times-1;
            if(times==1 || times==n){
                while(i<size){
                    ans.push_back(s[i]);
                    i+=2*n-2;
                }
            } 
            else{
                int peeche=k; k+=2;                while(i<size){
                    if(i-peeche>=0) ans.push_back(s[i-peeche]);
                    ans.push_back(s[i]);
                    i+=2*n-2;
                }
                if(i-peeche<size && i-peeche>=0) ans.push_back(s[i-peeche]);
            }
            times++;
        }
        return ans;
    }
};