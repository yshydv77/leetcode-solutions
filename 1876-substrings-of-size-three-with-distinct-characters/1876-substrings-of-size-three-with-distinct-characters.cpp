class Solution {
public:
    int countGoodSubstrings(string s)
{   
    // string substring count 
    // fixed sized sliding window ka questino ba gaya hai
    int k = 3;
    int low = 0 ;
    int high = k-1;
    int count = 0 ;
    unordered_map<char,int>freq;
    for(int i = 0 ; i <= high ; i++){
        freq[s[i]]++;
    }
    if(freq.size() == k){
        count++;
    }

    while(high < s.size()){
        freq[s[low]]--;
        if(freq[s[low]] == 0 ){
            freq.erase(s[low]);
        }
        low++;
        high++;
        freq[s[high]]++;
        if(high == s.size()){
            break;
        }

        if(freq.size() == k){
            count++;
        }
    }

    return count;

}
};