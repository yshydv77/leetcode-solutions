class Solution {
public:
    int maxArea(vector<int>& height) {
       int low = 0 ;
       int high = height.size()-1;
       int area = INT_MIN;
       while(low<high){
        int h = min(height[low] , height[high ]);
        int w = high - low;
        int a = h * w;
        area = max(area,a);
        if(height[low] < height[high]){
            low++;
        }
        else{
            high--;
        }
       }

       return area;
    }
};