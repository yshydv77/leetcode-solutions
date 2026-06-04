class Solution {
public:
int findMaxLength(vector<int> &nums)
{
    int cnt_zero = 0 ;
    int cnt_one = 0;
    unordered_map<int,int>index;
    int res = 0;
    for(int i = 0 ; i < nums.size() ;i++){
        if(nums[i] == 0 ){
            cnt_zero++;
        }
        else{
            cnt_one++;
        }
        int diff = cnt_zero - cnt_one;
        if (diff == 0)
        {
            res = max(res, i + 1);
            continue;
        }
        if (index.find(diff) != index.end())
        {
            res = max(res, i - index[diff]);
        }
        else
        {
            index[diff] = i;
        }
    }
    return res;
}
};