class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        int n=101;
        for(int i=0;i<seats.size();i++){
            n=max({n,seats[i],students[i]});
        }
        int m=n+1;
        vector<int>kursi(m,0);
        vector<int>bcche(m,0);

        for(int i=0;i<seats.size();i++){
            kursi[seats[i]]++;
            bcche[students[i]]++;
        }

        int i=0,j=0;
        int moves=0;
        while(i<m && j<m){
            while(i<m && kursi[i]==0) i++;
            while(j<m && bcche[j]==0) j++;
            moves+=abs(j-i);
            if(i<m){
                kursi[i]--; 
                if(kursi[i]==0) i++;
            }
            if(j<m){
                bcche[j]--; 
                if(bcche[j]==0) j++;
            }
        }

        return moves;
    }
};