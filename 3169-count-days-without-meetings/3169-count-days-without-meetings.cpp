class Solution {
public:
int countDays(int days, vector<vector<int>>& meetings) {
    
    // 2d array intervals meeting keyword dikh raha hai toh ye merge interval ka question hai 
    if (meetings.size() == 1) {
        return days - (meetings[0][1] - meetings[0][0] + 1);
    }

    sort(meetings.begin(), meetings.end());

    int meeting_days = 0 ;



    int start1 = meetings[0][0];
    int end1 = meetings[0][1];

    for(int i = 1 ; i < meetings.size() ;i++){
        int start2 = meetings[i][0];
        int end2 = meetings[i][1];
        if(end1 >= start2){
            //means meetings are overlaaping kar rahi hai toh mujhe isko merge karna hai
            start1 = start1;
            end1 = max(end1 , end2);
            continue;
        }
        else{
            meeting_days += (end1 - start1 + 1);
            start1 = start2;
            end1 = end2;
        }
    }
    
    meeting_days += (end1 - start1 + 1);


    return days - meeting_days;
}
};