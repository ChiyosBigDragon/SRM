#include <bits/stdc++.h>
using namespace std;
const int INF=1145141919;
const long long LINF=8931145141919364364;

class FightMonsterDiv1 {
public:
    bool calc(long long h,long long a,long long l, long long d, long long n){
        // nomagic
        if(h<=a*n+(a/100*l)*(n*(n-1)/2)) return true;
        // magic
        if(d+1<=n){
            long long x=n-d-1;
            long long sum=a*x+(a/100*l)*(x*(x+1)/2-x);
            h-=sum;
            long long sum1=a*(n-1)+(a/100*l)*((n-1)*(n-2)/2)-(a*x+(a/100*l)*(x*(x-1)/2));
            h-=5*sum1;
            if(h<=0) return true;
        }else{
            n--;
            long long sum=a*n+(a/100*l)*(n*(n-1)/2);
            if(h<=5*sum) return true;
        }
        return false;
    }
    long long fightTime( long long hp, long long attack, int level, long long duration ){
        long long ok=1;
        while(1){
            if(!calc(hp,attack,level,duration,ok)){
                ok*=2;
            }
            else break;
        }
        long long ng=ok/2;
        while(abs(ng-ok)>1){
            long long n=(ok+ng)/2;
            if(calc(hp,attack,level,duration,n)){
                ok=n;
            }else{
                ng=n;
            }
        }
        return ok;
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
			long long hp              = 201;
			long long attack          = 100;
			int level                 = 10;
			long long duration        = 10;
			long long expected__      = 2;

			std::clock_t start__      = std::clock();
			long long received__      = FightMonsterDiv1().fightTime(hp, attack, level, duration);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			long long hp              = 74900;
			long long attack          = 100;
			int level                 = 0;
			long long duration        = 2;
			long long expected__      = 742;

			std::clock_t start__      = std::clock();
			long long received__      = FightMonsterDiv1().fightTime(hp, attack, level, duration);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			long long hp              = 1000000000000LL;
			long long attack          = 1000000000000LL;
			int level                 = 100;
			long long duration        = 1000000000000LL;
			long long expected__      = 1;

			std::clock_t start__      = std::clock();
			long long received__      = FightMonsterDiv1().fightTime(hp, attack, level, duration);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			long long hp              = 1338;
			long long attack          = 100;
			int level                 = 1;
			long long duration        = 2;
			long long expected__      = 6;

			std::clock_t start__      = std::clock();
			long long received__      = FightMonsterDiv1().fightTime(hp, attack, level, duration);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

        case 4: {
			long long hp              = 1000000000000;
			long long attack          = 100;
			int level                 = 1;
			long long duration        = 1;
			long long expected__      = 1414112;

			std::clock_t start__      = std::clock();
			long long received__      = FightMonsterDiv1().fightTime(hp, attack, level, duration);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
        case 5: {
			long long hp              = 980;
			long long attack          = 100;
			int level                 = 10;
			long long duration        = 1;
			long long expected__      = 5;

			std::clock_t start__      = std::clock();
			long long received__      = FightMonsterDiv1().fightTime(hp, attack, level, duration);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
/*      case 6: {
			long long hp              = ;
			long long attack          = ;
			int level                 = ;
			long long duration        = ;
			long long expected__      = ;

			std::clock_t start__      = std::clock();
			long long received__      = FightMonsterDiv1().fightTime(hp, attack, level, duration);
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
