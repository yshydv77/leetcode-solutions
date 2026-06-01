class Solution {
public:
    
int subarraySum(vector<int> &nums, int k)
{
    unordered_map<int,int>freq;
    int sum = 0 ;
    freq[0] = 1;
    int count = 0 ;
    for(int i = 0; i < nums.size() ;i++){
        sum+=nums[i];
        int ques = sum - k;
        if(freq.find(ques) != freq.end()){
            count+=freq[ques];
        }
        freq[sum]++;
    }

    return count;
}

};