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
    void fun(TreeNode * root , int &targetSum , vector<int>&temp,vector<vector<int>>&ans)
    {
        
        if(!root) return;

        if(!root->left && !root->right)
        {   
            targetSum -= root->val;
            temp.push_back(root->val);
            if(targetSum == 0)
            ans.push_back(temp);
            
            targetSum += root->val;
            temp.pop_back();
            return;
        }
         
        targetSum -= root->val;
        temp.push_back(root->val);

        fun(root->left , targetSum , temp , ans);
        fun(root->right, targetSum , temp , ans);

        targetSum += root->val;
        temp.pop_back();

    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        
        vector<vector<int>>res;
        vector<int>temp;
        fun(root,targetSum,temp,res);
        return res;
    }
};