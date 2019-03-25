#include <bits/stdc++.h>
using namespace std;

class RectangleArea {
public:
    int h,w;
    int board[51][51];
    int ret=0;
    // (sy,sx)を1頂点とした長方形について、穴埋め
    void greed(int sy,int sx){
        // 対角の座標で探索
        for(int y=0;y<h;y++){
            for(int x=0;x<w;x++){
                // 長方形でないので×
                if(sy==y||sx==x) continue;
                // 3つの小長方形の面積がわかっている
                if(board[sy][sx]+board[y][sx]+board[sy][x]+board[y][x]==3){
                    if(board[y][sx]==0){
                        board[y][sx]=1;
                        greed(y,sx);
                    }
                    if(board[sy][x]==0){
                        board[sy][x]=1;
                        greed(sy,x);
                    }
                    if(board[y][x]==0){
                        board[y][x]=1;
                        greed(y,x);
                    }
                }
            }
        }
    }
    
    int minimumQueries( vector <string> known ){
        h=known.size();
        w=known[0].size();
        for(int y=0;y<h;y++){
            for(int x=0;x<w;x++){
                if(known[y][x]=='Y') board[y][x]=1;
                else board[y][x]=0;
            }
        }
        // 面積がわかっているところを先に埋める
        for(int y=0;y<h;y++){
            for(int x=0;x<w;x++){
                if(board[y][x]==1){
                    greed(y,x);
                }
            }
        }
        // 質問しないといけないので実行する度に回数+1
        for(int y=0;y<h;y++){
            for(int x=0;x<w;x++){
                if(board[y][x]==0){
                    board[y][x]=1;
                    ret++;
                    greed(y,x);
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
			string known[]            = {"NN",
 "NN"};
			int expected__            = 3;

			std::clock_t start__      = std::clock();
			int received__            = RectangleArea().minimumQueries(vector <string>(known, known + (sizeof known / sizeof known[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string known[]            = {"YNY",
 "NYN",
 "YNY"};
			int expected__            = 1;

			std::clock_t start__      = std::clock();
			int received__            = RectangleArea().minimumQueries(vector <string>(known, known + (sizeof known / sizeof known[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string known[]            = {"YY",
 "YY",
 "YY",
 "YY"};
			int expected__            = 0;

			std::clock_t start__      = std::clock();
			int received__            = RectangleArea().minimumQueries(vector <string>(known, known + (sizeof known / sizeof known[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string known[]            = {"NNNNNNNNNN"};
			int expected__            = 10;

			std::clock_t start__      = std::clock();
			int received__            = RectangleArea().minimumQueries(vector <string>(known, known + (sizeof known / sizeof known[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string known[]            = {"NNYYYNN",
 "NNNNNYN",
 "YYNNNNY",
 "NNNYNNN",
 "YYNNNNY"};
			int expected__            = 2;

			std::clock_t start__      = std::clock();
			int received__            = RectangleArea().minimumQueries(vector <string>(known, known + (sizeof known / sizeof known[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			string known[]            = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = RectangleArea().minimumQueries(vector <string>(known, known + (sizeof known / sizeof known[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string known[]            = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = RectangleArea().minimumQueries(vector <string>(known, known + (sizeof known / sizeof known[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string known[]            = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = RectangleArea().minimumQueries(vector <string>(known, known + (sizeof known / sizeof known[0])));
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
