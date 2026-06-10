class Solution {
public:
int firstMissingPositive(vector<int>& nums) {
    int ans = 1;
    unordered_map<int,int>freq;
    for(int i = 0 ; i < nums.size() ; i++){
        if(nums[i] <= 0){
            continue;
        } 
        else{
            // vo kya hai vo positvie integer hai
            freq[nums[i]]++;
        }
    }

    while(true){
        if(freq.find(ans) == freq.end()){
            // iska matlab vo element nahi aaya hai and vahi merea first missing positive elemetn hai 
            return ans;
        }
        else{
            ans++;
        }
    }


    return -1;

}
};