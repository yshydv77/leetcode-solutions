class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int s = 0 ;
        int n = gain.size();
        vector<int>prefix(n+1);
        prefix[0] = 0;
        for(int i = 1 ; i < gain.size() ; i++){
          prefix[i] = prefix[i-1] + gain[i-1];
        } 
        prefix[n] = prefix[n-1] + gain[n-1];
        return *max_element(prefix.begin() , prefix.end());
        
    }
};