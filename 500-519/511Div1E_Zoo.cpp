#include <bits/stdc++.h>
using namespace std;

class Zoo {
public:
    long long theCount( vector <int> answers ){
        sort(answers.begin(),answers.end());
        map<int,int> mp;
    	for(auto i:answers) mp[i]++;
        // 値が飛び飛び
        answers.erase(unique(answers.begin(),answers.end()),answers.end());
        int a=answers.size(),b=answers.back();
        if(a!=b+1) return 0;
        // 順番に並んでいるか
        bool flg=0; int n=b;
    	for(auto m:mp){
            int i=m.second;
            // 前半
            if(!flg&&i!=2){
                if(i==1){
                    flg=1;
                    n=m.first;
                }
                else return 0;
            }
            // 後半
            if(flg&&i!=1) return 0;
    	}
        return pow(2,n+1);
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
			int answers[]             = {0, 1, 2, 3, 4};
			long long expected__      = 2;

			std::clock_t start__      = std::clock();
			long long received__      = Zoo().theCount(vector <int>(answers, answers + (sizeof answers / sizeof answers[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int answers[]             = {5, 8};
			long long expected__      = 0;

			std::clock_t start__      = std::clock();
			long long received__      = Zoo().theCount(vector <int>(answers, answers + (sizeof answers / sizeof answers[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int answers[]             = {0, 0, 0, 0, 0, 0};
			long long expected__      = 0;

			std::clock_t start__      = std::clock();
			long long received__      = Zoo().theCount(vector <int>(answers, answers + (sizeof answers / sizeof answers[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int answers[]             = {1, 0, 2, 0, 1};
			long long expected__      = 8;

			std::clock_t start__      = std::clock();
			long long received__      = Zoo().theCount(vector <int>(answers, answers + (sizeof answers / sizeof answers[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int answers[]             = {1, 0, 1};
			long long expected__      = 0;

			std::clock_t start__      = std::clock();
			long long received__      = Zoo().theCount(vector <int>(answers, answers + (sizeof answers / sizeof answers[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int answers[]             = ;
			long long expected__      = ;

			std::clock_t start__      = std::clock();
			long long received__      = Zoo().theCount(vector <int>(answers, answers + (sizeof answers / sizeof answers[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int answers[]             = ;
			long long expected__      = ;

			std::clock_t start__      = std::clock();
			long long received__      = Zoo().theCount(vector <int>(answers, answers + (sizeof answers / sizeof answers[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int answers[]             = ;
			long long expected__      = ;

			std::clock_t start__      = std::clock();
			long long received__      = Zoo().theCount(vector <int>(answers, answers + (sizeof answers / sizeof answers[0])));
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
