#include <vector>

using namespace std;

class Solution {
public:
    /**
     * Helper function to count subarrays with AT MOST 'goal' odd numbers.
     */
    int countAtMost(vector<int>& nums, int goal) {
        if (goal < 0) return 0;
        
        int left = 0;
        int currentOddCount = 0;
        int totalSubarrays = 0;
        
        for (int right = 0; right < nums.size(); ++right) {
            // If the current number is odd, increment our window's odd count
            if (nums[right] % 2 != 0) {
                currentOddCount++;
            }
            
            // Shrink the window from the left if we exceed the allowed odd count
            while (currentOddCount > goal) {
                if (nums[left] % 2 != 0) {
                    currentOddCount--;
                }
                left++;
            }
            
            // The number of subarrays ending at 'right' with at most 'goal' odd numbers 
            // is equal to the length of the current valid window.
            totalSubarrays += (right - left + 1);
        }
        
        return totalSubarrays;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        // Exactly K is the difference between At Most K and At Most K-1
        return countAtMost(nums, k) - countAtMost(nums, k - 1);
    }
};