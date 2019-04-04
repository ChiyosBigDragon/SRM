#include <bits/stdc++.h>
using namespace std;

struct Combination{
    const int MAX=2010;
    const int MOD;
    vector<vector<int>> COM;
    vector<vector<int>> PER;
    Combination(const int MOD):
        MOD(MOD)
        {
            COM=vector<vector<int>>(MAX,vector<int>(MAX));
            PER=vector<vector<int>>(MAX,vector<int>(MAX));
            COM[0][0]=PER[0][0]=1;
            for(int i=1;i<MAX;i++){
                COM[i][0]=PER[i][0]=1;
                for(int j=1;j<MAX;j++){
                    COM[i][j]=(COM[i-1][j-1]+COM[i-1][j])%MOD;
                    PER[i][j]=PER[i][j-1]*(i-j+1)%MOD;
                }
            }
        }
    int C(int n,int r){
        assert(0<=n&&n<MAX&&0<=r&&r<MAX);
        return COM[n][r];
    }
    int P(int n,int r){
        assert(0<=n&&n<MAX&&0<=r&&r<MAX);
        return PER[n][r];
    }
    int H(int n,int r){
        assert(0<=n+r-1&&n+r-1<MAX&&0<=r&&r<MAX);
        return COM[n+r-1][r];
    }
};

class LuckyRemainder {
public:
    int getLuckyRemainder( string X ){
        const int MOD=9;
        Combination com(MOD);
        int n=X.size();
        int ret=0;
        // 桁
        for(int i=0;i<n;i++){
            int num=X[i]-'0';
            for(int l=0;l<=i;l++){
                for(int r=0;r<n-i;r++){
                    ret+=num*com.C(i,l)*com.C(n-1-i,r);
                    ret%=MOD;
                }
            }
        }
        return ret;
    }
};
