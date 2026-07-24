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
vector<vector<int>> levelOrder(TreeNode *root)
{
  vector<vector<int>>ans;
  if(root == nullptr){
    return {};
  }
  if(root->left == nullptr && root->right == nullptr){
    return {{root->val}};
  }

  queue<TreeNode*>q;
  q.push(root);

  while(!q.empty()){
    int siz = q.size();
    vector<int>temp;

    //level ka kaam yaha hoga
    while(siz--){
      TreeNode* tmp = q.front();
      q.pop();
      temp.push_back(tmp->val);
      if(tmp->left != nullptr){
        q.push(tmp->left);
      }
      if(tmp->right != nullptr){
        q.push(tmp->right);
      }
    }

    // yaha tak mein poori level ko process kar chuka hu
    ans.push_back(temp);
  }

  return ans;
}
};