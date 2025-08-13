class Solution {
public:
    string reorganizeString(string s) {
        int map[256] = {0};
        for (int i = 0; i < s.size(); i++) {
            // frequency updation of the elemetns of the string
            map[s[i]]++;
        }

        char max_freq_char;
        int max_freq = INT_MIN;
        for (int i = 'a'; i <= 'z'; i++) {
            if (max_freq < map[i]) {
                max_freq = map[i];
                max_freq_char = i;
            }
        }

        // check that it is possible to reorganise the string or not
        if (max_freq > (s.size() + 1) / 2) {
            return "";
        }

        int index = 0;

        while (max_freq-- && index < s.size()) {
            s[index] = max_freq_char;
            index += 2;
        }

        // now for the maxfreq character uski freq in the map zero kardo
        map[max_freq_char] = 0;


        // rest element ko fill karna hai 
        for(int i = 'a' ; i<= 'z' ; i++){
            while(map[i] > 0){
                index = index >= s.size() ? 1 : index;
                s[index] = i ;
                map[i]--;
                index += 2;
            }
                

        }
        return s;
    }
};