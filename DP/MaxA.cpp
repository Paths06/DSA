// Problem Description
// You have a special keyboard with four possible operations:

// A: Print one 'A' on the screen
// Ctrl-A: Select all text currently on the screen
// Ctrl-C: Copy the selected text to a buffer
// Ctrl-V: Paste the buffer content to the screen (appending it after existing text)
// Given an integer n representing the maximum number of key presses allowed, determine the maximum number of 'A' characters you can print on the screen.

// Each operation counts as one key press. For example:

// Pressing 'A' uses 1 key press and adds 1 'A'
// The copy-paste sequence (Ctrl-A, Ctrl-C, Ctrl-V) uses 3 key presses total and doubles the current text
// Multiple Ctrl-V operations can be performed after a single copy operation
// The challenge is to find the optimal combination of direct printing ('A') and copy-paste operations to maximize the total number of 'A' characters within n key presses.

// For instance, with n = 7 key presses, you could:

// Press 'A' 7 times to get 7 'A's
// Or press 'A' 3 times, then Ctrl-A, Ctrl-C, Ctrl-V, Ctrl-V to get 9 'A's (3 initial, then paste twice for 3+3+3)

class Solution {
public:
    int maxA(int n) {
        // dp[i] = max A's achievable with exactly i keystrokes
        vector<int> dp(n + 1, 0);

        for (int i = 1; i <= n; i++) {

            // Option 1: press A key on keystroke i
            // Simply extends previous best by 1
            dp[i] = dp[i - 1] + 1;

            // Option 2: end a multiply block at keystroke i
            // Block of length b uses: 1 Ctrl+A + 1 Ctrl+C + (b-2) Ctrl+V
            // Minimum useful block = 3 (Ctrl+A, Ctrl+C, one Ctrl+V → multiplies by 2)
            // Block starts at keystroke (i-b+1), so dp[i-b] A's exist before block
            // Multiplier = (b-1): one Ctrl+V gives ×2... (b-2) Ctrl+V's give ×(b-1)
            for (int b = 3; b <= i; b++) {
                // dp[i-b] = A's on screen before this multiply block
                // (b-1)   = multiplication factor from this block
                dp[i] = max(dp[i], dp[i - b] * (b - 1));
            }
        }

        return dp[n];
    }
};
