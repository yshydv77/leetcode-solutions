class Solution {
public:
    int convertToMinute(string&time){
        int hr = stoi(time.substr(0,2));
        int min = stoi(time.substr(3,2));
        return (hr*60) + min;

    }
    int findMinDifference(vector<string>& timePoints) {
        vector<int>minutes;
        for(auto time : timePoints)
            minutes.push_back(convertToMinute(time));

        sort(minutes.begin() , minutes.end());
        int ans = INT_MAX;
        for(int i = 1 ; i < minutes.size() ;i++)
            ans =min(ans , minutes[i] - minutes[i-1]);
        
        int lastdiff = minutes[0] + 1440 - minutes.back();
        ans = min(ans , lastdiff);
        return ans;
    }
};