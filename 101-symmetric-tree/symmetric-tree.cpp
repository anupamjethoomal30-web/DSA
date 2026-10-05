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
    bool isSymmetric(TreeNode* root) {
        
        if(!root) return false;


        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty())
        {
            
            vector<TreeNode*>temp;
            int n = q.size();

            while(n--)
            {
                TreeNode * node = q.front();
                q.pop();


                temp.push_back(node);

                if(node){
                q.push(node->left);
                q.push(node->right);
                }
               
            }
            

            int left = 0;
            int right = temp.size()-1;

            while(left < right)
            {
             
                if(temp[left] == NULL && temp[right] == NULL)
                {
                    left++;
                    right--;
                    continue;
                }

                if(temp[left] == NULL || temp[right] == NULL)
                return false;

                if(temp[left]->val != temp[right]->val)
                return false;
                
                left++;
                right--;
            }
        }
        
        return true;
    }
};