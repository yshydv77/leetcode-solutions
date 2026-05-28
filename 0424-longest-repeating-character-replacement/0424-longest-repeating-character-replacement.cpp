class Solution {
public:
    int maxFreqFinder(vector<int>&freq){
    int maxi = INT_MIN;
    for(int i = 0 ; i < freq.size() ; i++){
        maxi = max(maxi , freq[i]);
    }

    return maxi;
}
int characterReplacement(string s, int k)
{
    // string longest substring nikalni hai jisme same repeating character ho 
    // variable sized window 
    int low = 0 ;
    int high = 0;
    int maxLen = INT_MIN;
    vector<int>freq(26);

    for(high = 0 ; high < s.size() ; high ++){
        freq[s[high] - 'A']++;
        int len = high - low +1;
        int maxi = maxFreqFinder(freq);
        int diff = len  - maxi;
        while(diff > k ){
            freq[s[low]-'A']--;
            low++;
            len = high - low +1;
            maxi = maxFreqFinder(freq);
            diff = len - maxi;
        }

        len = high - low +1 ;
        maxLen = max(maxLen , len);
    }

    return maxLen;
}
};