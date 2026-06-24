class Solution {
public:
    int countBinarySubstrings(string s) {
       int n = s.size();
       if(n == 1){
        return 0;
       }
       vector<int>cnt;
        int low = 0;
        int high = 1;
        while(high < n){
            if(s[low] == s[high]){
                high++;
            }
            else{
                cnt.push_back(high-low);
                low = high;
                high++;
            }

        }

        cnt.push_back(high-low);

        int sum = 0 ;
        if(cnt.size() == 1){
            return 0;
        }

        for(int i = 1 ; i < cnt.size() ; i++){
            int one = cnt[i-1];
            int two = cnt[i];
            int mini = min(one,two);
            sum+=mini;
        }
        return sum;
    }
};