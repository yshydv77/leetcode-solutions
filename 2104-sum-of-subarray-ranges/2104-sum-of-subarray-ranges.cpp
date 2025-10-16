class Solution {
public:

    long long int subarrayMax(vector<int>&nums){

    }

    void nextSmallerElement(vector<int>&nums , vector<int>&next){

    }
    void prevSmallerElement(vector<int>&nums , vector<int>&prev){

    }

    long long int subarrayMin(vector<int>&nums){    
        vector<int>next(nums.size(), -1);
        vector<int>prev(nums.size(), -1);
    }
    long long subArrayRanges(vector<int>& nums) {
        auto smallest  = subarrayMin(nums);
        auto largest = subarrayMax(nums);
        return largest - smallest;
    }
};