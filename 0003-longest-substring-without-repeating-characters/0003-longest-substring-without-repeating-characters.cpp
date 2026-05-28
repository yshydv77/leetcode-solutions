class Solution {
public:
    int lengthOfLongestSubstring(string s)
{
    // string substring longest -> sliding window ka question ho sakta hai 
    // sliding window se sochna strat karte hai 
    // variable sizd window hai 
   
    int low = 0;
    int high =  0;

    int maxLen = 0;
    unordered_map<char,int>freq;
    for(high = 0 ; high < s.size() ; high++){
        freq[s[high]]++;
        int len = high - low +1;
        while(freq.size() <  len){
            freq[s[low]]--;
            if(freq[s[low]] == 0 ){
                freq.erase(s[low]);
            }
            low++;
            len = high - low + 1;
        }
        maxLen = max(maxLen , len);
        
    }

    return maxLen;
}

};