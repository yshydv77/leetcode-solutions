class Solution {
public:
    int compress(vector<char> &chars)
{
    int low = 0 ;
    int high = 0 ;

    int n = chars.size();

    while(high < n){
        char curr_char = chars[high];
        int count = 0 ;
        while(high < n && chars[high] == curr_char){
            count++;
            high++;
        }

        chars[low] = curr_char;
        low++;
        if(count>1){
            string count_str = to_string(count);
            for(auto &it : count_str){
                chars[low] = it;
                low++;
            }
        }
    }

    return low;
}
};