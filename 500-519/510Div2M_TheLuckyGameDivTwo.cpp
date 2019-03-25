#include <bits/stdc++.h>
using namespace std;
const int INF=1145141919;

class TheLuckyGameDivTwo {
public:
   int find( int a, int b, int jLen, int bLen ) {
    int lucky[]={4,7,44,47,74,77,444,447,474,477,744,747,774,777,4444,4447,4474,4477,4744,4747};
   	int num[5000]={}; for(auto i:lucky) num[i]=1;
   	for(int i=1;i<5000;i++) num[i]+=num[i-1];
    jLen--; bLen--;

   	int ans=0;
   	for(int i=a;i+jLen<=b;i++){
   		int bSum=INF;
   		for(int j=i;j+bLen<=i+jLen;j++){
   			bSum=min(bSum,num[j+bLen]-num[j-1]);
   		}
   		ans=max(ans,bSum);
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
			int a                     = 1;
			int b                     = 10;
			int jLen                  = 2;
			int bLen                  = 1;
			int expected__            = 0;

			std::clock_t start__      = std::clock();
			int received__            = TheLuckyGameDivTwo().find(a, b, jLen, bLen);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int a                     = 1;
			int b                     = 100;
			int jLen                  = 100;
			int bLen                  = 100;
			int expected__            = 6;

			std::clock_t start__      = std::clock();
			int received__            = TheLuckyGameDivTwo().find(a, b, jLen, bLen);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int a                     = 4;
			int b                     = 8;
			int jLen                  = 3;
			int bLen                  = 2;
			int expected__            = 1;

			std::clock_t start__      = std::clock();
			int received__            = TheLuckyGameDivTwo().find(a, b, jLen, bLen);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int a                     = 1;
			int b                     = 100;
			int jLen                  = 75;
			int bLen                  = 50;
			int expected__            = 2;

			std::clock_t start__      = std::clock();
			int received__            = TheLuckyGameDivTwo().find(a, b, jLen, bLen);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			int a                     = ;
			int b                     = ;
			int jLen                  = ;
			int bLen                  = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = TheLuckyGameDivTwo().find(a, b, jLen, bLen);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			int a                     = ;
			int b                     = ;
			int jLen                  = ;
			int bLen                  = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = TheLuckyGameDivTwo().find(a, b, jLen, bLen);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int a                     = ;
			int b                     = ;
			int jLen                  = ;
			int bLen                  = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = TheLuckyGameDivTwo().find(a, b, jLen, bLen);
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
