#include <bits/stdc++.h>
using namespace std;

class MeanMedian {
public:
    int minEffort(int needMean, int needMedian, vector<int> d) {
		int n = d.size();
		sort(d.begin(), d.end());
		int64_t ans = 0;
		for(int i = 0; i < n / 2 + 1; ++i) {
			ans += d[i] * needMedian;
		}
		int64_t need = needMean * n - needMedian * (n / 2 + 1);
		if(need > 0) {
			for(int i = 0; i < n / 2 + 1; ++i) {
				ans += min<int64_t>(need, 10 - needMedian) * d[i];
				need -= (10 - needMedian);
				if(need <= 0) break;
			}
		}
		if(need > 0) {
			for(int i = n / 2 + 1; i < n; ++i) {
				ans += min<int64_t>(need, 10) * d[i];
				need -= 10;
				if(need <= 0) break;
			}
		}
		return ans;
    }
};
