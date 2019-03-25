#include <bits/stdc++.h>
using namespace std;

class BinaryCards {
public:
    // 最上位bit
    unsigned long long MSB(unsigned long long n){
        n=n&0xFFFFFFFF00000000?n&0xFFFFFFFF00000000:n;
        n=n&0xFFFF0000FFFF0000?n&0xFFFF0000FFFF0000:n;
        n=n&0xFF00FF00FF00FF00?n&0xFF00FF00FF00FF00:n;
        n=n&0xF0F0F0F0F0F0F0F0?n&0xF0F0F0F0F0F0F0F0:n;
        n=n&0xCCCCCCCCCCCCCCCC?n&0xCCCCCCCCCCCCCCCC:n;
        n=n&0xAAAAAAAAAAAAAAAA?n&0xAAAAAAAAAAAAAAAA:n;
        return n;
    }
    long long largestNumber( long long A, long long B ){
        long long diff=MSB(A^B);
        return (B|(max(diff-1,0ll)));
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
			long long A               = 6;
			long long B               = 6;
			long long expected__      = 6;

			std::clock_t start__      = std::clock();
			long long received__      = BinaryCards().largestNumber(A, B);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			long long A               = 6;
			long long B               = 7;
			long long expected__      = 7;

			std::clock_t start__      = std::clock();
			long long received__      = BinaryCards().largestNumber(A, B);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			long long A               = 6;
			long long B               = 8;
			long long expected__      = 15;

			std::clock_t start__      = std::clock();
			long long received__      = BinaryCards().largestNumber(A, B);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			long long A               = 1;
			long long B               = 11;
			long long expected__      = 15;

			std::clock_t start__      = std::clock();
			long long received__      = BinaryCards().largestNumber(A, B);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			long long A               = 35;
			long long B               = 38;
			long long expected__      = 39;

			std::clock_t start__      = std::clock();
			long long received__      = BinaryCards().largestNumber(A, B);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			long long A               = 1125899906842630LL;
			long long B               = 1125899906842632LL;
			long long expected__      = 1125899906842639LL;

			std::clock_t start__      = std::clock();
			long long received__      = BinaryCards().largestNumber(A, B);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			long long A               = ;
			long long B               = ;
			long long expected__      = ;

			std::clock_t start__      = std::clock();
			long long received__      = BinaryCards().largestNumber(A, B);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			long long A               = ;
			long long B               = ;
			long long expected__      = ;

			std::clock_t start__      = std::clock();
			long long received__      = BinaryCards().largestNumber(A, B);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			long long A               = ;
			long long B               = ;
			long long expected__      = ;

			std::clock_t start__      = std::clock();
			long long received__      = BinaryCards().largestNumber(A, B);
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
