using ll = long long;
class Solution {
public:

    bool isPalindrome(int x) {
        ll num = x;
        bool neg = (x<0);
        if(neg) return false;
        ll rev = 0;
        while(num!=0){
            ll  digit = num % 10;
            rev = rev * 10 + digit;
            num/=10;
        }
       return (x==rev);
    }
};