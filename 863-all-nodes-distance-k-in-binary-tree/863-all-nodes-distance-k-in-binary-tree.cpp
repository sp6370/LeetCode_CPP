/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void printAtK(TreeNode* root, int k, vector<int> &result)
    {
        //base case
        if(root == NULL || k<0)
        {
            return;
        }
        
        // this node is the correct node
        if(k == 0 )
        {
            result.push_back(root->val);
        }
        
        //we need to go down in the tree
        printAtK(root->left, k-1, result);
        printAtK(root->right, k-1, result);
    }
    
    int helper(TreeNode* root, TreeNode* target, int k, vector<int> &result)
    {
        //edge case
        if(root == NULL)
        {
            return -1;
        }
        
        // target is found 
        if(root == target)
        {
            printAtK(root, k, result);
            // this node is '0' distance away from the required node
            return 0;
        }
        
        //root is not the target, check if target is in left subtree
        int leftAnswer = helper(root->left, target, k, result);
        
        if(leftAnswer!=-1)
        {
            //i.e. we found the required node in the left subtree
            
            //check if the current node i.e. is at k distance from target in left sub tree  
            if(leftAnswer+1 == k)
            {
                result.push_back(root->val);
            }
            else{
                // find all nodes in right subtree of current node which are k distance away from the original targe
                // > distance of current root from target = leftAnswer+1
                // > distance of right child of root from target = leftAnswer+2
                // > Remainig ditance to be travelled in right sub tree: k - leftAnswer-2
                printAtK(root->right, k - leftAnswer - 2, result);
            }
            
            //return the distance
            
            return leftAnswer+1;
        }
        
        int rightAnswer = helper(root->right, target, k, result);
        
        if(rightAnswer!=-1)
        {
            if(rightAnswer+1 == k)
            {
                result.push_back(root->val);
            }
            else
            {
                //find nodes in the left subtree
                printAtK(root->left, k - rightAnswer - 2, result);

            }
            
            return rightAnswer+1;
        }
        
        //base case
        return -1;
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> result;
        
        if(root==NULL || target == NULL)
        {
            return result;
        }
        
        int tmp = helper(root, target, k, result);
        return result;
    }
};