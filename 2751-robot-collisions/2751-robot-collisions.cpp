
class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& pos,
                                      vector<int>& health,
                                      string dir) {
        int n = pos.size();
        vector<int> actual_idx(n);
        iota(actual_idx.begin(), actual_idx.end(), 0);

        sort(actual_idx.begin(), actual_idx.end(),
             [&](int i, int j) {
                 return pos[i] < pos[j];
             });

        stack<int> st;

        for (int idx : actual_idx) {
            if (dir[idx] == 'R') {
                st.push(idx);
                continue;
            }

            while (!st.empty() && health[idx] > 0) {
                int j = st.top();

                if (health[j] < health[idx]) {
                    health[j] = 0;
                    st.pop();
                    health[idx]--;
                } 
                else if (health[j] == health[idx]) {
                    health[j] = 0;
                    health[idx] = 0;
                    st.pop();
                    break;
                } 
                else {
                    health[j]--;
                    health[idx] = 0;
                    break;
                }
            }
        }

        vector<int> ans;
        for (int h : health) {
            if (h > 0) ans.push_back(h);
        }

        return ans;
    }
};
