#include <bits/stdc++.h>
using namespace std;

class NetworkXOneTimePad {
public:
    int crack( vector <string> plaintexts, vector <string> ciphertexts ){
        vector<long long> p,c;
        for(auto i:plaintexts){
            string s=i; reverse(s.begin(),s.end());
            long long a=1,sum=0;
            for(auto j:i){
                sum+=a*(j-'0');
                a<<=1;
            }
            p.push_back(sum);
        }
        for(auto i:ciphertexts){
            string s=i; reverse(s.begin(),s.end());
            long long a=1,sum=0;
            for(auto j:i){
                sum+=a*(j-'0');
                a<<=1;
            }
            c.push_back(sum);
        }
        int ret=0;
        for(auto i:p){
            long long key=c[0]^i;
            bool flg1=1;
            for(auto j:c){
                bool flg2=0;
                for(auto k:p){
                    if((j^key)==k) flg2=1;
                }
                if(!flg2) flg1=0;
            }
            if(flg1) ret++;
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
			string plaintexts[]       = {"110", "001"};
			string ciphertexts[]      = {"101", "010"};
			int expected__            = 2;

			std::clock_t start__      = std::clock();
			int received__            = NetworkXOneTimePad().crack(vector <string>(plaintexts, plaintexts + (sizeof plaintexts / sizeof plaintexts[0])), vector <string>(ciphertexts, ciphertexts + (sizeof ciphertexts / sizeof ciphertexts[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string plaintexts[]       = {"00", "01", "10", "11"};
			string ciphertexts[]      = {"00", "01", "10", "11"};
			int expected__            = 4;

			std::clock_t start__      = std::clock();
			int received__            = NetworkXOneTimePad().crack(vector <string>(plaintexts, plaintexts + (sizeof plaintexts / sizeof plaintexts[0])), vector <string>(ciphertexts, ciphertexts + (sizeof ciphertexts / sizeof ciphertexts[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string plaintexts[]       = {"01", "10"};
			string ciphertexts[]      = {"00"};
			int expected__            = 2;

			std::clock_t start__      = std::clock();
			int received__            = NetworkXOneTimePad().crack(vector <string>(plaintexts, plaintexts + (sizeof plaintexts / sizeof plaintexts[0])), vector <string>(ciphertexts, ciphertexts + (sizeof ciphertexts / sizeof ciphertexts[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string plaintexts[]       = {"000", "111", "010", "101", "110", "001"};
			string ciphertexts[]      = {"011", "100"};
			int expected__            = 6;

			std::clock_t start__      = std::clock();
			int received__            = NetworkXOneTimePad().crack(vector <string>(plaintexts, plaintexts + (sizeof plaintexts / sizeof plaintexts[0])), vector <string>(ciphertexts, ciphertexts + (sizeof ciphertexts / sizeof ciphertexts[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			string plaintexts[]       = ;
			string ciphertexts[]      = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = NetworkXOneTimePad().crack(vector <string>(plaintexts, plaintexts + (sizeof plaintexts / sizeof plaintexts[0])), vector <string>(ciphertexts, ciphertexts + (sizeof ciphertexts / sizeof ciphertexts[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			string plaintexts[]       = ;
			string ciphertexts[]      = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = NetworkXOneTimePad().crack(vector <string>(plaintexts, plaintexts + (sizeof plaintexts / sizeof plaintexts[0])), vector <string>(ciphertexts, ciphertexts + (sizeof ciphertexts / sizeof ciphertexts[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string plaintexts[]       = ;
			string ciphertexts[]      = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = NetworkXOneTimePad().crack(vector <string>(plaintexts, plaintexts + (sizeof plaintexts / sizeof plaintexts[0])), vector <string>(ciphertexts, ciphertexts + (sizeof ciphertexts / sizeof ciphertexts[0])));
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
