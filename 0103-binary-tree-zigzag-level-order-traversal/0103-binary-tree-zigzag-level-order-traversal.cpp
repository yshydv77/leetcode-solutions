/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
vector<vector<int>> zigzagLevelOrder(TreeNode *root)
{
  if(root == nullptr){
    return {};
  }
  if(root->left == nullptr && root->right == nullptr){
    return {{root->val}};
  }

  vector<vector<int>> ans;
  queue<TreeNode*>q;
  q.push(root);
  int level = 0 ;
  // i -> even left to right  
  // i -> odd right to left

  while (!q.empty())
  {
    int siz = q.size();
    vector<int>temp;
    stack<int>st;
    while (siz--)
    {
      TreeNode* t = q.front();
      q.pop();
      if(level%2 == 0){
        //even hai toh direct left to right order hi rahega
        temp.push_back(t->val);
      }
      else{
        st.push(t->val);
      }

      if(t->left != nullptr){
        q.push(t->left);
      }
      if(t->right != nullptr){
        q.push(t->right);
      }
    }
    level++;
    if(temp.empty() && !st.empty()){
      while(!st.empty()){
        temp.push_back(st.top());
        st.pop();
      }
    }
    ans.push_back(temp);
    
  }
  
  return ans;

}

};