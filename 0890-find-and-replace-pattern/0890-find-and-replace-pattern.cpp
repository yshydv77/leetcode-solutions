class Solution {
public:
    string normaliser(string s){
        char start = 'a';
        unordered_map<char , char>mp;
        for(int i = 0 ; i < s.size() ; i++){
            if(mp.find(s[i]) == mp.end()){
                mp[s[i]] = start;
                start++;
            }
        }
        string result = "";
        for(int i = 0 ; i< s.size() ; i++){
            result+=mp[s[i]];
        }
        return result;

    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
       
        string normalisedPattern = normaliser(pattern);
        vector<string>normalisedWords;
        vector<string>ans;
        for(int i = 0 ;i < words.size() ; i++){
            string word = words[i];
            string normalisedWord = normaliser(word);
            normalisedWords.push_back(normalisedWord);
        }
        for(int i = 0 ;i < normalisedWords.size() ; i++){
            string normalisedWord = normalisedWords[i];
            if(normalisedWord == normalisedPattern){
                ans.push_back(words[i]);
            }
        }
        return ans;
    }   
};