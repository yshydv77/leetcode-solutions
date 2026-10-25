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
int maxPathSumFinder(TreeNode* root , int& maxi){
    if(root == nullptr) return 0;

    
    /**
     *  there is no point that my left or right is negative if they are neg then we should return 0 
     * because obviously negative value will not contribute in my answer for maximum answer 
     * */
    int left = max( maxPathSumFinder(root->left , maxi),0);
    int right = max(maxPathSumFinder(root->right , maxi) , 0);

    maxi = max(maxi , left + right + root->val);
    /**
     * why we are returning root->data + max(left,right)
     * because for that particular node i want just want the max left or the right sum
     * 
     * */
    return root->val + max(left,right);
}
int maxPathSum(TreeNode* root) {
    int maxi  =INT_MIN;
    int a = maxPathSumFinder(root , maxi);
    return maxi;
}
};