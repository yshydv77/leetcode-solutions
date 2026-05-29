class Solution {
public:
// lc567 permutation in the string
bool fun(vector<int>&s1_hashmap , vector<int>&s2_hashmap){
    for(int i = 0 ; i < 26 ; i++){
        if (s1_hashmap[i] != s2_hashmap[i])
        {
            return false;
        }
    }
    return true;
}
bool checkInclusion(string s1, string s2)
{
    // string substring check karna ka bol raha hai ki kay vo mera permutatiion ho sakta hai kya 
    // slindg window soch sakta hu 
    // s1 ka any permutation s2 ki substring ke andar present hai ki nahi vo return karna hai
    // fixed sized window hogi because permutatiion se wndow ki size par koi affect nahi hogi 
    int m = s1.size();
    int n = s2.size();
    if(n<m){
        return false;
    }

    int k = m;//window size
    vector<int>s1_hashmap(26);
    vector<int>s2_hashmap(26);
    for(int i = 0 ; i < s1.size() ; i++){
        s1_hashmap[s1[i]-'a']++;
    }
    bool flag = false;
    int low = 0 ;
    int high = k-1;
    for(int i = 0 ; i <= high  ; i++){
        s2_hashmap[s2[i]-'a']++;
    }
    if(fun(s1_hashmap ,s2_hashmap)){
        flag = true;
        return flag;
    }

    while(high < n){
        s2_hashmap[s2[low]-'a']--;
        low++;
        high++;
        if(high == n){
            break;
        }
        s2_hashmap[s2[high]-'a']++;
        if(fun(s1_hashmap , s2_hashmap)){
            flag = true;
        }
    }

    return flag;

}

};