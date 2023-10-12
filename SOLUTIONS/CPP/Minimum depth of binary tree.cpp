#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        queue<TreeNode*> Q;
        Q.push(root);
        int depth = 0;
        while (!Q.empty()) {
            depth++;
            int count = Q.size();
            for (int i = 0; i < count; i++) {
                TreeNode* node = Q.front();
                if (node->left) {
                    Q.push(node->left);
                }
                if (node->right) {
                    Q.push(node->right);
                }
                Q.pop();
                if (node->left == nullptr && node->right == nullptr) {
                    return depth;
                }
            }
        }
        return -1;
    }
};

TreeNode* createTree() {
    int val;
    cin >> val;
    if (val == -1) { // Assuming -1 represents a NULL node
        return nullptr;
    }
    TreeNode* root = new TreeNode(val);
    root->left = createTree();
    root->right = createTree();
    return root;
}

int main() {
    cout << "Enter the tree nodes in the following format (space-separated):" << endl;
    cout << "Node NodeLeft NodeRight" << endl;
    cout << "Use -1 for NULL nodes." << endl;

    TreeNode* root = createTree();

    Solution solution;
    int minDepth = solution.minDepth(root);
    cout << "The minimum depth of the tree is: " << minDepth << endl;

    return 0;
}
