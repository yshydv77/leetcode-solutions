class Solution {
public:
vector<int> topKFrequent(vector<int>& nums, int k) {

    unordered_map<int,int>freq;  
    for(auto &it : nums){
        freq[it]++;
    }

    vector<int>ans;
    priority_queue<pair<int,int>>pq;

    for(auto &it : freq){
        pq.push({it.second , it.first});
    }

    while(pq.empty() == false && k--){
        ans.push_back(pq.top().second);
        pq.pop();
    }

    return ans;


}
};