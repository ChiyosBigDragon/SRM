#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e7;
int last[MAX];
int ans[MAX];
class PreviousOccurrence {
public:
    int findValue( int defaultValue, int query ){
		for(int i = 0; i < MAX; ++i) last[i] = -1;
		for(int i = 0; i < MAX; ++i) ans[i] = -1;
		int pre = 0;
		for(int cnt = 1; cnt < MAX; ++cnt) {
			if(last[pre] == -1) {
				ans[pre] = cnt - 1;
				if(pre == query) {
					return ans[pre];
				}
				last[pre] = cnt - 1;
				pre = defaultValue;
			} else {
				int tmp = pre;
				pre = (cnt - 1) - last[pre];
				last[tmp] = cnt - 1;
				if(pre >= MAX) break;
			}
		}
		return -1;
	}
};
