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
vector<int> largestValues(TreeNode *root)
{
  if(root == nullptr){
    return {};
  }
  if(root->left == nullptr && root->right == nullptr){
    return {root->val};
  }

  vector<int>ans;
  // just perform the lvel ordre traverasl 
  queue<TreeNode*>q;
  q.push(root);

  while(!q.empty()){
    int siz = q.size();
    priority_queue<int>pq;
    while(siz--){
      TreeNode* t = q.front();
      q.pop();

      pq.push(t->val);
      if(t->left != nullptr){
        q.push(t->left);
      }
      if(t->right != nullptr){
        q.push(t->right);
      }

    }

    ans.push_back(pq.top());
  }
  return ans;
} 
};