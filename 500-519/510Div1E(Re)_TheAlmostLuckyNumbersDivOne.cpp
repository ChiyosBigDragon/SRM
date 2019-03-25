#include <bits/stdc++.h>
using namespace std;

class TheAlmostLuckyNumbersDivOne {
public:
    long long count(string s){
        int n=s.size();
        // 桁/確定/4.7以外個数/頭0,頭0以外
        long long dp[20][2][20][2]={};
        dp[0][0][0][0]=1;
        for(int i=1;i<=n;i++){
            int num=s[i-1]-'0';
            for(int j=0;j<2;j++){
                for(int d=0;d<=(j?9:num);d++){
                    for(int k=0;k<20;k++){
                        for(int l=0;l<2;l++){
                            if(d==0&&l==0) dp[i][j||d<num][k][l||d!=0]+=dp[i-1][j][k][l];
                            else dp[i][j||d<num][k+(d!=4&&d!=7)][l||d!=0]+=dp[i-1][j][k][l];
                        }
                    }
                }
            }
        }
        long long ret=0;
        for(int j=0;j<2;j++)for(int k=0;k<2;k++){
            ret+=dp[n][j][k][1];
        }
        return ret;
    }

    long long find( long long a, long long b ) {
       string A=to_string(a-1);
       string B=to_string(b);
       return count(B)-count(A);
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

	int verify_case(int casenum, const long long &expected, const long long &received, std::clock_t elapsed) {
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
			long long a               = 97;
			long long b               = 100;
			long long expected__      = 1;

			std::clock_t start__      = std::clock();
			long long received__      = TheAlmostLuckyNumbersDivOne().find(a, b);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			long long a               = 8;
			long long b               = 19;
			long long expected__      = 4;

			std::clock_t start__      = std::clock();
			long long received__      = TheAlmostLuckyNumbersDivOne().find(a, b);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			long long a               = 28;
			long long b               = 33;
			long long expected__      = 0;

			std::clock_t start__      = std::clock();
			long long received__      = TheAlmostLuckyNumbersDivOne().find(a, b);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			long long a               = 12345678900LL;
			long long b               = 98765432100LL;
			long long expected__      = 91136;

			std::clock_t start__      = std::clock();
			long long received__      = TheAlmostLuckyNumbersDivOne().find(a, b);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			long long a               = ;
			long long b               = ;
			long long expected__      = ;

			std::clock_t start__      = std::clock();
			long long received__      = TheAlmostLuckyNumbersDivOne().find(a, b);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			long long a               = ;
			long long b               = ;
			long long expected__      = ;

			std::clock_t start__      = std::clock();
			long long received__      = TheAlmostLuckyNumbersDivOne().find(a, b);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			long long a               = ;
			long long b               = ;
			long long expected__      = ;

			std::clock_t start__      = std::clock();
			long long received__      = TheAlmostLuckyNumbersDivOne().find(a, b);
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
