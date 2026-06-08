class Solution {
public:
int longestPalindrome(string s) {
  if (s.size() == 1) {
    return 1;
  }
  unordered_map<char,int>freq;
  for(int i = 0 ; i < s.size();i++){
    freq[s[i]]++;
  }

  int len = 0 ;
  bool odd = false;
  for(auto &it : freq){
    if(it.second % 2 == 0){
        len += it.second;
    }
    else{
        odd = true;
    }
  }

  if(odd == false){
    return len;
  }

  for(auto &it : freq){
    if(it.second % 2 == 1){
        len+= (it.second - 1);
    }
  }

  return len+1;

}
};