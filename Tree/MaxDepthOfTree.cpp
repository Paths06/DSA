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
    void getMaxDepth(TreeNode* root, int height, vector<int>& depthArr)
    {
        if(!root)
        { 
            // height++;
            depthArr.push_back(height);
            return;
        }
        // height+=1;
        getMaxDepth(root->left, height+1,depthArr);
        getMaxDepth(root->right, height+1,depthArr);

    }
    int maxDepth(TreeNode* root) {
        int height =0;
        if(!root)
        {
            return height;
        }
        vector<int> depthArr;
        getMaxDepth(root, height,depthArr);
        return *max_element(depthArr.begin(), depthArr.end());
    }
};
