class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()){
            return false;
        }
        vector<int>s_hashmap(26);
        vector<int>t_hashmap(26);
        for(int i = 0 ; i < s.size() ; i++){
            s_hashmap[s[i]-'a']++;
        }

        for(int i = 0 ; i < t.size() ; i++){
            t_hashmap[t[i]-'a']++;
        }

        for(int i = 0 ; i < 26;i++){
            if(s_hashmap[i] != t_hashmap[i]){
                return false;
            }
        }

        return true;
    }
};