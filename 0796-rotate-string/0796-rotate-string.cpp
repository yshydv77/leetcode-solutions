class Solution {
public:
    string rotate(string s , int k){
      int n = s.size();
      k = k % n ;
      if(k== 0){
        return s;
      }
      reverse(s.begin() , s.end());
      reverse(s.begin() , s.begin()+k);
      reverse(s.begin()+k , s.end());
      return s;
    }
    bool rotateString(string s, string goal) {
        if(s == goal){
          return true;
        }

        for(int i = 1 ; i < s.size() ; i++){
          string updated = rotate(s,i);
          if(updated == goal){
            return true;
          }
        }

        return false;

    }
};