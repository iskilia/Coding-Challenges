class TestClass{

    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };
    public:

        // Encodes a tree to a single string.
        std::string serialize(TreeNode* root) {
            std::ostringstream out;
            serializeHelper(root, out);
            return out.str();
        }

        // Decodes your encoded data to tree.
        TreeNode* deserialize(string data) {
            std::istringstream in(data);
            return deserializeHelper(in);
        }

    private:
        void serializeHelper(TreeNode* root, ostringstream& out){
            if (!root) {
                out << "# ";
                return;
            }
            out << root->val << " ";
            serializeHelper(root->left, out);
            serializeHelper(root->right, out);
        }

        TreeNode* deserializeHelper(istringstream& in){
            string val;
            in >> val;
            if (val == "#") return nullptr;
            TreeNode* root = new TreeNode(stoi(val));
            root->left = deserializeHelper(in);
            root->right = deserializeHelper(in);
            return root;
        }
}