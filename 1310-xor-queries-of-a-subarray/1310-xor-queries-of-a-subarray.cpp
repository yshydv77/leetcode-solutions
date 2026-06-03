class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> ans;
        vector<int> prefix(arr.size());
        vector<int> suffix(arr.size());
        int p = 0;
        int s = 0;
        for (int i = 0; i < arr.size(); i++) {
            p ^= arr[i];
            prefix[i] = p;
        }

        for (int i = 0; i < queries.size(); i++) {
            int start = queries[i][0];
            int end = queries[i][1];

            if (start == 0) {
                ans.push_back(prefix[end]);
            } else {
                int query_end = prefix[end];
                int query_start = prefix[start - 1];
                int res = query_end ^ query_start;
                ans.push_back(res);
            }
        }

        return ans;
    }
};