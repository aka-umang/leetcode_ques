class Solution {
public:
    vector<bool>visited;
    int n;

    void solve(vector<vector<int>>& rooms,int i,int& c){
        if(i>=n) return;
        c++;
        visited[i]=true;

        for(int & r:rooms[i]){
            if(visited[r]) continue;
            solve(rooms,r,c);
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        n=rooms.size();
        visited.resize(n,false);
        int c=0;
        solve(rooms,0,c);
        if(c!=n) return false;
        return true;
    }
};