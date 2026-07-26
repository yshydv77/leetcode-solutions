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
int maxLevelSum(TreeNode *root)
{
  if(root->left == nullptr && root->right == nullptr){
    return 1;
  }

  // level order traversal need to be performed
  int max_level  = 1;
  int max_sum = INT_MIN;

  queue<TreeNode*>q;
  q.push(root);
  int level = 1;
  while(!q.empty()){
    int siz = q.size();
    int sum = 0 ;
    while(siz--){
      TreeNode* t = q.front();
      q.pop();
      sum += (t->val);

      if(t->left != nullptr){
        q.push(t->left);
      }
      if(t->right != nullptr){
        q.push(t->right);
      }
    }

    // har ek level ka sum nikal kar aagaya hai 
    if(sum > max_sum){
      max_sum = sum;
      max_level = level;
    }

    level++; // because yaha tak ek level ka kaam ho chuka hia 
  }

  return max_level;
}
};