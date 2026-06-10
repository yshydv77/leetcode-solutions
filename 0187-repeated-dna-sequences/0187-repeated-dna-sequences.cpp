class Solution {
public:
vector<string> findRepeatedDnaSequences(string s) {
  unordered_map<string,int>freq;
  for(int i = 0 ; i <  s.size() ; i++){
    if(i+10 <= s.size()){
      string temp = s.substr(i, 10);
      freq[temp]++;
    }
  }
    vector<string>ans;
    for(auto &it : freq){
        if(it.second > 1){
            ans.push_back(it.first);
        }
    }
  return ans;
}
};