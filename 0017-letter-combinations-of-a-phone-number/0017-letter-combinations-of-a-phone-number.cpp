class Solution {
public:
    vector<string> ans;

    void helper(string digits, string diary, int i, int n,
                unordered_map<int, string>& mp) {

        if (i == n) {
            ans.push_back(diary);
            return;
        }

        string letters = mp[digits[i] - '0'];
        for (int j = 0; j < letters.size(); j++) {
            char ch = letters[j];
            diary.push_back(ch);
            helper(digits, diary, i + 1, n, mp);
            diary.pop_back();
        }

        return;
    }
    vector<string> letterCombinations(string digits) {
        unordered_map<int, string> mp;
        mp[2] = "abc";
        mp[3] = "def";
        mp[4] = "ghi";
        mp[5] = "jkl";
        mp[6] = "mno";
        mp[7] = "pqrs";
        mp[8] = "tuv";
        mp[9] = "wxyz";
        helper(digits, "", 0, digits.size(), mp);
        return ans;
    }
};