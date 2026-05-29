class Solution {
public:
vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    if(k == 1){
        return nums;
    }

    int low = 0;
    int high = k-1;
    deque<int>dq;
    vector<int>ans;
    for(int i = 0 ; i <= high ; i++){
        while(!dq.empty() && nums[dq.back()] <= nums[i]){
            dq.pop_back();
        }
        dq.push_back(i);
    }
    ans.push_back(nums[dq.front()]);

    while(high < nums.size()){
        low++;
        high++;
        if(high == nums.size()){
            break;
        }   

        while(!dq.empty() && dq.front() < low ){
            dq.pop_front();
        }

        while(!dq.empty() && nums[dq.back()] <= nums[high]){
            dq.pop_back();
        }

        dq.push_back(high);
        ans.push_back(nums[dq.front()]);
    }


    return ans;

    
}
};