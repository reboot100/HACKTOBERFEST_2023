#include <iostream>
#include <cmath>

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
    bool isBalanced(TreeNode* root) {
        int height = 0;
        return dfs(root, height);
    }

private:
    bool dfs(TreeNode* root, int& height) {
        if (root == nullptr) {
            height = -1;
            return true;
        }

        int left = 0;
        int right = 0;
        if (!(dfs(root->left, left)) || !(dfs(root->right, right))) {
            return false;
        }
        if (abs(left - right) > 1) {
            return false;
        }
        height = 1 + max(left, right);
        return true;
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
    bool isBalanced = solution.isBalanced(root);
    cout << (isBalanced ? "The tree is balanced." : "The tree is not balanced.") << endl;

    return 0;
}
