class Solution {
public:
  int maxSubArray(vector<int> &nums)
{
    // array subarray best sum 
    // all int 
    // kadaens ka question hai 
    // sliding wndow fail here because negative elements are also here
    int bestending = nums[0];
    int ans = nums[0];
    for(int i = 1 ; i < nums.size() ; i++){
        // bestending ke liye do option hai 
        // opt1 -> prvious ke sath mil jao 
        //opt2 -> apna start karo i ko hi lo and i se start karo
        int opt1 = bestending + nums[i];
        int opt2 = nums[i];
        bestending = max(opt1 , opt2 );
        ans = max(ans , bestending);
    }

    return ans;
}
};