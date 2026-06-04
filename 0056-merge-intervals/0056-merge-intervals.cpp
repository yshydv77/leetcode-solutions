class Solution {
public:
vector<vector<int>> merge(vector<vector<int>> &intervals)
{   
    if(intervals.size() == 1){
        return intervals;
    }
    sort(intervals.begin() , intervals.end());

    int start1 = intervals[0][0]; 
    int end1 = intervals[0][1];
    vector<vector<int>>ans;
    for(int i = 1 ; i < intervals.size() ; i++){
        // merge kab hoga and kab nahi hoga
        int start2 = intervals[i][0]; 
        int end2 = intervals[i][1];
        if(end1 >= start2){
            // merge hoga
            start1 = start1;
            end1 = max(end1 , end2);
            continue;
        }
        else{
            // merge nahi karna hai but jo answer ban gaya hai usko store karna hai
            ans.push_back({start1 , end1});
            start1 = start2;
            end1 = end2;
        }
    }
    ans.push_back({start1 , end1}); 
    return ans;


}
};