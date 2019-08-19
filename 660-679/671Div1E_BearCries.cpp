#include <bits/stdc++.h>
using namespace std;

// dp[i][a][b] := iまで見て';'がa個，';_'がb個残っている
int64_t dp[210][210][210];
class BearCries {
public:
    int count(string message) {
		const int MOD = 1e9 + 7;
		int n = message.size();
		for(int i = 0; i < 210; ++i)
			for(int j = 0; j < 210; ++j)
				for(int k = 0; k < 210; ++k)
					dp[i][j][k] = 0;
		dp[0][0][0] = 1;
		for(int i = 1; i <= n; ++i) {
			for(int a = 0; a <= n; ++a) {
				for(int b = 0; b <= n; ++b) {
					if(message[i - 1] == ';') {
						// 使わない
						if(a - 1 >= 0) dp[i][a][b] += dp[i - 1][a - 1][b];
						dp[i][a][b] %= MOD;
						// 使う
						dp[i][a][b] += dp[i - 1][a][b + 1] * (b + 1);
						dp[i][a][b] %= MOD;
					}
					if(message[i - 1] == '_') {
						// 新規
						if(b - 1 >= 0) dp[i][a][b] += dp[i - 1][a + 1][b - 1] * (a + 1);
						dp[i][a][b] %= MOD;
						// 古参
						dp[i][a][b] += dp[i - 1][a][b] * b;
						dp[i][a][b] %= MOD;
					}
				}
			}
		}
		return dp[n][0][0];
    }
};
