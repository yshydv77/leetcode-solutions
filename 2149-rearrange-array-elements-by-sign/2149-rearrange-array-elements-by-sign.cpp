class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>p;
        vector<int>n;
        vector<int>ans;
        for(auto &it : nums){
            if(it < 0 ){
                n.push_back(it);
            }
            else{
                p.push_back(it);
            }
        }
        int i = 0 ;
        int j = 0 ;
        int k = 0;
        while(j<p.size() && k <n.size()){
            nums[i] = p[j];
            j++;
            i++;
            nums[i]= n[k];
            k++;
            i++;
        }

        while(j<p.size()){
            nums[i]=p[j];
            j++;
            i++;
        }
        while(k<n.size()){
            nums[i]=n[k];
            k++;
            i++;
        }



        return nums;
    }
};