#include <bits/stdc++.h>
using namespace std;
const int INF=1145141919;

class MysteriousRestaurant {
public:
    int calc(char c){
        int ret;
        if('0'<=c&&c<='9') ret=c-'0';
        if('A'<=c&&c<='Z') ret=c-'A'+10;
        if('a'<=c&&c<='z') ret=c-'a'+36;
        return ret;
    }
    int maxDays( vector <string> prices, int budget ){
        int day[7];
        int ret=0,n=prices.size(),m=prices[0].size();
        for(int i=0;i<n;i++){
            if(ret<7){
                string tmp=prices[i];
                sort(tmp.begin(),tmp.end());
                char c=tmp.front();
                int cost=calc(c);
                if(budget-cost>=0){
                    day[i]=cost;
                    budget-=cost;
                    ret++;
                }else{
                    return ret;
                }
            }else{
                budget+=day[i%7];
                int cost=INF;
                for(int j=0;j<m;j++){
                    int sum=0;
                    for(int k=i;k>=0;k-=7){
                        sum+=calc(prices[k][j]);
                    }
                    cost=min(cost,sum);
                }
                if(budget-cost>=0){
                    day[i%7]=cost;
                    budget-=cost;
                    ret++;
                }else{
                    return ret;
                }
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
			string prices[]           = {"26", "14", "72", "39", "32", "85", "06"};
			int budget                = 13;
			int expected__            = 5;

			std::clock_t start__      = std::clock();
			int received__            = MysteriousRestaurant().maxDays(vector <string>(prices, prices + (sizeof prices / sizeof prices[0])), budget);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string prices[]           = {"26", "14", "72", "39", "32", "85", "06", "91"};
			int budget                = 20;
			int expected__            = 8;

			std::clock_t start__      = std::clock();
			int received__            = MysteriousRestaurant().maxDays(vector <string>(prices, prices + (sizeof prices / sizeof prices[0])), budget);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string prices[]           = {"SRM", "512"};
			int budget                = 4;
			int expected__            = 0;

			std::clock_t start__      = std::clock();
			int received__            = MysteriousRestaurant().maxDays(vector <string>(prices, prices + (sizeof prices / sizeof prices[0])), budget);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string prices[]           = {"Dear", "Code", "rsHa", "veFu", "nInT", "heCh", "alle", "ngeP", "hase", "andb", "ecar", "eful"};
			int budget                = 256;
			int expected__            = 10;

			std::clock_t start__      = std::clock();
			int received__            = MysteriousRestaurant().maxDays(vector <string>(prices, prices + (sizeof prices / sizeof prices[0])), budget);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			string prices[]           = ;
			int budget                = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = MysteriousRestaurant().maxDays(vector <string>(prices, prices + (sizeof prices / sizeof prices[0])), budget);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			string prices[]           = ;
			int budget                = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = MysteriousRestaurant().maxDays(vector <string>(prices, prices + (sizeof prices / sizeof prices[0])), budget);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string prices[]           = ;
			int budget                = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = MysteriousRestaurant().maxDays(vector <string>(prices, prices + (sizeof prices / sizeof prices[0])), budget);
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
