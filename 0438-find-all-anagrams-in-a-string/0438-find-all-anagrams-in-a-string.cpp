class Solution {
public:
    //lc 438 find all angarams
bool fun(vector<int> &s_hashmap, vector<int> &p_hashmap){
    for(int i = 0 ; i < 26 ; i++){
        if(s_hashmap[i] != p_hashmap[i]){
            return false;
        }
    }

    return true;
}
    vector<int> findAnagrams(string s, string p)
{
    // string substring haa but anagram bhi mostly sunstring type se hi hojayegi 
    // fixed window because p and s ki size same ho ni chaihiye 
    vector<int>ans;
    vector<int>s_hashmap(26);
    vector<int>p_hashmap(26);
    int m = s.size();
    int n = p.size();
    if(m<n){return {};}
    for(int i = 0 ; i < n ; i++){
        p_hashmap[p[i]-'a']++;
    }

    int k = n;//window size because we have to return the starting index of the anagram 
    int low = 0 ;
    int high = k-1;
    for(int i = 0 ; i <= high ; i++){
        s_hashmap[s[i]-'a']++;
    }
    if(fun(s_hashmap , p_hashmap)){
        ans.push_back(low);
    }

    while(high < m){
        s_hashmap[s[low]-'a']--;
        low++;
        high++;
        if(high == m){
            break;
        }
        s_hashmap[s[high]-'a']++;
        if(fun(s_hashmap , p_hashmap)){
            ans.push_back(low);
        }
    }

    return ans;
}
};