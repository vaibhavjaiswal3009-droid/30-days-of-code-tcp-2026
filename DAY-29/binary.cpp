 #include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int globalMax = INT_MIN;
        calculateGain(root, globalMax);
        return globalMax;
    }

private:
    int calculateGain(TreeNode* node, int& globalMax) {
        if (!node) return 0;

        int leftGain = max(0, calculateGain(node->left, globalMax));
        int rightGain = max(0, calculateGain(node->right, globalMax));

        globalMax = max(globalMax, node->val + leftGain + rightGain);

        return node->val + max(leftGain, rightGain);
    }
};

int main() {
    // Constructing a test tree: [-10, 9, 20, null, null, 15, 7]
    TreeNode* root = new TreeNode(-10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution sol;
    cout << "Maximum Path Sum: " << sol.maxPathSum(root) << endl;

    return 0;
}