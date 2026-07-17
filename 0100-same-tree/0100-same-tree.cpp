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
    void preOrder(TreeNode* root, vector<int>&ans){
        if(root == NULL){
            ans.push_back(INT_MIN);
            return;
        }
        ans.push_back(root->val);
        preOrder(root->left, ans);
        preOrder(root->right, ans);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<int> pans;
        vector<int> qans;

        preOrder(p, pans);
        preOrder(q,qans);

        if(pans.size() != qans.size()){
            return false;
        }

        for(int i =0; i<pans.size(); i++){
            if(pans[i]!= qans[i]){
                return false;
            }
        }

        return true;
    }
};