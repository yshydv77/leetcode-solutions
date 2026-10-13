class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        vector<long long>a;
        for(auto &i : nums){
            a.push_back(i*i*1LL);
        }

        sort(a.begin() , a.end());
        int n = a.size();
        return -accumulate(a.begin() , a.begin() + n/2 , 0LL) + accumulate(a.begin()+n/2 , a.end(),0LL);

    }

};