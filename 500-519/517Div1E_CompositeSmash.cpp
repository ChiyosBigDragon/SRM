#include <bits/stdc++.h>
using namespace std;

// 0=未/1=ok/2=no
int memo[100010];
class CompositeSmash {
public:
    int goal;
    // 素因数分解
    vector<int> prime_factorization(int n){
        vector<int> v;
        if(n==1) v.push_back(1);
        int i=2;
        while(n>1){
            if(n%i==0){
                n/=i;
                v.push_back(i);
            }else{
                i++;
            }
        }
        return v;
    }
    // 探索
    bool dfs(int n,vector<int> v){
        if(memo[n]==1) return true;
        if(memo[n]==2) return false;
        // cout<<n<<endl;
        if(n==goal) {memo[n]=1;return true;}
        // どう割っても無理
        if(n%goal!=0) {memo[n]=2;return false;}
        // 素因数の組み合わせ
        int vv=v.size();
        for(int i=1;i<=vv/2;i++){
            vector<int> p;
            for(int j=0;j<vv-i;j++) p.push_back(0);
            for(int j=0;j<i;j++) p.push_back(1);
            do{
                 vector<int> l,r;
                 int le=1,ri=1;
                 for(int j=0;j<vv;j++){
                     if(p[j]){
                         l.push_back(v[j]);
                         le*=v[j];
                     }else{
                         r.push_back(v[j]);
                         ri*=v[j];
                     }
                 }
                 // cout<<le<<" "<<ri<<endl;
                if(!dfs(le,l)&&!dfs(ri,r)) {memo[n]=2;return false;}
            }while(next_permutation(p.begin(),p.end()));
        }
        memo[n]=1; return true;
    }
    // 判定
    string thePossible( int N, int target ){
        goal=target;
        for(int i=0;i<100010;i++) memo[i]=0;
        if(dfs(N,prime_factorization(N))) return "Yes";
        else return "No";
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

	int verify_case(int casenum, const string &expected, const string &received, std::clock_t elapsed) {
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
			std::cerr << "    Expected: \"" << expected << "\"" << std::endl;
			std::cerr << "    Received: \"" << received << "\"" << std::endl;
		}

		return verdict == "PASSED";
	}

	int run_test_case(int casenum__) {
		switch (casenum__) {
		case 0: {
			int N                     = 517;
			int target                = 47;
			string expected__         = "Yes";

			std::clock_t start__      = std::clock();
			string received__         = CompositeSmash().thePossible(N, target);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int N                     = 8;
			int target                = 4;
			string expected__         = "Yes";

			std::clock_t start__      = std::clock();
			string received__         = CompositeSmash().thePossible(N, target);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int N                     = 12;
			int target                = 6;
			string expected__         = "No";

			std::clock_t start__      = std::clock();
			string received__         = CompositeSmash().thePossible(N, target);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int N                     = 5;
			int target                = 8;
			string expected__         = "No";

			std::clock_t start__      = std::clock();
			string received__         = CompositeSmash().thePossible(N, target);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int N                     = 100000;
			int target                = 100000;
			string expected__         = "Yes";

			std::clock_t start__      = std::clock();
			string received__         = CompositeSmash().thePossible(N, target);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			int N                     = 5858;
			int target                = 2;
			string expected__         = "Yes";

			std::clock_t start__      = std::clock();
			string received__         = CompositeSmash().thePossible(N, target);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 6: {
			int N                     = 81461;
			int target                = 2809;
			string expected__         = "No";

			std::clock_t start__      = std::clock();
			string received__         = CompositeSmash().thePossible(N, target);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 7: {
			int N                     = 65536;
			int target                = 256;
			string expected__         = "No";

			std::clock_t start__      = std::clock();
			string received__         = CompositeSmash().thePossible(N, target);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 8: {
			int N                     = ;
			int target                = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = CompositeSmash().thePossible(N, target);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 9: {
			int N                     = ;
			int target                = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = CompositeSmash().thePossible(N, target);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 10: {
			int N                     = ;
			int target                = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = CompositeSmash().thePossible(N, target);
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
