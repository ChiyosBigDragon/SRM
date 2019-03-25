#include <bits/stdc++.h>
using namespace std;
const int MAX_C=1000;
const int MOD=9;

long long Com[MAX_C][MAX_C];

class LuckyRemainder {
public:
    void calc_com() {
        memset(Com, 0, sizeof(Com));
        Com[0][0] = 1;
        for (int i = 1; i < MAX_C; ++i) {
            Com[i][0] = 1;
            for (int j = 1; j < MAX_C; ++j) {
                Com[i][j] = (Com[i-1][j-1] + Com[i-1][j]) % MOD;
            }
        }
    }

    int getLuckyRemainder( string X ) {
        //前処理
        calc_com();
        int n=X.size();
        long long ans=0;
        // 位置
        for(int i=0;i<n;i++){
            long long num=X[i]-'0';
            // num*10^jの出現回数
            for(int j=0;j<n;j++){
                // 桁数
                for(int k=0;k<n;k++){
                    if(k-j>=0&&n-i-1>=0) ans+=num*Com[i][k-j]*Com[n-i-1][j];
                    ans%=MOD;
                }
            }
        }
        return ans;
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
			string X                  = "123";
			int expected__            = 6;

			std::clock_t start__      = std::clock();
			int received__            = LuckyRemainder().getLuckyRemainder(X);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string X                  = "24816";
			int expected__            = 3;

			std::clock_t start__      = std::clock();
			int received__            = LuckyRemainder().getLuckyRemainder(X);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string X                  = "9999929999999999999999999999999999999999";
			int expected__            = 7;

			std::clock_t start__      = std::clock();
			int received__            = LuckyRemainder().getLuckyRemainder(X);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string X                  = "11235813213455";
			int expected__            = 7;

			std::clock_t start__      = std::clock();
			int received__            = LuckyRemainder().getLuckyRemainder(X);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			string X                  = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = LuckyRemainder().getLuckyRemainder(X);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			string X                  = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = LuckyRemainder().getLuckyRemainder(X);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string X                  = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = LuckyRemainder().getLuckyRemainder(X);
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
