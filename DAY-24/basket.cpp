#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    long long D;
    if (!(cin >> N >> D)) return 0;

    vector<long long> P(N);
    for (int i = 0; i < N; i++) {
        cin >> P[i];
    }

    sort(P.begin(), P.end(), greater<long long>());

    int wins = 0;
    int left = 0;
    int right = N - 1;

    while (left <= right) {
        long long top_power = P[left];
        long long players_needed = (D / top_power) + 1;

        if (right - left >= players_needed - 1) {
            wins++;
            left++;
            right -= (players_needed - 1);
        } else {
            break;
        }
    }

    cout << wins << endl;

    return 0;
}