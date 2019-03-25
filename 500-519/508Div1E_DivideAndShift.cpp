#include <bits/stdc++.h>
using namespace std;

class DivideAndShift {
public:
    vector<int> prime_factorization(int n){
        vector<int> v;
        if(n==1) v.push_back(1);
        int i=2;
        while(n>1){
            if(n%i==0){
                n/=i;
                v.push_back(i);
            }else{
                i++;
            }
        }
        return v;
    }

    int getLeast( int N, int M ) {
        // 素因数分解
        auto v=prime_factorization(N);
        int n=v.size();
        // 1にシフトするときの回数
        int ans=min(M-1,N-M+1);
        // 割り方
        for(int j=0;j<(1<<n);j++){
            int tmp=N,divcnt=0;
            for(int k=0;k<n;k++){
                if(j>>k&1){
                    tmp/=v[k];
                    divcnt++;
                }
            }
            int shiftcnt=min((M-1)%tmp,(tmp-M%tmp+1)%tmp);
            ans=min(ans,shiftcnt+divcnt);
        }
        return ans;
    }
};
