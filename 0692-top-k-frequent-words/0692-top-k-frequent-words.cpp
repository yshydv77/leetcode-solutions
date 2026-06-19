class Solution {
public:
    struct cmp {
        bool operator()(pair<int, string>& a, pair<int, string>& b) {
            if (a.first != b.first) {
                return a.first > b.first;
            }

            return a.second < b.second;
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        // top k frequent element pucha hai
        // min heap ka use karte hai
        priority_queue<pair<int, string>, vector<pair<int, string>>, cmp> pq;
        unordered_map<string, int> freq;

        for (auto& word : words) {
            freq[word]++;
        }

        for (auto& it : freq) {
            pair<string, int> p = it;
            if (pq.size() < k) {
                pq.push({p.second, p.first});
            } else {
                pq.push({p.second , p.first});
                pq.pop();
            }
        }
        if(k == 1){
          return {pq.top().second};
        }
        vector<string> ans;
        while (!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};