class Solution {
public:
    void merge(vector<int>& n1, int m, vector<int>& n2, int n) {

       
        int i = m-1,
            j = n-1, 
            k = n1.size()-1;

        
        while(i >=0 && j >= 0){
            if(n1[i] > n2[j]){
                n1[k] = n1[i];
                i--;
                k--;
            }
            else if(n1[i] == n2[j]){
                n1[k] = n2[j];
                j--;
                k--;
            }
            else{
                n1[k] = n2[j];
                j--;
                k--;
            }
        }



        while(i >= 0){
            n1[k] = n1[i];
            k-- ;
            i--; 
        }

        while(j >= 0){
            n1[k] = n2[j];
            j--;
            k--;
        }





























        // vector<int>ans;
        // int i1 = 0;
        // int i2 = 0;
        // while(i1 < m && i2 < n){
        //     if(nums1[i1] < nums2[i2]){
        //         ans.push_back(nums1[i1]);
        //         i1++;
        //     }
        //     else if(nums1[i1] > nums2[i2]){
        //         ans.push_back(nums2[i2]);
        //         i2++;
        //     }
        //     else{
        //         // if both the elements are = 
        //         ans.push_back(nums1[i1]);
        //         ans.push_back(nums2[i2]);
        //         i1++;
        //         i2++;
        //     }
        // }

        // while(i1<m){
        //     ans.push_back(nums1[i1]);i1++;
        // }
        // while(i2 < n){
        //     ans.push_back(nums2[i2]);i2++;
        // }

        // for(int i = 0 ; i < ans.size() ; i++){
        //     nums1[i] = ans[i];
        // }


    }
};