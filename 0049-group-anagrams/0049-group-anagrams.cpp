class Solution {
public:

    vector<vector<string>> groupAnagrams(vector<string>& st) {
        if(st.size() == 0 ){
            return {{}};
        }
        if(st.size() == 1){
            return {{st}};
        }
        vector<vector<string>>ans;
        vector<int>hashmap(26);
        unordered_map<string,vector<string>>mp;
        for(int i = 0 ; i < st.size() ; i++){
            string curr = st[i];
            for(int i = 0 ; i < curr.size(); i++){
                hashmap[curr[i]-'a']++;
            }
            string build = "";
            for(int i = 0 ; i < 26 ; i++){
                while(hashmap[i] != 0 ){
                    build.push_back(i+'a');
                    hashmap[i]--;
                }
            }
            mp[build].push_back(curr);
        }

        for(auto it : mp){
            ans.push_back(it.second);
        }

        return ans;

    }
};