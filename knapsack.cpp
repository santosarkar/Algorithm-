#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n; // Number of items
    int W; // Capacity of the knapsack

    cout << "Enter the number of items: ";
    cin >> n;
    cout << "Enter the capacity of the knapsack: ";
    cin >> W;

    int weights[n], values[n];

    cout << "Enter the weights and values for each item:\n";
    for (int i = 0; i < n; ++i) {
        cout << "Item " << (i + 1) << " - Weight: ";
        cin >> weights[i];
        cout << "Item " << (i + 1) << " - Value: ";
        cin >> values[i];
    }

    int dp[n + 1][W + 1];

    for (int i = 0; i <= n; ++i) {
        for (int w = 0; w <= W; ++w) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            } else if (weights[i - 1] <= w) {
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - weights[i - 1]] + values[i - 1]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    cout << "Maximum value in the knapsack: " << dp[n][W] << endl;

    return 0;
}
