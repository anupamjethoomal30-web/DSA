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
    
    int stn(string s)
    {
        int num = 0;
        
        for(char ch : s)
        {
            num = num * 10 + (ch - '0');
        }

        return num;
    }

    void fun(TreeNode * root , string &s , int &ans)
    {
        if(!root) return;  
      

        if(!root->left && !root->right)
        {
            s += char(root->val + '0');
            
            int s_to_num = stn(s);
            ans += s_to_num;

            s.pop_back();
            return;
        }

        s += char(root->val + '0');
        fun(root->left , s ,ans);
        fun(root->right , s,ans);
        s.pop_back();

    }

    int sumNumbers(TreeNode* root) {
        
        if(!root)
        return 0;

        int ans = 0;
        string s = "";
        fun(root,s,ans);
        return ans;
    }
};