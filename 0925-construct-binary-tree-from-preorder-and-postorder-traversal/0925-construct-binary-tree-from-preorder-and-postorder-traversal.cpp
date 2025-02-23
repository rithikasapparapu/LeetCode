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
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int j=0;
        TreeNode* root;
        root = new TreeNode(preorder[0]);
        TreeNode* cur = root;
        stack<TreeNode*> st;
        st.push(root);
        for(int i=1; i<preorder.size(); i++){
            if(preorder[i]!=postorder[j]){
                while(postorder[j]==st.top()->val){
                    st.pop();
                    cur = st.top();
                    j++;
                }
                TreeNode* nnew = new TreeNode(preorder[i]);
                st.push(nnew);
                if(cur->left==NULL){
                    cur->left = nnew;
                    cur = cur->left;
                }
                else{
                    cur->right = nnew;
                    cur = cur->right;
                }
            }
            else{
                if(cur->left==NULL){
                    TreeNode* nnew = new TreeNode(preorder[i]);
                    cur->left = nnew;
                }
                else{
                    TreeNode* nnew = new TreeNode(preorder[i]);
                    cur->right = nnew;
                }
                j++;
            }
        }
        return root;
    }
};