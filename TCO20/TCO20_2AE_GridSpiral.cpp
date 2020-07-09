#include <bits/stdc++.h>
using namespace std;

class GridSpiral {
public:
    long long findCell( int D ){
		if(D % 2 == 0) {
			return -1;
		}
		if(D <= 3) {
			return 0;
		}
		long long idx = (D - 5) / 2;
		long long ans = (idx / 2) * ((idx + 1) / 2);
		return ans;
    }
};
