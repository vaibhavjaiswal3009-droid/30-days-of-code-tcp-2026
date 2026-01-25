#include <iostream>
#include <vector>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

// The traversal logic
void traverse(TreeNode* root, vector<int>& in, vector<int>& pre, vector<int>& post) {
    if (!root) return;
    pre.push_back(root->data);
    traverse(root->left, in, pre, post);
    in.push_back(root->data);
    traverse(root->right, in, pre, post);
    post.push_back(root->data);
}

vector<vector<int>> getTreeTraversal(TreeNode *root) {
    vector<int> inorder, preorder, postorder;
    traverse(root, inorder, preorder, postorder);
    return {inorder, preorder, postorder};
}

int main() {
     
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    vector<vector<int>> result = getTreeTraversal(root);

    string labels[] = {"Inorder: ", "Preorder: ", "Postorder: "};

    for (int i = 0; i < 3; i++) {
        cout << labels[i];
        for (int val : result[i]) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}