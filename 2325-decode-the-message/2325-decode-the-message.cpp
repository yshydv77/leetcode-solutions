class Solution {
public:
    string decodeMessage(string key, string message) {
        unordered_map<char,char>mp;
        for(int i = 0 ; i < key.size() ; i++){
            if(key[i] != ' ' && mp.find(key[i])== mp.end()){
                mp[key[i]] = ('a' + mp.size() );
            }
        }
        string result = "";
        for(int i = 0 ; i < message.size() ; i++){
            if(message[i] == ' '){
                result.push_back(' ');
            }
            else{
                result.push_back(mp[message[i]]);
            }

        }
        return result;
    }
};