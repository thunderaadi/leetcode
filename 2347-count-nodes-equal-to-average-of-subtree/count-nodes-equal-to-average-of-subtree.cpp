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
    int c=0;

    pair<int,int> dfs(TreeNode* root)
    {
        if(root==NULL)
            return {0,0};

        pair<int,int> l=dfs(root->left);
        pair<int,int> r=dfs(root->right);

        int sum=root->val+l.first+r.first;
        int cnt=1+l.second+r.second;

        if(sum/cnt==root->val)
            c++;

        return {sum,cnt};
    }

    int averageOfSubtree(TreeNode* root)
    {
        dfs(root);
        return c;
    }
};