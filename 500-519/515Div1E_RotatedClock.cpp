#include <bits/stdc++.h>
using namespace std;

class RotatedClock {
public:
    string getEarliest( int hourHand, int minuteHand ){
        int h=hourHand%30*12;
        int ansh=20,ansm=20;
        for(int i=0;i<12;i++){
            hourHand-=30;
            if(hourHand<0) hourHand+=360;
            minuteHand-=30;
            if(minuteHand<0) minuteHand+=360;
            if(minuteHand==h){
                if(hourHand/30<ansh){
                    ansh=hourHand/30;
                    ansm=minuteHand/6;
                }
            }
        }
        string ret;
        if(ansh!=20){
            if(ansh<10) ret+="0";
            ret+=to_string(ansh);
            ret+=":";
            if(ansm<10) ret+="0";
            ret+=to_string(ansm);
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
			int hourHand              = 70;
			int minuteHand            = 300;
			string expected__         = "08:20";

			std::clock_t start__      = std::clock();
			string received__         = RotatedClock().getEarliest(hourHand, minuteHand);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int hourHand              = 90;
			int minuteHand            = 120;
			string expected__         = "11:00";

			std::clock_t start__      = std::clock();
			string received__         = RotatedClock().getEarliest(hourHand, minuteHand);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int hourHand              = 240;
			int minuteHand            = 36;
			string expected__         = "";

			std::clock_t start__      = std::clock();
			string received__         = RotatedClock().getEarliest(hourHand, minuteHand);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int hourHand              = 19;
			int minuteHand            = 19;
			string expected__         = "";

			std::clock_t start__      = std::clock();
			string received__         = RotatedClock().getEarliest(hourHand, minuteHand);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int hourHand              = 1;
			int minuteHand            = 12;
			string expected__         = "00:02";

			std::clock_t start__      = std::clock();
			string received__         = RotatedClock().getEarliest(hourHand, minuteHand);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int hourHand              = ;
			int minuteHand            = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = RotatedClock().getEarliest(hourHand, minuteHand);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int hourHand              = ;
			int minuteHand            = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = RotatedClock().getEarliest(hourHand, minuteHand);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int hourHand              = ;
			int minuteHand            = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = RotatedClock().getEarliest(hourHand, minuteHand);
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
