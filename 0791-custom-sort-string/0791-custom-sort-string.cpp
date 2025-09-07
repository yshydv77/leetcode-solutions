class Solution {
public:
    string customSortString(string order, string s) {
        vector<int>rank(26 , INT_MAX);
        for(int i = 0 ; i < order.size() ; i++){
            rank[order[i]-'a'] = i;
        }
        sort(s.begin() , s.end() , [&](char ch1 , char ch2 ){
            return( rank[ch1-'a']  < rank[ch2 -'a']);
        });
        return s;
    }
};