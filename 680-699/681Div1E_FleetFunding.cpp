#include <bits/stdc++.h>
using namespace std;

class FleetFunding {
public:
	using T = tuple<int, int, int>;
	using pqueue = priority_queue<T, vector<T>, greater<T>>;
	bool bisearch(int m, int mid, pqueue &pq) {
		// aの早い順
		pqueue pq1 = pq;
		// bの早い順
		pqueue pq2;
		for(int i = 1; i <= m; ++i) {
			while(pq1.size()) {
				int a, b, k;
				tie(a, b, k) = pq1.top();
				if(a > i) break;
				pq1.pop();
				pq2.emplace(b, k, a);
			}
			int tmp = mid;
			while(pq2.size()) {
				int b, k, a;
				tie(b, k, a) = pq2.top();
				pq2.pop();
				if(b < i) continue;
				tmp -= k;
				if(tmp < 0) {
					pq2.emplace(b, -tmp, a);
					break;
				}
			}
			if(tmp > 0) return false;
		}
		return true;
	}
    int maxShips(int m, vector <int> k, vector <int> a, vector <int> b) {
		// aの早い順
		pqueue pq;
		int n = k.size();
		for(int i = 0; i < n; ++i) {
			pq.emplace(a[i], b[i], k[i]);
		}
		int ok = 0, ng = 5e7 + 10;
		while(abs(ok - ng) > 1) {
			int mid = (ok + ng) / 2;
			if(bisearch(m, mid, pq)) {
				ok = mid;
			} else {
				ng = mid;
			}
		}
		return ok;
    }
};
