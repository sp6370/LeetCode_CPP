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
    vector<int> rightSideView(TreeNode* root) {

        vector<int> result;
        if(root == NULL)
        {
            return result;
        }
        
        queue<TreeNode*> nodeQueue;
        nodeQueue.push(root);
        
        int levelNodeCount = 1;
        int childNodeCount = 0;
        
        vector<int> levelResult;
        
        while(!nodeQueue.empty())
        {
            while(levelNodeCount>0)
            {
                TreeNode* tmp = nodeQueue.front();
                levelResult.push_back(tmp->val);
                nodeQueue.pop();
                
                if(tmp->left!=NULL)
                {
                    nodeQueue.push(tmp->left);
                    childNodeCount++;
                }
                if(tmp->right!=NULL)
                {
                    nodeQueue.push(tmp->right);
                    childNodeCount++;
                }
                levelNodeCount--;
            }
            
            result.push_back(levelResult[levelResult.size()-1]);
            levelResult.clear();
            levelNodeCount = childNodeCount;
            childNodeCount = 0;
        }
        return result;
    }
    
};