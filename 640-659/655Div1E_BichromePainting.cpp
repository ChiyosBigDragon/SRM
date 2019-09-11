#include <bits/stdc++.h>
using namespace std;

class BichromePainting {
public:
    string isThatPossible(vector<string> board, int k) {
		int n = board.size();
		while(true) {
			bool find = false;
			for(int y = 0; y + k <= n; ++y) {
				for(int x = 0; x + k <= n; ++x) {
					bool black = true;
					bool white = true;
					for(int dy = 0; dy < k; ++dy) {
						int ny = y + dy;
						for(int dx = 0; dx < k; ++dx) {
							int nx = x + dx;
							if(board[ny][nx] == 'B') white = false;
							if(board[ny][nx] == 'W') black = false;
						}
					}
					if(black or white) {
						for(int dy = 0; dy < k; ++dy) {
							int ny = y + dy;
							for(int dx = 0; dx < k; ++dx) {
								int nx = x + dx;
								find |= (board[ny][nx] != 'T');
								board[ny][nx] = 'T';
							}
						}
					}
				}
			}
			if(not find) {
				for(int y = 0; y < n; ++y) {
					for(int x = 0; x < n; ++x) {
						if(board[y][x] != 'T') {
							return "Impossible";
						}
					}
				}
				return "Possible";
			}
		}
    }
};

