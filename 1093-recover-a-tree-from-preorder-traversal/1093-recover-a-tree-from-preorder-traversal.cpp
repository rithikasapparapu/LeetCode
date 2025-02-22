class Solution {
public:
    TreeNode* recoverFromPreorder(string traversal) {
        stack<TreeNode*> st;
        TreeNode* root = nullptr;
        int i = 0;
        int n = traversal.size();

        // Parse root node (depth 0)
        int val = 0;
        while (i < n && traversal[i] != '-') {
            val = val * 10 + (traversal[i] - '0');
            i++;
        }
        root = new TreeNode(val);
        st.push(root);

        while (i < n) {
            int depth = 0;
            while (i < n && traversal[i] == '-') {
                depth++;
                i++;
            }

            val = 0;
            while (i < n && traversal[i] != '-') {
                val = val * 10 + (traversal[i] - '0');
                i++;
            }

            TreeNode* node = new TreeNode(val);
            while (st.size() > depth) {
                st.pop();
            }

            if (st.top()->left == nullptr) {
                st.top()->left = node;
            } else {
                st.top()->right = node;
            }
            st.push(node);
        }

        return root;
    }
};
