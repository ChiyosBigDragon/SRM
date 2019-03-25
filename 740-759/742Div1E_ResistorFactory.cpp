#include <bits/stdc++.h>
using namespace std;

class ResistorFactory {
public:
    vector <int> construct( long long nanoOhms ){
        if(nanoOhms==1e9) return {};
        vector<int> ret;
        vector<double> use={1};
        // 構築{1,2,…,2^49,1/2,…,1/2^50}
        for(long long i=1;i<50;i++){
            use.push_back(1LL<<i);
            ret.push_back(i-1);
            ret.push_back(i-1);
            ret.push_back(0);
        }
        use.push_back(0.5);
        ret.push_back(0);
        ret.push_back(0);
        ret.push_back(1);
        for(long long i=2;i<=50;i++){
            use.push_back(pow(2,-i));
            ret.push_back(i+48);
            ret.push_back(i+48);
            ret.push_back(1);
        }
        vector<int> ans;
        long long l=nanoOhms/1e9;
        double r=nanoOhms/1e9-l;
        for(int id=49;id>=0;id--){
            if(l>=use[id]){
                l-=use[id];
                ans.push_back(id);
            }
        }
        for(int id=50;id<100;id++){
            if(r>=use[id]){
                r-=use[id];
                ans.push_back(id);
            }
        }
        // for(auto i:ans) cout<<i<<endl;
        int n=ans.size();
        if(n==1){
            if(ans[0]>1){
                ret.push_back(ans[0]-1);
                ret.push_back(ans[0]-1);
            }else{
                ret.push_back(ans[0]+1);
                ret.push_back(ans[0]+1);
            }
            ret.push_back(0);
        }else{
            ret.push_back(ans[0]);
            ret.push_back(ans[1]);
            ret.push_back(0);
            int cnt=100;
            for(int i=2;i<n;i++){
                ret.push_back(cnt++);
                ret.push_back(ans[i]);
                ret.push_back(0);
            }
        }
        // vector<double> simu={1};
        // int nn=ret.size();
        // for(int i=0;i<nn;i+=3){
        //     if(ret[i+2]==0) simu.push_back(simu[ret[i]]+simu[ret[i+1]]);
        //     else simu.push_back(simu[ret[i]]*simu[ret[i+1]]/(simu[ret[i]]+simu[ret[i+1]]));
        // }
        // printf("%.10lf\n",simu.back());
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
			long long nanoOhms        = 3000000000LL;
			int expected__[]          = {0, 0, 0, 0, 1, 0 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = ResistorFactory().construct(nanoOhms);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 1: {
			long long nanoOhms        = 1200000000;
			int expected__[]          = {0, 0, 0, 1, 0, 0, 1, 2, 1 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = ResistorFactory().construct(nanoOhms);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 2: {
			long long nanoOhms        = 1428571428;
			int expected__[]          = {0, 0, 0, 0, 1, 0, 1, 2, 0, 3, 1, 1 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = ResistorFactory().construct(nanoOhms);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 3: {
			long long nanoOhms        = 12000000001LL;
			int expected__[]          = {0, 0, 0, 0, 1, 0, 2, 2, 0, 3, 3, 0 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = ResistorFactory().construct(nanoOhms);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 4: {
			long long nanoOhms        = 333333333;
			int expected__[]          = {0, 0, 1, 0, 1, 1 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = ResistorFactory().construct(nanoOhms);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			long long nanoOhms        = ;
			int expected__[]          = ;

			std::clock_t start__      = std::clock();
			vector <int> received__   = ResistorFactory().construct(nanoOhms);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 6: {
			long long nanoOhms        = ;
			int expected__[]          = ;

			std::clock_t start__      = std::clock();
			vector <int> received__   = ResistorFactory().construct(nanoOhms);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 7: {
			long long nanoOhms        = ;
			int expected__[]          = ;

			std::clock_t start__      = std::clock();
			vector <int> received__   = ResistorFactory().construct(nanoOhms);
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
