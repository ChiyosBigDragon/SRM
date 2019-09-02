#include <bits/stdc++.h>
using namespace std;

class SquareScores {
public:
    double calcexpectation(vector<int> p, string s) {
		int pn = p.size();
		int sn = s.size();
		double ans = 0.0;
		for(int i = 0; i < pn; ++i) {
			char c = 'a' + i;
			for(int l = 0; l < sn; ++l) {
				double tmp = 1.0;
				for(int r = l; r < sn; ++r) {
					if(s[r] != c and s[r] != '?') break;
					if(s[r] == '?') {
						tmp *= 0.01 * p[i];
					}
					ans += tmp;
				}
			}
		}
		return ans;
    }
};
