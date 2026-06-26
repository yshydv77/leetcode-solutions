class Solution {
public:
long long minimumSteps(string s)
{
    long long n = s.size();
    if(n==1){
        return 0;
    }
    long long count = 0 ;

    // two adjacent balls ko hi choose kar sakte hai and unhi ko swap kar sakte hai 
    long long cnt0 = 0 ;
    for(int i = n-1; i >=0 ; i--){
        if(s[i] == '0'){
            cnt0++;
        }
        else if(s[i] == '1'){
            count+=cnt0;
        }
    }
    return count;
    
}
};