class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int pickP = 0;
        int pickM = 0;
        int pickG = 0 ;
        int lastHouseP = 0;
        int lastHouseM = 0;
        int lastHouseG = 0;

        for(int i = 0 ;i < garbage.size() ; i++){
            string currGarbage = garbage[i];
            for(int j = 0 ; j < currGarbage.size() ; j++){
                char garbageType = currGarbage[j];
                if(garbageType == 'P'){
                    pickP++;
                    lastHouseP = i;
                }
                else if(garbageType == 'M'){
                    pickM++;
                    lastHouseM = i;
                }
                else if(garbageType == 'G'){
                    pickG++;
                    lastHouseG = i;
                } 
            }
        }
        int travelP = 0;
        int travelM = 0;
        int travelG = 0;
        for(int i = 0 ;i < lastHouseP ; i++){
            travelP += travel[i];
        }
        for(int i = 0 ;i < lastHouseM ; i++){
            travelM += travel[i];
        }
        for(int i = 0 ;i < lastHouseG ; i++){
            travelG += travel[i];
        }

        return (pickP + pickM + pickG) + (travelP +travelM +travelG);
    }
};