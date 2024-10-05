#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    string A, B;
    cout << "Enter two strings:\n";
    cin >> A >> B;

    int m = A.length();
    int n = B.length();
    
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (A[i - 1] == B[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    cout << "Length of Longest Common Subsequence: " << dp[m][n] << endl;

    return 0;
}
