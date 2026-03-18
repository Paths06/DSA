#include <bits/stdc++.h>
using namespace std;

int maxSumDivThree(vector<int>& nums) {
    // dp[r] = max sum achievable with sum%3 == r
    // init: only empty subset (sum=0) is valid
    vector<int> dp(3, INT_MIN);
    dp[0] = 0; // empty subset has sum 0, remainder 0

    for (int num : nums) {
        vector<int> new_dp = dp; // copy: each num used at most once

        int rem = num % 3;

        for (int r = 0; r < 3; r++) {
            if (dp[r] == INT_MIN) continue; // state not reachable yet

            int new_r = (r + rem) % 3;     // new remainder after adding num

            // update new state with max sum
            new_dp[new_r] = max(new_dp[new_r], dp[r] + num);
        }

        dp = new_dp; // move to next element
    }

    // dp[0] = max sum divisible by 3
    return dp[0]; // guaranteed >= 0 since dp[0] starts at 0 (empty subset)
}

// ── test ──
int main() {
    vector<int> a = {3, 6, 5, 1, 8};
    cout << maxSumDivThree(a) << "\n"; // 18

    vector<int> b = {4};
    cout << maxSumDivThree(b) << "\n"; // 0

    vector<int> c = {1, 2, 3, 4, 4};
    cout << maxSumDivThree(c) << "\n"; // 12

    return 0;
}
// ```

// ---

// ## Dry Run: `[3, 6, 5, 1, 8]`
// ```
// Init: dp = [0, -inf, -inf]

// num=3, rem=0:
//   r=0: new_r=(0+0)%3=0, new_dp[0]=max(0, 0+3)=3
//   dp = [3, -inf, -inf]

// num=6, rem=0:
//   r=0: new_r=0, new_dp[0]=max(3, 3+6)=9
//   dp = [9, -inf, -inf]

// num=5, rem=2:
//   r=0: new_r=(0+2)=2, new_dp[2]=max(-inf, 9+5)=14
//   dp = [9, -inf, 14]

// num=1, rem=1:
//   r=0: new_r=1, new_dp[1]=max(-inf, 9+1)=10
//   r=2: new_r=(2+1)%3=0, new_dp[0]=max(9, 14+1)=15
//   dp = [15, 10, 14]

// num=8, rem=2:
//   r=0: new_r=2, new_dp[2]=max(14, 15+8)=23
//   r=1: new_r=(1+2)%3=0, new_dp[0]=max(15, 10+8)=18
//   r=2: new_r=(2+2)%3=1, new_dp[1]=max(10, 14+8)=22
//   dp = [18, 22, 23]

// Answer: dp[0] = 18 ✅
// (3+6+1+8=18, divisible by 3)
