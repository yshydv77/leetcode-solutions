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
int galat = 0;
TreeNode *prev = nullptr;
TreeNode *galat1_first = nullptr;
TreeNode *galat1_second = nullptr;
TreeNode *galat2_first = nullptr;
TreeNode *galat2_second = nullptr;
void fun(TreeNode *root)
{
  if (root == nullptr)
  {
    return;
  }
  fun(root->left);

  if (prev == nullptr)
  {
    prev = root;
  }
  else
  {
    // checking for the galti
    if (prev->val >= root->val)
    {
      // galti hai
      if (galat == 0)
      {
        // pheli galti hai
        galat1_first = prev;
        galat1_second = root;
        galat++;
      }
      else
      {
        // meri doosri galti hai
        galat2_first = prev;
        galat2_second = root;
        galat++;
      }
    }
    prev = root;
  }

  //* yaha tak meine saari galti vagerah nikal li hai ek tree ke andar 
  fun(root->right); 

}

void recoverTree(TreeNode *root)
{
  if(root == nullptr){
    return ;
  }

  fun(root);
  if(galat == 1){
    //* matlab nodes are adjacent to each other 
    swap(galat1_first->val , galat1_second->val);
  }
  else{
    //* matlab nodes are not adjacent to each other 
    swap(galat1_first->val , galat2_second->val);
  }

  return ;

}
};