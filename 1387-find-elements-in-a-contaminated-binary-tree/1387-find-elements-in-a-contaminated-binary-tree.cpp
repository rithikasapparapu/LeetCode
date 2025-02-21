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
class FindElements {
public:
    TreeNode* head = new TreeNode();

    void rec(TreeNode* root){
        if(root->left!=NULL){
            root->left->val = 2 * root->val + 1;
            cout << root->left->val << endl;
            rec(root->left);
        }
        if(root->right!=NULL){
            root->right->val = 2 * root->val + 2;
            cout << root->right->val << endl;
            rec(root->right);
        }
    }

    FindElements(TreeNode* root) {
        root->val = 0;
        rec(root);
        head = root;
    }
    
    bool f(TreeNode* head, int target){
        if(head!=NULL && head->val == target) return true;

        if(head!=NULL){
            bool b = f(head->left,target);
            if(b) return true;
        }
        if(head!=NULL){
            bool b = f(head->right,target);
            if(b) return true;
        }
        return false;
    }

    bool find(int target) {
        return f(head, target);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */