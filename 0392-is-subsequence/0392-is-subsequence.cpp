class Solution {
public:
bool isSubsequence(string s, string t)
{
    // subsequence check karne ke liye bus do loop hi toh chalane hai 
    int i = 0 ;
    int j = 0;
    int siz_s = s.size();
    int siz_t = t.size();

    while(i<siz_s && j < siz_t){
        while(i < siz_s && s[i] == t[j]){
            i++;
            j++;
        }
        
        if(i >= siz_s){
            return true;
        }


        while(j < siz_t && s[i] != t[j]){
            j++;
        }

        if(j>=siz_t){
            break;
        }
        i++;
        j++;

    }

    if(i >= siz_s){
        return true;
    }

    return false;
}
};