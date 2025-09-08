class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int>ans;
        int i1 = 0;
        int i2 = 0;
        while(i1 < m && i2 < n){
            if(nums1[i1] < nums2[i2]){
                ans.push_back(nums1[i1]);
                i1++;
            }
            else if(nums1[i1] > nums2[i2]){
                ans.push_back(nums2[i2]);
                i2++;
            }
            else{
                // if both the elements are = 
                ans.push_back(nums1[i1]);
                ans.push_back(nums2[i2]);
                i1++;
                i2++;
            }
        }

        while(i1<m){
            ans.push_back(nums1[i1]);i1++;
        }
        while(i2 < n){
            ans.push_back(nums2[i2]);i2++;
        }

        for(int i = 0 ; i < ans.size() ; i++){
            nums1[i] = ans[i];
        }


    }
};