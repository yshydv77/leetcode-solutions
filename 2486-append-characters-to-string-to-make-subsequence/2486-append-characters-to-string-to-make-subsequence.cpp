class Solution {
public:
    int appendCharacters(string s, string t) {
        int low = 0 ;
        int high = 0 ;
        while(low < s.size() && high < t.size()){
            if(s[low] == t[high]){
                low++;
                high++;
            }
            else{
               low++;
            }
        }

        int ans = t.size() - high;
        if(t.empty() == true){ 
            // vo already ek subsequence tha
            return 0;
        }
        return ans;

    }
};