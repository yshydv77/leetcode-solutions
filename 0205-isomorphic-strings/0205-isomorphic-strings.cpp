class Solution {
public:
    string normaliser(string str){
        unordered_map<char,char>mp;
        char start = 'a';
        for(auto it : str){
            if(mp.find(it) == mp.end()){
                mp[it] = start ;
                start++;
            }
        }
        
        string normalisedString ="";
        for(int i = 0 ; i < str.size() ; i++){
            normalisedString.push_back(mp[str[i]]);
        }
        return normalisedString;
    }
    bool isIsomorphic(string s, string t) {
        string normalisedS = normaliser(s);
        string normalisedT = normaliser(t);
        if(normalisedS == normalisedT){
            return true;
        }
        return false;
    }
};