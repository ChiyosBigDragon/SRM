#include <bits/stdc++.h>
using namespace std;
const int MOD=1e9+9;

class YetAnotherIncredibleMachine {
public:
    int countWays( vector <int> platformMount, vector <int> platformLength, vector <int> balls ){
        // ボールの処理
        int ball[40010]={};
        for(auto i:balls) ball[i+20000]++;
        for(int i=1;i<40010;i++) ball[i]+=ball[i-1];
        // かぞえよう
        long long ret=1;
        int n=platformMount.size();
        for(int i=0;i<n;i++){
            int left=platformMount[i]-platformLength[i]+20000;
            int right=left+platformLength[i];
            long long sum=0;
            for(;left<=platformMount[i]+20000;left++,right++){
                // printf("(%d,%d):%d\n",left-20000,right-20000,ball[right]-ball[left-1]);
                if(ball[left-1]==ball[right]) sum++;
            }
            ret*=sum;
            ret%=MOD;
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
			int platformMount[]       = {7};
			int platformLength[]      = {10};
			int balls[]               = {3,4};
			int expected__            = 3;

			std::clock_t start__      = std::clock();
			int received__            = YetAnotherIncredibleMachine().countWays(vector <int>(platformMount, platformMount + (sizeof platformMount / sizeof platformMount[0])), vector <int>(platformLength, platformLength + (sizeof platformLength / sizeof platformLength[0])), vector <int>(balls, balls + (sizeof balls / sizeof balls[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int platformMount[]       = {1,4};
			int platformLength[]      = {3,3};
			int balls[]               = {2,7};
			int expected__            = 1;

			std::clock_t start__      = std::clock();
			int received__            = YetAnotherIncredibleMachine().countWays(vector <int>(platformMount, platformMount + (sizeof platformMount / sizeof platformMount[0])), vector <int>(platformLength, platformLength + (sizeof platformLength / sizeof platformLength[0])), vector <int>(balls, balls + (sizeof balls / sizeof balls[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int platformMount[]       = {4,4,4};
			int platformLength[]      = {10,9,8};
			int balls[]               = {1,100};
			int expected__            = 27;

			std::clock_t start__      = std::clock();
			int received__            = YetAnotherIncredibleMachine().countWays(vector <int>(platformMount, platformMount + (sizeof platformMount / sizeof platformMount[0])), vector <int>(platformLength, platformLength + (sizeof platformLength / sizeof platformLength[0])), vector <int>(balls, balls + (sizeof balls / sizeof balls[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int platformMount[]       = {0};
			int platformLength[]      = {1};
			int balls[]               = {0};
			int expected__            = 0;

			std::clock_t start__      = std::clock();
			int received__            = YetAnotherIncredibleMachine().countWays(vector <int>(platformMount, platformMount + (sizeof platformMount / sizeof platformMount[0])), vector <int>(platformLength, platformLength + (sizeof platformLength / sizeof platformLength[0])), vector <int>(balls, balls + (sizeof balls / sizeof balls[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int platformMount[]       = {100, -4215, 251};
			int platformLength[]      = {400, 10000, 2121};
			int balls[]               = {5000, 2270, 8512, 6122};
			int expected__            = 250379170;

			std::clock_t start__      = std::clock();
			int received__            = YetAnotherIncredibleMachine().countWays(vector <int>(platformMount, platformMount + (sizeof platformMount / sizeof platformMount[0])), vector <int>(platformLength, platformLength + (sizeof platformLength / sizeof platformLength[0])), vector <int>(balls, balls + (sizeof balls / sizeof balls[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int platformMount[]       = ;
			int platformLength[]      = ;
			int balls[]               = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = YetAnotherIncredibleMachine().countWays(vector <int>(platformMount, platformMount + (sizeof platformMount / sizeof platformMount[0])), vector <int>(platformLength, platformLength + (sizeof platformLength / sizeof platformLength[0])), vector <int>(balls, balls + (sizeof balls / sizeof balls[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int platformMount[]       = ;
			int platformLength[]      = ;
			int balls[]               = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = YetAnotherIncredibleMachine().countWays(vector <int>(platformMount, platformMount + (sizeof platformMount / sizeof platformMount[0])), vector <int>(platformLength, platformLength + (sizeof platformLength / sizeof platformLength[0])), vector <int>(balls, balls + (sizeof balls / sizeof balls[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int platformMount[]       = ;
			int platformLength[]      = ;
			int balls[]               = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = YetAnotherIncredibleMachine().countWays(vector <int>(platformMount, platformMount + (sizeof platformMount / sizeof platformMount[0])), vector <int>(platformLength, platformLength + (sizeof platformLength / sizeof platformLength[0])), vector <int>(balls, balls + (sizeof balls / sizeof balls[0])));
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
