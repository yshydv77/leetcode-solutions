class Solution {
public:
    string reverseWords(string s) {
        vector<string>store;
        string word = "";
        int i = 0 ;
        int n = s.size();
        while(i < n){
            while(i < n && s[i] == ' '){
                i++;
            }
            if(i==n){
                break;
            }

            while(i< n && s[i] != ' ' ){
                word.push_back(s[i]);
                i++;
            }
         

            store.push_back(word);
            word="";
            i++;
           
        }

        reverse(store.begin() , store.end());
        string ans = "";
        for(auto &&i : store){
            ans+=i;
            ans.push_back(' ');
        }
        ans.pop_back();
        return ans;
    }
};