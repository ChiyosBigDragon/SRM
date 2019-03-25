#include <bits/stdc++.h>
using namespace std;

vector<int> edge[1010];
bool used[1010];
int dp[1010][2];

class MaxCutFree {
public:
    struct UnionFind{
        const int V;
        vector<int> par;
        vector<int> sz;
        UnionFind(const int V):V(V){
            par.resize(V+1);
            for(int i=0;i<=V;i++) par[i]=i;
            sz.resize(V+1,1);
        }
        bool unite(int x,int y){
            x=root(x),y=root(y);
            if(same(x,y)) return false;
            if(y<x) swap(x,y);
            par[y]=x;
            sz[x]+=sz[y];
            return true;
        }
        int root(int x){
        	if(par[x]==x) return x; // xはroot
        	return (par[x]=root(par[x])); // xの親のroot
        }
        bool same(int x,int y){
        	return (root(x)==root(y));
        }
        int size(int x){
            return sz[root(x)];
        }
    };
    void dfs(int from){
        if(used[from]) return;
        used[from]=1;
        bool leaf=1;
        for(int to:edge[from]){
            if(!used[to]){
                leaf=0;
                dfs(to);
                dp[from][0]+=max(dp[to][0],dp[to][1]);
                dp[from][1]+=dp[to][0];
            }
        }
        if(leaf){
            dp[from][0]=0;
            dp[from][1]=1;
        }
    }
    void init(){
        for(int i=0;i<1010;i++){
            edge[i].clear();
            used[i]=0;
            dp[i][0]=0;
            dp[i][1]=1;
        }
    }
    int solve( int n, vector <int> a, vector <int> b ){
        init();
        int m=a.size();
        for(int i=0;i<m;i++){
            UnionFind uf(n);
            for(int j=0;j<m;j++){
                if(i==j) continue;
                uf.unite(a[j],b[j]);
            }
            if(!uf.same(a[i],b[i])){
                edge[a[i]].push_back(b[i]);
                edge[b[i]].push_back(a[i]);
            }
        }
        int ret=0;
        for(int i=0;i<n;i++){
            if(!used[i]){
                dfs(i);
                ret+=max(dp[i][0],dp[i][1]);
            }
        }
        return ret;
    }
};

// BEGIN CUT HERE
#include <cstdio>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
namespace moj_harness {
	using std::string;
	using std::vector;
	int run_test_case(int);
	void run_test(int casenum = -1, bool quiet = false) {
		if (casenum != -1) {
			if (run_test_case(casenum) == -1 && !quiet) {
				std::cerr << "Illegal input! Test case " << casenum << " does not exist." << std::endl;
			}
			return;
		}

		int correct = 0, total = 0;
		for (int i=0;; ++i) {
			int x = run_test_case(i);
			if (x == -1) {
				if (i >= 100) break;
				continue;
			}
			correct += x;
			++total;
		}

		if (total == 0) {
			std::cerr << "No test cases run." << std::endl;
		} else if (correct < total) {
			std::cerr << "Some cases FAILED (passed " << correct << " of " << total << ")." << std::endl;
		} else {
			std::cerr << "All " << total << " tests passed!" << std::endl;
		}
	}

	int verify_case(int casenum, const int &expected, const int &received, std::clock_t elapsed) {
		std::cerr << "Example " << casenum << "... ";

		string verdict;
		vector<string> info;
		char buf[100];

		if (elapsed > CLOCKS_PER_SEC / 200) {
			std::sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
			info.push_back(buf);
		}

		if (expected == received) {
			verdict = "PASSED";
		} else {
			verdict = "FAILED";
		}

		std::cerr << verdict;
		if (!info.empty()) {
			std::cerr << " (";
			for (size_t i=0; i<info.size(); ++i) {
				if (i > 0) std::cerr << ", ";
				std::cerr << info[i];
			}
			std::cerr << ")";
		}
		std::cerr << std::endl;

		if (verdict == "FAILED") {
			std::cerr << "    Expected: " << expected << std::endl;
			std::cerr << "    Received: " << received << std::endl;
		}

		return verdict == "PASSED";
	}

	int run_test_case(int casenum__) {
		switch (casenum__) {
		case 0: {
			int n                     = 4;
			int a[]                   = {0, 1, 2, 0};
			int b[]                   = {1, 2, 0, 3};
			int expected__            = 3;

			std::clock_t start__      = std::clock();
			int received__            = MaxCutFree().solve(n, vector <int>(a, a + (sizeof a / sizeof a[0])), vector <int>(b, b + (sizeof b / sizeof b[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int n                     = 6;
			int a[]                   = {0,1,2,3,3};
			int b[]                   = {2,2,3,4,5};
			int expected__            = 4;

			std::clock_t start__      = std::clock();
			int received__            = MaxCutFree().solve(n, vector <int>(a, a + (sizeof a / sizeof a[0])), vector <int>(b, b + (sizeof b / sizeof b[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int n                     = 7;
			int a[]                   = {0,2,4};
			int b[]                   = {1,3,5};
			int expected__            = 4;

			std::clock_t start__      = std::clock();
			int received__            = MaxCutFree().solve(n, vector <int>(a, a + (sizeof a / sizeof a[0])), vector <int>(b, b + (sizeof b / sizeof b[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int n                     = 4;
			int a[]                   = {0,0,0,1,1,2};
			int b[]                   = {1,2,3,2,3,3};
			int expected__            = 4;

			std::clock_t start__      = std::clock();
			int received__            = MaxCutFree().solve(n, vector <int>(a, a + (sizeof a / sizeof a[0])), vector <int>(b, b + (sizeof b / sizeof b[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			int n                     = ;
			int a[]                   = ;
			int b[]                   = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = MaxCutFree().solve(n, vector <int>(a, a + (sizeof a / sizeof a[0])), vector <int>(b, b + (sizeof b / sizeof b[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			int n                     = ;
			int a[]                   = ;
			int b[]                   = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = MaxCutFree().solve(n, vector <int>(a, a + (sizeof a / sizeof a[0])), vector <int>(b, b + (sizeof b / sizeof b[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int n                     = ;
			int a[]                   = ;
			int b[]                   = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = MaxCutFree().solve(n, vector <int>(a, a + (sizeof a / sizeof a[0])), vector <int>(b, b + (sizeof b / sizeof b[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
		default:
			return -1;
		}
	}
}


#include <cstdlib>
int main(int argc, char *argv[]) {
	if (argc == 1) {
		moj_harness::run_test();
	} else {
		for (int i=1; i<argc; ++i)
			moj_harness::run_test(std::atoi(argv[i]));
	}
}
// END CUT HERE
