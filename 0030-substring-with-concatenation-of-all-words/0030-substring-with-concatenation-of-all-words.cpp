class Solution {
public:
bool fun(string& s, vector<string>& words, unordered_map<string, int>& mp, int low, int high) {
  unordered_map<string, int> m;
  int i = low;
  int temp = words.size();
  while (temp--) {
    string t = s.substr(i, words[0].size());
    i += (words[0].size());
    m[t]++;
  }
  if (m == mp) {
    return true;
  }
  return false;
}
vector<int> findSubstring(string s, vector<string>& words) {
  unordered_map<string, int> mp;
  for (int i = 0; i < words.size(); i++) {
    mp[words[i]]++;
  }
  int concat_length = words.size() * words[0].size();
  if(s.size() < concat_length){
    return {};
  }
  int low = 0;
  int i = low;
  int high = concat_length - 1;
  vector<int> ans;
  bool checkAns = fun(s,words,mp,low,high);
  if(checkAns){
    ans.push_back(low);
  }

  while (high < s.size()) {
    low++;
    high++;
    if(high >= s.size()){
      break;
    }
    checkAns = fun(s,words,mp,low,high);
    if(checkAns){
      ans.push_back(low);
    }
    

  }
  return ans;
}
};