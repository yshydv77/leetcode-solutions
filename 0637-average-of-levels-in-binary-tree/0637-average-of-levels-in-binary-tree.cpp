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
vector<double> averageOfLevels(TreeNode *root)
{
  vector<double>ans;
  if(root->left == nullptr && root->right == nullptr){
    return {(double)root->val};
  }

  queue<TreeNode*>q;
  q.push(root);

  while (!q.empty())
  {
    int siz = q.size();// isse hume pta padta hai ki uss level par kitne nodes present hai 
    double sum = 0;
    int size = siz;
    while(siz--){
      TreeNode* t = q.front();
      q.pop();
      sum+= (t->val);
      if(t->left != nullptr){
        q.push(t->left);
      }
      if(t->right != nullptr){
        q.push(t->right);
      }
    }
    ans.push_back(sum / (double)size);

  }
  
  return ans;

}
};