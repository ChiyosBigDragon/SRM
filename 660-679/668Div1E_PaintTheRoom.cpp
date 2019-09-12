#include <bits/stdc++.h>
using namespace std;

class PaintTheRoom {
public:
    string canPaintEvenly(int R, int C, int K) {
		if(K == 1) return "Paint";
		if(R % 2 == 1 and C % 2 == 1) return "Cannot paint";
		return "Paint";
    }
};
