class Solution {
public:
int pivotIndex(vector<int> &nums)
{   
    //approach 2 

    int left = 0 ;
    int right = 0;
    int n = nums.size();
    int index = -1;
    int sum = accumulate(nums.begin() , nums.end() , 0);
    int i = 0;
    if(i == 0){
        left = 0;
        right = sum - nums[0];
        if(left == right){
            return i;
        }
        i++;
    }
    if(i>=1 && i<=n-2){

    for(i = 1 ; i <= n-2; i++){
        left+=nums[i-1];//prefix nikalte jayega 
        //because ith index se phele jitne bhi index the unka sum left store karte jayega and ith index se phele vala sum batayega
        right = sum - left - nums[i];

        if(left == right){
            index=i;
            break;
        }

    }
    }

    if(i==n-1){
        left = sum - nums[n-1];
        right = 0;
        if(left == right){
            return i;
        }
    }
    
    return index;



    // approach 1 
    // int n = nums.size();
    // vector<int>prefix(n);
    // vector<int>suffix(n);

    // for(int i = 1 ; i < n ; i++){
    //     prefix[i] = prefix[i-1] + nums[i-1];
    // }

    // for(int i = n-2;i>=0;i--){
    //     suffix[i] = suffix[i+1] + nums[i+1];
    // }

    // int index = -1;
    // for(int i = 0 ; i < n ; i++){
    //     if(prefix[i] == suffix[i]){
    //         index = i;
    //     }
    // }

    // return index;
    
}
};