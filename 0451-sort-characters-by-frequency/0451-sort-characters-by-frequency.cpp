class Solution {
public:
string frequencySort(string s) {
    unordered_map<char,int>freq;
    for(auto &it : s){
        freq[it]++;
    }

    priority_queue<pair<int,char>>pq;
    for(auto &it : freq){
        pq.push({it.second , it.first});
    }

    string ans ="";
    while(pq.empty() == false){
        int times = pq.top().first;
        char ch = pq.top().second;
        while(times--){

            ans+=ch;
        }
        pq.pop();
    }
    return ans;
}
};