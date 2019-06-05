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
