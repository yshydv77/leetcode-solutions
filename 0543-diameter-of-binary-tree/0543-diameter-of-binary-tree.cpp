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
    int H(TreeNode* root , int& maxi){
    if(root == nullptr) return 0;

    int left = H(root->left,maxi);
    int right = H(root->right, maxi);
    // because for the diameter what we have to do is 
    // just find out the height of the left subtree for that particular node
    // and find out the height of the right subtree for that particular node
    maxi = max(maxi , left + right);
    return 1 +max(left,right);

}
int diameterOfBinaryTree(TreeNode* root) {
    int maxi = INT_MIN;
    int ans = H(root , maxi);
    return maxi;
}
};