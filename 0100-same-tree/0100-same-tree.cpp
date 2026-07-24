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

void fun(TreeNode* node1 , TreeNode* node2 , bool& ans){

  // false do case mein hi return karna hai 
  // 1. node ki values match nahi kar rahi hai
  // 2. node ki jagah null hai and ek node mein value hai 

  if(node1 == nullptr && node2 == nullptr){
    return ;
  }

  if(node1 == nullptr && node2 != nullptr){
    ans = false;
    return ;
  }

  if(node1 != nullptr && node2 == nullptr){
    ans = false;
    return ;
  }

  int v1 = node1->val;
  int v2 = node2->val;
  if(v1 != v2){
    ans = false;
    return ; 
  }

  fun(node1->left , node2->left , ans);
  fun(node1->right , node2->right , ans);

}
bool isSameTree(TreeNode *p, TreeNode *q)
{
  bool ans = true;
  fun(p,q , ans);
  return ans;
}
};