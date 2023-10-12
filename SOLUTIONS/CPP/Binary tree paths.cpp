#include <iostream>
#include <vector>
#include <string>
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
    void addPath(TreeNode* root, string temp, vector<string>& ans) {
        if (root == nullptr) {
            return;
        }

        if (root->left == nullptr && root->right == nullptr) {
            temp += to_string(root->val);
            ans.push_back(temp);
            return;
        }

        temp += to_string(root->val) + "->";

        addPath(root->left, temp, ans);
        addPath(root->right, temp, ans);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string temp = "";

        if (root == nullptr) 
            return ans;

        addPath(root, temp, ans);

        return ans;
    }
};

TreeNode* buildTree() {
    int val;
    cin >> val;
    if (val == -1) {
        return nullptr;
    }

    TreeNode* root = new TreeNode(val);
    cout << "Enter left child of " << val << ": ";
    root->left = buildTree();
    cout << "Enter right child of " << val << ": ";
    root->right = buildTree();

    return root;
}

int main() {
    cout << "Enter the values of the binary tree (-1 for null):" << endl;
    TreeNode* root = buildTree();
    Solution solution;
    vector<string> paths = solution.binaryTreePaths(root);

    cout << "Binary Tree Paths:" << endl;
    for (const string& path : paths) {
        cout << path << endl;
    }

    return 0;
}
