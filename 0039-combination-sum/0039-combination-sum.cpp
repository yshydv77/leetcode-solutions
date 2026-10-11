class Solution {
public:
    vector<vector<int>> ans;
    void helper(vector<int>& candidates, int target, int i, int n,
                vector<int> diary, int sum) {
        if (i == n) {
            if (sum == target) {
                ans.push_back(diary);
            }
            return;
        }
    

    helper(candidates, target, i + 1, n, diary, sum);
    if (sum + candidates[i] <= target) {
        // 2 choices
        // lete jao lete jao
        sum += candidates[i];
        diary.push_back(candidates[i]);
        helper(candidates, target, i, n, diary, sum);
        sum -= candidates[i];
        diary.pop_back();
    }

    return;

}

vector<vector<int>>
combinationSum(vector<int>& candidates, int target) {
    helper(candidates, target, 0, candidates.size(), {}, 0);
    return ans;
}
}
;