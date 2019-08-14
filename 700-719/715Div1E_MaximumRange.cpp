#include <bits/stdc++.h>
using namespace std;

class MaximumRange {
public:
    int findMax(string s) {
		int plus = 0, minus = 0;
		for(char c : s) {
			if(c == '+') ++plus;
			if(c == '-') ++minus;
		}
		return max(plus, minus);
    }
};
