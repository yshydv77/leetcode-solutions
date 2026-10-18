class Solution {
public:
void fun(vector<int>& candidates , int target , int i , vector<int>ds , vector<vector<int>>&ans){
    if(target == 0 ){
        ans.push_back(ds);
        return ;
    }

    for(int j = i ; j < candidates.size() ; j++){
        if(j > i && candidates[j] == candidates[j-1] ) continue;
        if(candidates[j] > target) break;

        ds.push_back(candidates[j]);
        fun(candidates,target-candidates[j] , j+1,ds,ans);
        ds.pop_back();
    }
}
vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<vector<int>>ans;
    int i = 0  ;
    vector<int>ds;
    sort(candidates.begin() , candidates.end());
    fun(candidates,target,i,ds,ans);
    return ans;
}
};