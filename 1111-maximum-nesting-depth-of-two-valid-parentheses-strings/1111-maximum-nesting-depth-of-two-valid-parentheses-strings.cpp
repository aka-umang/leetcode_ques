class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int d=0;
        int n=seq.size();
        //d=even  ->0
        //d=odd   ->1
        vector<int>ans(n);

        for(int i=0;i<n;i++){
            if(seq[i]=='('){
                d++;
                if(d%2) ans[i]=1;
                else ans[i]=0;
            }else{  
                if(d%2) ans[i]=1;
                else ans[i]=0;
                d--;
            }
        }
        return ans;
    }
};