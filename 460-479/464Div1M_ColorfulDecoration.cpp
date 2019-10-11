#include <bits/stdc++.h>
using namespace std;

struct StronglyConnectedComponent {
	const int V;
	vector<vector<int>> G, revG;
	vector<int> id;
	StronglyConnectedComponent(const int V) :
		V(V),
		G(vector<vector<int>>(V, vector<int>())),
		revG(vector<vector<int>>(V, vector<int>())),
		id(vector<int>(V))
		{}
	void addEdge(int from, int to) {
		G[from].push_back(to);
		revG[to].push_back(from);
	}
	void build() {
		vector<bool> used(V, false);
		stack<int> st;
		for(int from = 0; from < V; ++from) {
			if(not used[from]) {
				dfs(from, used, st);
			}
		}
		int num = 0;
		while(st.size()) {
			int from = st.top();
			st.pop();
			if(used[from]) {
				revdfs(from, num, used);
				++num;
			}
		}
	}
	void dfs(int from, vector<bool> &used, stack<int> &st) {
		used[from] = true;
		for(int to : G[from]) {
			if(not used[to]) {
				dfs(to, used, st);
			}
		}
		st.push(from);
	}
	void revdfs(int from, int num, vector<bool> &used) {
		used[from] = false;
		id[from] = num;
		for(int to : revG[from]) {
			if(used[to]) {
				revdfs(to, num, used);
			}
		}
	}
	int get(int x) {
		return id[x];
	}
};

struct TwoSatisfiability {
	const int V;
	vector<vector<int>> G;
	vector<bool> pos;
	StronglyConnectedComponent scc;
	TwoSatisfiability(const int V) :
		V(V),
		G(vector<vector<int>>(2 * V, vector<int>())),
		pos(vector<bool>(2 * V)),
		scc(StronglyConnectedComponent(2 * V))
		{}
	inline int NOT(int A) {
		return (A + V) % (2 * V);
	}
	// A <=> (not A -> A)
	void addUNARY(int A, bool Apos) {
		if(not Apos) A = NOT(A);
		scc.addEdge(NOT(A), A); // not A -> A
	}
	// A or B <=> (not A -> B) and (not B -> A)
	void addOR(int A, bool Apos, int B, bool Bpos) {
		if(not Apos) A = NOT(A);
		if(not Bpos) B = NOT(B);
		scc.addEdge(NOT(A), B); // not A -> B
		scc.addEdge(NOT(B), A); // not B -> A
	}
	// not(A and B) => (A -> not B) and (B -> not A)
	void addNAND(int A, bool Apos, int B, bool Bpos) {
		if(not Apos) A = NOT(A);
		if(not Bpos) B = NOT(B);
		scc.addEdge(A, NOT(B)); // A -> not B
		scc.addEdge(B, NOT(A)); // B -> not A
	}
	// A xor B <=> not(A and B) and not(not A and not B)
	void addXOR(int A, bool Apos, int B, bool Bpos) {
		addNAND(A, Apos, B, Bpos); // not(A and B)
		addNAND(A, not Apos, B, not Bpos); // not(not A and not B)
	}
	// not(A xor B) <=> A xor not B
	void addXNOR(int A, bool Apos, int B, bool Bpos) {
		addXOR(A, Apos, B, not Bpos);
	}
	bool solve() {
		scc.build();
		for(int i = 0; i < V; ++i) {
			if(scc.get(i) == scc.get(i + V)) {
				return false;
			}
			pos[i] = (scc.get(i) > scc.get(i + V));
		}
		return true;
	}
	bool get(int x) {
		return pos[x];
	}
};

class ColorfulDecoration {
public:
    int getMaximum(vector <int> xa, vector<int> ya, vector<int> xb, vector<int> yb) {
		int n = xa.size();
		int64_t ok = 0, ng = 1e15;
		while(abs(ok - ng) > 1) {
			TwoSatisfiability sat(n);
			int64_t mid = (ok + ng) / 2;
			for(int i = 0; i < n; ++i) {
				for(int j = i + 1; j < n; ++j) {
					for(int mask = 0; mask < (1 << 2); ++mask) {
						bool ipos = (mask & 1);
						bool jpos = ((mask >> 1) & 1);
						int xi = (ipos ? xa[i] : xb[i]);
						int yi = (ipos ? ya[i] : yb[i]);
						int xj = (jpos ? xa[j] : xb[j]);
						int yj = (jpos ? ya[j] : yb[j]);
						if(abs(xi - xj) < mid and abs(yi - yj) < mid) {
							sat.addNAND(i, ipos, j, jpos);
						}
					}
				}
			}
			if(sat.solve()) {
				ok = mid;
			} else {
				ng = mid;
			}
		}
		return ok;
    }
};
