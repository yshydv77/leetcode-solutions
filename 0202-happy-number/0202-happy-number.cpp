class Solution {
public:
int sqOfDigits(int n){
    int sum = 0 ;
    while(n != 0){
        int digit = n % 10;
        sum += (digit * digit);
        n = n / 10;
    }

    return sum;
}
bool isHappy(int n)
{
    // single number cycle 
    // slow and fast pointer lagate hai 
    int slow = n;
    int fast = n;
    while(fast != 1){
        slow = sqOfDigits(slow);
        fast = sqOfDigits(fast);
        fast = sqOfDigits(fast);

        if(slow == fast && fast != 1){
            return false;
        }
    }
    return true;
}

};