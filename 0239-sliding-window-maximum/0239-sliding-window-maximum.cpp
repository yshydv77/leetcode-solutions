class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
        vector<int>ans;
        deque<int>dq;

        // first window process ->> addition , answer storing 

        // addition ka logic for the first window 
        // jisme meine ye find out kiya ki har element ko toh insert karna hi hai 
        // and vo current element agar uske left side ke saare elements se baada aata
        // hai toh mujhe uske left side ke sare elements ko deque se pop kardena hai 
        for(int i = 0 ; i< k ; i++){

          while( !dq.empty() && arr[dq.back()]< arr[i]){
            dq.pop_back();
          }
          dq.push_back(i);
        }

        //answer storing logic for the first window 

        int element = arr[dq.front()];
        ans.push_back(element);

        // second window ki processing karni hai 

        for(int i = k ;i < arr.size() ; i++){
          //removal for the second window 
          if(!dq.empty() && i-dq.front() >= k){
            dq.pop_front();
          }
          //addition for the second window 
          while( !dq.empty() && arr[dq.back()]< arr[i]){
            dq.pop_back();
          }
          dq.push_back(i);

          // answer storing for the second window
          int element = arr[dq.front()];
          ans.push_back(element);
        }

    return ans;
    }
};