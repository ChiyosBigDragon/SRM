#include <bits/stdc++.h>
using namespace std;
const int MAX_C=1000;
const int MOD=9;

long long Com[MAX_C][MAX_C];

class LuckyRemainder {
public:
    void calc_com() {
        memset(Com, 0, sizeof(Com));
        Com[0][0] = 1;
        for (int i = 1; i < MAX_C; ++i) {
            Com[i][0] = 1;
            for (int j = 1; j < MAX_C; ++j) {
                Com[i][j] = (Com[i-1][j-1] + Com[i-1][j]) % MOD;
            }
        }
    }

    int getLuckyRemainder( string X ) {
        //前処理
        calc_com();
        int n=X.size();
        long long ans=0;
        // 位置
        for(int i=0;i<n;i++){
            long long num=X[i]-'0';
            // num*10^jの出現回数
            for(int j=0;j<n;j++){
                // 桁数
                for(int k=0;k<n;k++){
                    if(k-j>=0&&n-i-1>=0) ans+=num*Com[i][k-j]*Com[n-i-1][j];
                    ans%=MOD;
                }
            }
        }
        return ans;
    }
};
