#include <bits/stdc++.h>
using namespace std;
const int MOD=1e9+9;

class YetAnotherIncredibleMachine {
public:
    int countWays( vector <int> platformMount, vector <int> platformLength, vector <int> balls ){
        // ボールの処理
        int ball[40010]={};
        for(auto i:balls) ball[i+20000]++;
        for(int i=1;i<40010;i++) ball[i]+=ball[i-1];
        // かぞえよう
        long long ret=1;
        int n=platformMount.size();
        for(int i=0;i<n;i++){
            int left=platformMount[i]-platformLength[i]+20000;
            int right=left+platformLength[i];
            long long sum=0;
            for(;left<=platformMount[i]+20000;left++,right++){
                // printf("(%d,%d):%d\n",left-20000,right-20000,ball[right]-ball[left-1]);
                if(ball[left-1]==ball[right]) sum++;
            }
            ret*=sum;
            ret%=MOD;
        }
        return ret;
    }
};
