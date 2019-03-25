#include <bits/stdc++.h>
using namespace std;

class TheAlmostLuckyNumbersDivOne {
public:
    long long count(string s){
        int n=s.size();
        // 桁/確定/4.7以外個数/頭0,頭0以外
        long long dp[20][2][20][2]={};
        dp[0][0][0][0]=1;
        for(int i=1;i<=n;i++){
            int num=s[i-1]-'0';
            for(int j=0;j<2;j++){
                for(int d=0;d<=(j?9:num);d++){
                    for(int k=0;k<20;k++){
                        for(int l=0;l<2;l++){
                            if(d==0&&l==0) dp[i][j||d<num][k][l||d!=0]+=dp[i-1][j][k][l];
                            else dp[i][j||d<num][k+(d!=4&&d!=7)][l||d!=0]+=dp[i-1][j][k][l];
                        }
                    }
                }
            }
        }
        long long ret=0;
        for(int j=0;j<2;j++)for(int k=0;k<2;k++){
            ret+=dp[n][j][k][1];
        }
        return ret;
    }

    long long find( long long a, long long b ) {
       string A=to_string(a-1);
       string B=to_string(b);
       return count(B)-count(A);
    }
};
