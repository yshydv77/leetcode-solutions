class Solution {
public:
    int totalFruit(vector<int> &fruits)
{
    int low = 0 ;
    int high = 0;
    unordered_map<int,int>freq;
    int maxLen = INT_MIN;
    for(high  = 0 ; high < fruits.size() ; high++){
        freq[fruits[high]]++;
        while(freq.size() > 2){
            freq[fruits[low]]--;
            if(freq[fruits[low]] == 0){
                freq.erase(fruits[low]);
            }
            low++;
        }
        int len = high - low +1;
        maxLen = max(maxLen , len);
    }

    return maxLen;
}

};