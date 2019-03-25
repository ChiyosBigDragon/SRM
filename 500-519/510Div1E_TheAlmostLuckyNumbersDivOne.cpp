#include <bits/stdc++.h>
using namespace std;

class TheAlmostLuckyNumbersDivOne {
public:
    vector<int> init(long long n) {
       vector<int> v;
       while(n>0){
           v.push_back(n%10);
           n/=10;
       }
       reverse(v.begin(),v.end());
       return v;
    }

    long long count(vector<int> v) {
        int S=v.size();
        long long ret=0;
        for(int i=0;i<S;i++){
            if(i==0&&v[i]==1&&S!=1) continue;
            int unlucky=0;
            for(int j=0;j<i;j++){
                int n=v[j];
                if(n!=4&&n!=7) unlucky++;
            }
            if(i==S-1){
                for(int j=(S==1?1:0);j<=v[i];j++){
                    if(unlucky==0) ret++;
                    else if(unlucky==1&&(j==4||j==7)) ret++;
                }
            }else{
                for(int j=(i==0?1:0);j<=v[i]-1;j++){
                    if(j!=4&&j!=7) unlucky++;
                    if(unlucky==0) ret+=pow(2,(S-i-1))+8*(S-i-1)*pow(2,(S-i-2));
                    else if(unlucky==1) ret+=pow(2,(S-i-1));
                    if(j!=4&&j!=7) unlucky--;
                }
            }
        }
        return ret;
    }

    long long find( long long a, long long b ) {
       vector<int>low=init(--a);
       int L=low.size();
       vector<int>high=init(b);
       int H=high.size();

       long long ans=0;
       for(int i=1;i<H;i++) ans+=pow(2,i-1)*(8*i+1);
       ans+=count(high);
       for(int i=1;i<L;i++) ans-=pow(2,i-1)*(8*i+1);
       ans-=count(low);
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
			long long a               = 8;
			long long b               = 19;
			long long expected__      = 4;

			std::clock_t start__      = std::clock();
			long long received__      = TheAlmostLuckyNumbersDivOne().find(a, b);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			long long a               = 2;
			long long b               = 37;
			long long expected__      = 14;

			std::clock_t start__      = std::clock();
			long long received__      = TheAlmostLuckyNumbersDivOne().find(a, b);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			long long a               = 723696;
			long long b               = 846400;
			long long expected__      = 648;

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
