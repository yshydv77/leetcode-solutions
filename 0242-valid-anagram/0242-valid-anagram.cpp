class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int>visited(26,0);
        for(auto it : s){
            visited[it-'a']++;
        }

        for(auto it : t){
            visited[it-'a']--;
        }
        for(auto it : visited){
            if(it > 0){
                return false;
            }
        }

        // agar mein 18 line par agaaya iska mtlb mere valid anagram hai
        return true;
    }
};