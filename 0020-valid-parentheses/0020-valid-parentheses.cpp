class Solution {
public:
    bool isValid(string s) {
        unordered_map<char,char>m;
        stack<int>st;
        m['}']='{';
        m[')']='(';
        m[']']='[';
        for(auto ele:s){
            if(ele=='(' || ele=='{' || ele=='[') st.push(ele);
            else{
                if(st.size()==0 || st.top()!=m[ele]) return false;
                st.pop();
            }
        }
      return st.size()==0;
    }
};