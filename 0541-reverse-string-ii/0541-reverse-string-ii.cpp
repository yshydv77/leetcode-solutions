class Solution {
public:
    void reverseMe(string &s, int k, int low, int high)
{
    reverse(s.begin()+low , s.begin() + low +  k);
}
string reverseStr(string s, int k)
{
    int n = s.size();
    if(n==1)return s;
    int twoK = 2 * k;
    int possibleGroup = n / twoK;
    int remainingLetters = n % twoK;
    
    int low = 0;
    int high = twoK - 1;

    while(possibleGroup--){
        reverseMe(s,k,low,high);
        low+=twoK;
        high+=twoK;
    }
    // high gets out of bound now 
    high = n-1;
    int diff = high - low + 1;
    if(diff < k){
        reverse(s.begin() + low , s.end());
    }
    else if(k<=diff && diff < twoK){
        reverseMe(s,k,low,high);
    }
 
    return s;
}
};