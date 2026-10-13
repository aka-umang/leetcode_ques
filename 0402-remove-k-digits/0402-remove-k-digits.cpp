
class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        if (k == n) return "0";

        stack<char> st;

        for (char ch : num) {
            while (k > 0 && !st.empty() && st.top() > ch) {
                st.pop();
                k--;
            }
            st.push(ch);
        }

        // Remove remaining digits from the end
        while (k--) st.pop();

        
        string ans = "";
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        // Remove leading zeros
        int i=0;
        while(i<ans.size()){
            if(ans[i]=='0') i++;
            else {
                return ans.substr(i);
            }
        }
        return "0";
    }
};
