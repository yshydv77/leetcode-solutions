class RecentCounter {
  using ll = long long ;
public:
    queue<int>q;
    RecentCounter() {
    }
    
    int ping(int t) {
        ll low = t - 3000;
        ll high = t; 
        if(q.empty()){
          q.push(t);
          return 1;
        }
        else{
        while(!q.empty() && q.front() < low){
          q.pop();
        }
        q.push(t);
        return q.size();
        }
    }

};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */