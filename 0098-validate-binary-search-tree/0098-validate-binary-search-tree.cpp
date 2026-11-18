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
class Triplet{
    public: 
      long long min;
      long long max;
      bool isBST;
      Triplet(long long max, long long min, bool isBST){
        this->max = max;
        this->min = min;
        this->isBST = isBST;
      }
      };
      Triplet fun(TreeNode* root){
        if(root == NULL) return Triplet(LLONG_MIN, LLONG_MAX, true);
        Triplet left = fun(root->left);
         Triplet right = fun(root->right);
         long long val = root->val;
         long long mx = max(val, max(left.max, right.max));
         long long mn = min(val, min(left.min, right.min));
         bool isBST = val > left.max && val < right.min && (left.isBST && right.isBST);
         return Triplet(mx, mn, isBST);
      }

    bool isValidBST(TreeNode* root) {
        return fun(root).isBST;
    }   
};





// bool check(TreeNode* root, long long low, long long high){
//          if(root == NULL)return true;
//         if(root->val <= low || root->val >= high)return false;
//         return check(root->left, low, root->val) && check(root->right, root->val, high);
//     }
//     bool isValidBST(TreeNode* root) {
//        return check(root, LLONG_MIN, LLONG_MAX);
//     }