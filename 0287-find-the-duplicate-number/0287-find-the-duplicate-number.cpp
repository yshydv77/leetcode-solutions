class Solution {
public:
    int findDuplicate(vector<int> &a)
{
    // array isme jab graph bnaya toh pta chala ki cucle hai isme toh 
    // cycle ke starting point par jo bhi number hai vahi repeat hoga
    // slow and fast pointer ka question hai 
    int slow = 0;
    int fast = 0 ;
    while(true){// because it is definite that it contains the cycle 
        slow = a[slow];
        fast = a[fast];
        fast = a[fast];

        if(slow == fast){
            // cycle hai and we are the meeting point 
            slow = 0;
            while(slow != fast){
                slow = a[slow];
                fast = a[fast];
            }

            return slow;
        }
    }

    return -1;
}

};