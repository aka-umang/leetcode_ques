class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroidList) {
        
    int n=asteroidList.size();
    vector<int> ans;
    stack<int> st;
    
    for(int &ele:asteroidList){
        if(ele>0) st.push(ele);
        else{
            int mag=abs(ele);
            int lastBlast=-1001;
            
            while(!st.empty() && st.top()<=mag){
                lastBlast=st.top();
                st.pop();
                if(lastBlast==mag) break;
            }
            
            if(st.empty() && lastBlast!=mag) ans.push_back(-1*mag);
        }
    }
    
    vector <int>temp;
    while(!st.empty()){
        int x=st.top(); st.pop();
        temp.push_back(x);
    }
    
    while(temp.size()>0){
        int x=temp.back();
        ans.push_back(x);
        temp.pop_back();
    }
    
    return ans;
    }
};