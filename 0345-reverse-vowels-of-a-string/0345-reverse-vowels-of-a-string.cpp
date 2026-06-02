class Solution {
public:
bool isVowel(char ch)
{
    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
    {
        return true;
    }
    return false;
}
string reverseVowels(string s)
{
    int low = 0;
    int high = s.size() - 1;
    while (low < high)
    {
        bool ch_low = isVowel(s[low]);
        bool ch_high = isVowel(s[high]);

        if (ch_low == true && ch_high == true)
        {
            swap(s[low], s[high]);
            low++;
            high--;
        }
        else if (ch_low == false &&ch_high == true)
        {
            low++;
        }
        else if (ch_low == true && ch_high == false)
        {
            high--;
        }
        else{
            low++;
            high--;
        }
            
    }
    return s;
}
};