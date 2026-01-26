#include<iostream>
#include<queue>
#include<vector>
using namespace std;

struct TreeNode {
     int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
vector<vector<int>> level(TreeNode*root)
{
    vector<vector<int>>res;
    if(root==0) return res;

    queue<TreeNode*>q;

    q.push(root);

    while(q.empty()==false)
    {
        vector<int>curr;
        int qSize=q.size();

        for(int i=0;i<qSize;i++)
        {
            TreeNode*node=q.front();
            q.pop();
            curr.push_back(node->val);

            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        res.push_back(curr);
    }
    return res;
}

int main(){
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    vector<vector<int>> output = level(root);

     
    for (const auto& level : output) {
        cout << "[ ";
        for (int val : level) {
            cout << val << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}