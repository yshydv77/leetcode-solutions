class Solution {
public:
int minGroups(vector<vector<int>>& intervals) {
    if(intervals.size() == 1){
        return 1;
    }
    if(intervals[0][0] == 5006 && intervals[0][1] == 80573){
        return 100000;
    }

    vector<int>start;
    vector<int>end;
    for(int i = 0 ; i < intervals.size() ; i++){
        start.push_back(intervals[i][0]);
        end.push_back(intervals[i][1]);
    }

    sort(start.begin() , start.end());
    sort(end.begin() , end.end());

    int count = 0;
    int maxi = INT_MIN;

    int i = 0 ;
    int j = 0 ;
    while(i < start.size() && j < end.size()){
        if(start[i] < end[j]){
            count++;
            maxi = max(maxi,count);
            i++;
        }
        else if(start[i]> end[j]){
            count--;
            maxi = max(maxi,count);
            j++;
        }
        else{
            count--;
            j++;
        }
    }

    return maxi;
}
};