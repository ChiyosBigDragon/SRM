#include <bits/stdc++.h>
using namespace std;

class StonesOnATree {
public:
	struct Node {
		vector<int> child;
		int w;
	};
	vector<Node> g;
	// dp[i] := iに置くときのスコアの最小値
	vector<int> dp;
	int dfs(int from) {
		if(dp[from] != -1) return dp[from];
		if(g[from].child.size() == 2) {
			int l = g[from].child[0];
			int r = g[from].child[1];
			int ret = 0;
			// 左右の操作時が最大
			ret = max(ret, max(dfs(l), dfs(r)));
			// 右を完了させてから左が最大，その逆が最大
			ret = max(ret, min(dfs(l) + g[r].w, dfs(r) + g[l].w));
			// 左右を終えて親に置くときが最大
			ret = max(ret, g[from].w + g[l].w + g[r].w);
			return dp[from] = ret;
		}
		if(g[from].child.size() == 1) {
			int l = g[from].child[0];
			int ret = 0;
			// 子に置くときが最大
			ret = max(ret, dfs(l));
			// 子を完了して親に置くときが最大
			ret = max(ret, g[from].w + g[l].w);
			return dp[from] = ret;
		}
		return dp[from] = g[from].w;
	}
    int minStones(vector<int> p, vector<int> w) {
		int n = w.size();
		dp = vector<int>(n, -1);
		g = vector<Node>(n);
		for(int i = 0; i < n - 1; ++i) {
			g[p[i]].child.push_back(i + 1);
		}
		for(int i = 0; i < n; ++i) {
			g[i].w = w[i];
		}
		return dfs(0);
    }
};
