class Solution {
public:
// fixed sliding window question
int maxScore(vector<int>& cardPoints, int k) {
    int low = 0 ;
    int high = k-1 ;
    int sum = 0 ;
    int maxSum = INT_MIN;
    int n = cardPoints.size();
    int lsum = 0 ;
    int rsum = 0 ;

    for(int i = 0 ; i < k ; i++){
        lsum += cardPoints[i];
    }

    



    int li = 0;
    int lj = k-1;
    int ri = n-k;
    int rj = n-1;
    sum = (lsum + rsum);
    maxSum = max(maxSum , sum);
    while(rj>=ri && lj >=li){
        lsum -= cardPoints[lj];
        lj--;
        rsum += cardPoints[rj];
        rj--;
        sum = lsum + rsum;
        maxSum = max(maxSum , sum);
    }

    return maxSum;


}
};