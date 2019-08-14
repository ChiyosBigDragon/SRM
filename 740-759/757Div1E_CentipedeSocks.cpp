#include <bits/stdc++.h>
using namespace std;

class CentipedeSocks {
public:
	int fewestSocks(int C, int F, vector<int> sockCounts) {
		priority_queue<pair<int, int>> pq;
		int n = sockCounts.size();
		int ans = 0;
		for(int i = 0; i < n; ++i) {
			if(sockCounts[i] - F >= 0) {
				pq.push({min(sockCounts[i] - F, F - 1), i});
			} else {
				ans += sockCounts[i];
				sockCounts[i] = 0;
			}
		}
		int last = -1;
		while(C--) {
			if(not pq.empty()) {
				int s, idx;
				tie(s, idx) = pq.top();
				pq.pop();
				ans += F;
				sockCounts[idx] -= F;
				last = idx;
				if(sockCounts[idx] - F >= 0) {
					pq.push({min(sockCounts[idx] - F, F - 1), idx});
				} else {
					if(C != 0) {
						ans += sockCounts[idx];
						sockCounts[idx] = 0;
					}
				}
			} else {
				return -1;
			}
		}
		for(int i = 0; i < n; ++i) {
			if(i == last) continue;
			ans += min(sockCounts[i], F - 1);
		}
		return ans;
	}
};
