class Solution {
public:
    string customSortString(string order, string s) {
        // another method for this question easy to implement use the lambda method in sort functino 
        sort(s.begin() , s.end() . [&](char ch1 , char ch2 ){
               return (order.find(ch1) < order.find(ch2)); 
        });

        //if you want to sort the particular stirng based on the custom logic then u can use the sort functionality and pass the lambda funcitno  

        // another method to solve this question but it is very long 
        
        
        string result= "";
        unordered_map<char,int>mp;
        for(int i = 0 ; i < s.size() ; i++){
            mp[s[i]]++;
        }
        for(int i = 0 ; i < order.size() ; i++){
            char ch = order[i];
            auto findChInMp = mp.find(ch);
            if(findChInMp != mp.end()){
                // then the element is present in the s string
                auto k = findChInMp->second;
                if( k > 1){
                   while(k--){
                    result.push_back(findChInMp->first);
                   }
                }
                else{
                    result.push_back(findChInMp->first);
                }
            }

        }
        for(int i = 0 ; i < s.size() ; i++){
            char ch = s[i];
            int findChInResult = result.find(ch);
            if(findChInResult  == -1){
                auto k = mp[ch];
                while(k--){
                    result.push_back(ch);
                }
            }
        }
        return result;
    }
};
