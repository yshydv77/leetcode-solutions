class Solution {
public:
    int vowelCount(string &s , int low , int high){
        int count = 0;

        for(int i = low ; i <= high ; i++){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
                count++;
            }
        }

        return count;
    }

    bool isVowel(char c){
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    int maxVowels(string s, int k) {

        int low = 0;
        int high = k - 1;

        int current_vowel_count;
        int max_vowel_count = 0;

        current_vowel_count = vowelCount(s, low, high);

        max_vowel_count = current_vowel_count;

        while(high < s.size() - 1){

            if(isVowel(s[low])){
                current_vowel_count--;
            }

            low++;
            high++;

            if(isVowel(s[high])){
                current_vowel_count++;
            }

            max_vowel_count = max(max_vowel_count, current_vowel_count);
        }

        return max_vowel_count;
    }
};