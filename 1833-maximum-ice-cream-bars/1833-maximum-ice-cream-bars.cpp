class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int sum = 0;
        int cnt = 0;
        sort(costs.begin() , costs.end());
        for(int i = 0 ; i < costs.size() ; i++){
            
            if(sum+costs[i] <= coins){
                cnt++;
                sum+=costs[i];
            }
            else{
                break;
            }
        }

        if(sum > coins){
            return 0;
        }
        return cnt;
    }
};