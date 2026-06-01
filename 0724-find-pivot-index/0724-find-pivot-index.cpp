class Solution {
public:
    
int pivotIndex(vector<int> &nums)
{   
    int n = nums.size();
    vector<int>prefix(n);
    vector<int>suffix(n);

    for(int i = 1 ; i < n ; i++){
        prefix[i] = prefix[i-1] + nums[i-1];
    }

    for(int i = n-2;i>=0;i--){
        suffix[i] = suffix[i+1] + nums[i+1];
    }

    int index = -1;
    for(int i = 0 ; i < n ; i++){
        if(prefix[i] == suffix[i]){
            index = i;
            break;
        }
    }

    return index;
    
}
};