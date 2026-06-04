class Solution {
public:
    void mergeIntervals(vector<vector<int>>& intervals,
                        vector<vector<int>>& ans) {

        int start1 = intervals[0][0];
        int end1 = intervals[0][1];

        for (int i = 1; i < intervals.size(); i++) {
            int start2 = intervals[i][0];
            int end2 = intervals[i][1];

            // merge hoga when end1 >= start2
            if (end1 >= start2) {
                start1 = start1;
                end1 = max(end1, end2);
            } else {
                // merge nahi hoga
                // ans store kar lo phele jo merge ho chuka hai uska
                ans.push_back({start1, end1});
                start1 = start2;
                end1 = end2;
            }
        }

        ans.push_back({start1, end1});
    }
    vector<vector<int>> insert(vector<vector<int>>& intervals,
                               vector<int>& newInterval) {
        // 2d array start and end de rakha hai and merge karne ka bol raha hai
        //  merge interval ka question ha

        int n = intervals.size();
        if (n == 0) {
            return {newInterval};
        }
        intervals.push_back({newInterval});
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;

        mergeIntervals(intervals, ans);
        return ans;
    }
};