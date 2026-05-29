class Solution {
public:
    bool containsDuplicate(vector<int> &nums)
{
    unordered_map<int,int>frq;
    for(int i = 0 ; i < nums.size() ; i++){
        frq[nums[i]]++;
    }

    if(frq.size() == nums.size()){
        return false;
    }
    return true;
}
};