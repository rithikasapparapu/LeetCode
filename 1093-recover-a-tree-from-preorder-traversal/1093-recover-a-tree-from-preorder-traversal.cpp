class Solution {
public:
    TreeNode* recoverFromPreorder(string traversal) {
        stack<TreeNode*> st;
        TreeNode* root;
        int i = 0;
        int n = traversal.size();

        string temp = "";
        while (i < n && traversal[i] != '-') {
            temp += traversal[i];
            i++;
        }
        root = new TreeNode(stoi(temp));
        st.push(root);

        while (i < n) {
            int depth = 0;
            while (i < n && traversal[i] == '-') {
                depth++;
                i++;
            }

            temp = "";
            while (i < n && traversal[i] != '-') {
                temp += traversal[i];
                i++;
            }

            TreeNode* node = new TreeNode(stoi(temp));
            while (st.size() > depth) {
                st.pop();
            }
            if (st.top()->left == NULL) {
                st.top()->left = node;
            } else {
                st.top()->right = node;
            }
            st.push(node);
        }
        return root;
    }
};
