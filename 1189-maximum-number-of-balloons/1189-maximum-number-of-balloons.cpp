class Solution {
public:
int maxNumberOfBalloons(string text) {
    unordered_map<char,int>freq_balloon;
    freq_balloon['b'] = 1;
    freq_balloon['a'] = 1;
    freq_balloon['l'] = 2;
    freq_balloon['o'] = 2;
    freq_balloon['n'] = 1;
    unordered_map<char,int>freq_text;
    for(int i = 0 ; i < text.size() ; i++){
        freq_text[text[i]]++;
    }
    vector<int>times;
    int count = INT_MAX;
    times.push_back(freq_text['b']/freq_balloon['b']);
    times.push_back(freq_text['a']/freq_balloon['a']);
    times.push_back(freq_text['l']/freq_balloon['l']);
    times.push_back(freq_text['o']/freq_balloon['o']);
    times.push_back(freq_text['n']/freq_balloon['n']);

    for(int i = 0 ; i < times.size() ; i++){
        count = min(count , times[i]);
    }
    return count;
}
};