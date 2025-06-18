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
    void dfs(TreeNode* root, int& count_good_node, int max_val)
    {
        if(!root) return;
        if(root->val >= max_val)
        {
            count_good_node++;
            max_val = max(max_val,root->val);
            cout<<count_good_node<<" "<<root->val<<" "<<max_val<<endl;
            root->val = INT_MIN;
        }
        dfs(root->left, count_good_node, max_val);
        dfs(root->right, count_good_node, max_val);
        
    }
    int goodNodes(TreeNode* root) {
        int count_good_node =0;
        if(!root) return count_good_node;
        int max_val = root->val;
        dfs(root,count_good_node,max_val);
        return count_good_node;
    }
};
