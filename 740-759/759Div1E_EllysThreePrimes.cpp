#include <bits/stdc++.h>
using namespace std;

class EllysThreePrimes {
public:
    vector<int> Sieve_of_Eratosthenes(int n){
    	bool list[n]; for(int i=0;i<n;i++) list[i]=1; //全数にフラグ
    	//2の倍数,3の倍数…と削っていく
        for(int i=2;i*i<n;i++){
            if(list[i]){
                for(int j=2;i*j<n;j++) list[i*j]=0;
            }
        }
    	vector<int> ret;
        for(int i=1e4;i<n;i++){
            if(list[i]) ret.push_back(i);
        }
        return ret;
    }
    vector <int> getPrimes( vector <int> sums ){
        vector<int> prime=Sieve_of_Eratosthenes(1e5);
        int n=prime.size();
        for(int a=0;a<n;a++){
            for(int b=a+1;b<n;b++){
                int i=prime[a],j=prime[b];
                int num=0;
                bool flg=1;
                int one=sums[0]-i%10-j%10;
                if(one>9||one<0||one%2==0||one==5) continue;
                int ii=i,jj=j;
                for(int k=4,tmp=1e4;k>=0;k--,tmp/=10){
                    int c=sums[k]-ii/tmp-jj/tmp;
                    if(c<0||c>9){
                        flg=0;
                        break;
                    }
                    num+=c*tmp;
                    ii%=tmp,jj%=tmp;
                }
                if(num<1e4 || !flg) continue;
                if(i==num||j==num) continue;
                if(!binary_search(prime.begin(),prime.end(),num)) continue;
                return {i,j,num};
            }
        }
        return {};
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

	template<typename T> std::ostream& operator<<(std::ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi=v.begin(); vi!=v.end(); ++vi) { if (vi != v.begin()) os << ","; os << " " << *vi; } os << " }"; return os; }

	int verify_case(int casenum, const vector <int> &expected, const vector <int> &received, std::clock_t elapsed) {
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
			int sums[]                = {19, 12, 15, 11, 14};
			int expected__[]          = {20533, 87119, 44987 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = EllysThreePrimes().getPrimes(vector <int>(sums, sums + (sizeof sums / sizeof sums[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 1: {
			int sums[]                = {22, 19, 3, 8, 23};
			int expected__[]          = { };

			std::clock_t start__      = std::clock();
			vector <int> received__   = EllysThreePrimes().getPrimes(vector <int>(sums, sums + (sizeof sums / sizeof sums[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 2: {
			int sums[]                = {13, 17, 0, 25, 20};
			int expected__[]          = {27011, 99083, 99089 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = EllysThreePrimes().getPrimes(vector <int>(sums, sums + (sizeof sums / sizeof sums[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 3: {
			int sums[]                = {11, 12, 13, 14, 15};
			int expected__[]          = {47221, 23789, 94421 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = EllysThreePrimes().getPrimes(vector <int>(sums, sums + (sizeof sums / sizeof sums[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 4: {
			int sums[]                = {14, 27, 6, 12, 15};
			int expected__[]          = { };

			std::clock_t start__      = std::clock();
			vector <int> received__   = EllysThreePrimes().getPrimes(vector <int>(sums, sums + (sizeof sums / sizeof sums[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int sums[]                = ;
			int expected__[]          = ;

			std::clock_t start__      = std::clock();
			vector <int> received__   = EllysThreePrimes().getPrimes(vector <int>(sums, sums + (sizeof sums / sizeof sums[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 6: {
			int sums[]                = ;
			int expected__[]          = ;

			std::clock_t start__      = std::clock();
			vector <int> received__   = EllysThreePrimes().getPrimes(vector <int>(sums, sums + (sizeof sums / sizeof sums[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 7: {
			int sums[]                = ;
			int expected__[]          = ;

			std::clock_t start__      = std::clock();
			vector <int> received__   = EllysThreePrimes().getPrimes(vector <int>(sums, sums + (sizeof sums / sizeof sums[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
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
