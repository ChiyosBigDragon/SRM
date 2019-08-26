#include <bits/stdc++.h>
using namespace std;

template<class T>
struct SegmentTree {
	using F = function<T(T, T)>;
	const T init;
	const F f;
	int sz;
	vector<T> seg;
	SegmentTree(int n, const T init, const F f) :
		init(init),
		f(f)
		{
			sz = 1;
			while(sz < n) sz <<= 1;
			seg.resize(sz << 1, init);
		}
	void update(int id) {
		while(id >>= 1) {
			seg[id] = f(seg[2 * id], seg[2 * id + 1]);
		}
	}
	void replace(int id, T x){
		id += sz;
		seg[id] = x;
		update(id);
	}
	// [l,r)
	T get(int l, int r){
		T L = init, R = init;
		for(l += sz, r += sz; l < r; l >>= 1, r>>= 1) {
			if(l & 1) L = f(L, seg[l++]);
			if(r & 1) R = f(seg[--r], R);
		}
		return f(L, R);
	}
	void debug(){
		int i = 1;
		for(int r = 2; r <= 2 * sz; r <<= 1) {
			while(i < r) {
				cout << seg[i++] << " ";
			}
			cout << "\n";
		}
	}
};

class ApplesAndOrangesEasy {
public:
    int maximumApples(int N, int K, vector<int> info) {
		const int lim = K / 2;
		SegmentTree<int> seg(N, 0, [](int lhs, int rhs){return lhs + rhs;});
		for(int i : info) {
			--i;
			seg.replace(i, 1);
		}
		for(int i = 0; i < N; ++i) {
			bool flg = true;
			for(int l = max(0, i - K + 1); l <= i; ++l) {
				int r = min(N, l + K);
				if(seg.get(l, r) == lim) flg = false;
			}
			if(flg) seg.replace(i, 1);
		}
		return seg.get(0, N);
    }
};
