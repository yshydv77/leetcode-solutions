class Solution {
public:
    pair<int, int> countVowelCons(string& word) {
        int count_vowel = 0;
        int count_cons = 0;
        for (int i = 0; i < word.size(); i++) {
            char ch = word[i];
            if (isalpha(ch)) {

                ch = tolower(ch);
                if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' ||
                    ch == 'u') {
                    count_vowel++;
                }
                else{
                    count_cons++;
                }
            }
        }
        return {count_vowel , count_cons};
    }
    bool isValid(string word) {
        if (word.size() < 3)
            return false;
        bool valid = true;
        pair<int,int>p = countVowelCons(word);
        int vowel = p.first;
        int consonant = p.second;
        for (int i = 0; i < word.size(); i++) {
            if (!isalnum(word[i])) {
              return false;
            }
        }
        if(vowel<1)return false;
        if(consonant<1)return false;
        return true;
    }
};