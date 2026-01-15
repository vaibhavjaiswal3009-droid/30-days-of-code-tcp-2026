#include <iostream>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Helper function to calculate GCD
    long long gcd(long long a, long long b) {
        while (b) {
            a %= b;
            swap(a, b);
        }
        return a;
    }

    // Helper function to calculate LCM
    long long lcm(long long a, long long b) {
        // We divide first to avoid unnecessary overflow
        return (a / gcd(a, b)) * b;
    }

    int nthUglyNumber(int n, int a, int b, int c) {
        // Search range: 1 to 2 * 10^9
        long long low = 1, high = 2000000000;
        long long ans = high;

        // Precompute LCMs of pairs and the triplet
        long long ab = lcm(a, b);
        long long bc = lcm(b, c);
        long long ac = lcm(a, c);
        long long abc = lcm(a, bc);

        while (low <= high) {
            long long mid = low + (high - low) / 2;

            // Inclusion-Exclusion Principle formula
            // Count = (divisible by a, b, or c) 
            //         - (divisible by pairs ab, bc, ac) 
            //         + (divisible by all three abc)
            long long count = (mid / a) + (mid / b) + (mid / c)
                            - (mid / ab) - (mid / bc) - (mid / ac)
                            + (mid / abc);

            if (count >= n) {
                ans = mid;
                high = mid - 1; // Try to find a smaller value that still satisfies count >= n
            } else {
                low = mid + 1;
            }
        }

        return (int)ans;