/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        stringstream ss;
        writeTree(root, ss);
        string res = ss.str();
        res.pop_back();
        return res;
    }

    void writeTree(TreeNode* root, stringstream& ss) {
        if (root) {
            ss << root->val << " ";
            writeTree(root->left, ss);
            writeTree(root->right, ss);
        }
        else {
            ss << "# ";
        }
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss;
        ss << data;

        return readTree(ss);
    }

    TreeNode* readTree(stringstream& ss) {
        string str;
        ss >> str;
        if (str == "#") {
            return NULL;
        }
        else {
            TreeNode* root = new TreeNode(atoi(str.c_str()));
            root->left = readTree(ss);
            root->right = readTree(ss);
            return root;
        }
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
