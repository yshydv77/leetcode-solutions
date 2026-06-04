class Solution {
public:
vector<vector<int>> intervalIntersection(vector<vector<int>> &firstList, vector<vector<int>> &secondList)
{
    if(firstList.size() == 0 || secondList.size() == 0 ){
        return {};
    }

    // array sorted merge overlapping intersection nikalo
    // two pointer tech

    int i = 0 ;
    int j = 0 ;
    vector<vector<int>>ans;
    while(i<firstList.size() && j < secondList.size())  {
        int start1 = firstList[i][0];
        int end1 = firstList[i][1];
        int start2 = secondList[j][0];
        int end2 = secondList[j][1];

        // check karna hai ki konsa pair phele le 
        // taki hum overlapping nikal sake

        if(start1 <= start2){
            // first pair ko phele lo and ab overlapping check karo ki exist karti hai yaa nahi because if not exist then koi matlab nahi hai iss pair ka
            if(end1 >= start2){
                //overlapping kar rahi hai because end1 start2 se bada and equal hai 
                // s and e are the start and end index of the intersection
                int s = max(start1 , start2);
                int e = min(end1 , end2);
                // find out the intersection pont s and e 
                ans.push_back({s,e});
            }
        }
        else{
            if(end2 >= start1){
                // overlapping kar rahi hai because end1 start2 se bada and equal hai
                //  s and e are the start and end index of the intersection
                int s = max(start1, start2);
                int e = min(end1, end2);
                // find out the intersection pont s and e
                ans.push_back({s, e});
            }
        }

        if(end2<= end1){
            j++;
        }
        else{
            i++;
        }

    }

    return ans;

}

};