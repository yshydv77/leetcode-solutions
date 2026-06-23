class Solution {
public:
void fun(int n , int open , int close , string &temp , vector<string>&ans){
  // agar mera open and close n ke equal ho jaye iska matlab ye hai ki mera formation total complete ho gaya hia
  if(open == n && close == n){
    ans.push_back(temp);
    return;
  }

  if(open < n){ // open<n means open wala explore kar rahe hai 
    temp.push_back('(');
    // next formation ke liye open+1 karke aage explore karenge
    fun(n, open+1 , close , temp, ans);
    // yaha aane par vapis backtrack karna padega
    temp.pop_back();
  }

  if(close < open){
    temp.push_back(')');
    fun(n,open , close+1 , temp,ans);
    temp.pop_back();
  }
}
vector<string> generateParenthesis(int n)
{
  // need to generate all the parenthesis 
  // well formed
  // kuch de rakha hai and generate karna hai all the combination 
  vector<string>ans;
  string temp = "";
  int open = 0 ;
  int close = 0;
  fun(n,open , close , temp,ans);
  return ans;
}
};