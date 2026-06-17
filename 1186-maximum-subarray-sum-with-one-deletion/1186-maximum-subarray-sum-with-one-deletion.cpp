class Solution {
  using ll = long long;
public:
    int maximumSum(vector<int>& arr) {
        int res = arr[0];
        int power = INT_MIN;
        int nopower = arr[0];

        for(int i = 1 ; i < arr.size() ; i++){
          // v1 and v2 are the choices for the nopower selection 
          int v1 = arr[i];
          int v2 = nopower + arr[i];
          // v3 and v4 are the choices for the power selection 
          // power matlab ki hum one deletion perfrom yaa toh kar chuke hai yaa phir karnege

          int v3 = power == INT_MIN ?  arr[i] : power + arr[i];
          int v4 = nopower;
          res = max({res , v1, v2 , v3 , v4});
          nopower = max({v1 , v2});
          power = max({v3 , v4});
        }
        return res;
        // int noDelete = arr[0];
        // int oneDelete = INT_MIN;
        // int ans = arr[0];

        // for(int i =1 ; i < arr.size() ; i++){
        //     int prev_noDelete = noDelete;
        //     int prev_oneDelete = oneDelete;
        //     noDelete = max({prev_noDelete+arr[i] , arr[i]});
        //     //ith element ko delete nahi kar rahe hai kyuki 0 to i-1 tak ke
        //     elements mein se ek delete ho chuka hai
        //     // oneDelete ka matlab hai mujhe ek delete karvana hai
        //     // ya toh mein ith element delete karunga toh mera ek delete ho
        //     jayega yaa phir mein ith element ko delete na karu aage kisi
        //     element ko delete karu
        //     // oneDelete = noDelete; // agar arr[i] ko delete karna chahte
        //     hai toh
        //     // oneDelete = oneDelete + arr[i]; // phele koi delete ho chuka
        //     ho toh arr[i] ko onedelete mein milna hi padega

        //     if(prev_oneDelete == INT_MIN){
        //         prev_oneDelete = arr[i];
        //     }
        //     else{
        //         prev_oneDelete = prev_oneDelete + arr[i];
        //     }
        //     oneDelete = max({prev_noDelete , prev_oneDelete});
        //     ans = max({ans , noDelete , oneDelete});
        //     prev_oneDelete = oneDelete;
        //     prev_noDelete = noDelete;
        // }
        // return ans;
    }
};