class Solution {
public:
int lengthOfLastWord(string s)
{
    int i = 0;
    int n = s.size();
    vector<string> a;
    string word = "";
    while (i < n)
    {
        while (i < n && s[i] == ' ')
        {
            i++;
        }

        if (i >= n)
        {
            break;
        }
        while (i < n && s[i] != ' ')
        {
            word += s[i];
            i++;
        }
        a.push_back(word);
        word = "";
        i++;
    }
    if(a.empty()){
        return 0;
    }
    return a.back().size();
}
};