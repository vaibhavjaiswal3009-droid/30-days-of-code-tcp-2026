#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> s;
        unordered_map<int, int> mapping;

        for (int num : nums2) {
            while (!s.empty() && num > s.top()) {
                mapping[s.top()] = num;
                s.pop();
            }
            s.push(num);
        }

        while (!s.empty()) {
            mapping[s.top()] = -1;
            s.pop();
        }

        vector<int> ans;
        ans.reserve(nums1.size());
        for (int num : nums1) {
            ans.push_back(mapping[num]);
        }

        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};
    
    vector<int> result = sol.nextGreaterElement(nums1, nums2);
    
     
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << (i == result.size() - 1 ? "" : ", ");
    }
     

    return 0;
}