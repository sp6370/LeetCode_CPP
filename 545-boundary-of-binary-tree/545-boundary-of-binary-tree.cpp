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
    
    vector<int> getLeft(TreeNode* root, vector<int> data)
    {
        if(root == NULL)
        {
            return data;
        }
        data.push_back(root->val);
        if(root->left!=NULL)
        {
            return getLeft(root->left, data);
        }
        if(root->right!=NULL)
        {
            return getLeft(root->right, data);
        }
        data.pop_back();
        return data;
    }
    
    vector<int> getRight(TreeNode* root, vector<int> data)
    {
        if(root == NULL)
        {
            return data;
        }
        data.push_back(root->val);
        
        if(root->right!=NULL)
        {
            return getRight(root->right, data);
        }
        
        if(root->left!=NULL)
        {
            return getRight(root->left, data);
        }
        data.pop_back();
        return data;
    }
    
    void getLeaves(TreeNode* root, vector<int> &data)
    {
        if(root == NULL)
        {
            return;
        }
        if(root->left == NULL && root->right == NULL)
        {
            data.push_back(root->val);
            return;
        }
        getLeaves(root->left, data);
        getLeaves(root->right, data);    
    }
    
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        
        vector<int> leftBoundary;
        leftBoundary = getLeft(root->left, leftBoundary);
        vector<int> rightBoundary;
        rightBoundary = getRight(root->right, rightBoundary);
        
        
        vector<int> leaves;
        getLeaves(root, leaves);
        
        vector<int> result;         
        if((root->left != NULL) || (root->right!=NULL))
        {
           result.push_back(root->val); 
        }
        
        result.insert(result.end(), leftBoundary.begin(), leftBoundary.end());
        result.insert(result.end(), leaves.begin(), leaves.end());
        
        reverse(rightBoundary.begin(), rightBoundary.end());
        result.insert(result.end(), rightBoundary.begin(), rightBoundary.end());
        
        return result;
    }
};