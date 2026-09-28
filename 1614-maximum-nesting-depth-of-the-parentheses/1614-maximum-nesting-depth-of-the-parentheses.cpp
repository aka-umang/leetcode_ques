class Solution {
public:
    int maxDepth(string s) {
       int c=0;
       int maxi=0;

       for(auto& ch:s){
            if(ch=='(') c++;
            else if(ch==')')  c--;

            maxi=max(maxi,c);
        } 
        return maxi;
    }
};