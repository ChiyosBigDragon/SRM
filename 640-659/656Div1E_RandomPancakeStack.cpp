#include <bits/stdc++.h>
using namespace std;

class RandomPancakeStack {
public:
    double expectedDeliciousness(vector<int> d) {
		int n = d.size();
		// dp[i][j] := 一番上がiで個数がjの確率
		double dp[255][255] = {};
		dp[n][0] = 1;
		double ans = 0;
		for(int i = n - 1; i >= 0; --i) {
			for(int j = 1; j <= n; ++j) {
				for(int k = i + 1; k < 255; ++k) {
					dp[i][j] += dp[k][j - 1] / (double)(n - (j - 1));
				}
				ans += dp[i][j] * d[i];
			}
		}
		return ans;
    }
};
