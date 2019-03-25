#include <bits/stdc++.h>
using namespace std;

class TheAlmostLuckyNumbersDivOne {
public:
    vector<int> init(long long n) {
       vector<int> v;
       while(n>0){
           v.push_back(n%10);
           n/=10;
       }
       reverse(v.begin(),v.end());
       return v;
    }

    long long count(vector<int> v) {
        int S=v.size();
        long long ret=0;
        for(int i=0;i<S;i++){
            if(i==0&&v[i]==1&&S!=1) continue;
            int unlucky=0;
            for(int j=0;j<i;j++){
                int n=v[j];
                if(n!=4&&n!=7) unlucky++;
            }
            if(i==S-1){
                for(int j=(S==1?1:0);j<=v[i];j++){
                    if(unlucky==0) ret++;
                    else if(unlucky==1&&(j==4||j==7)) ret++;
                }
            }else{
                for(int j=(i==0?1:0);j<=v[i]-1;j++){
                    if(j!=4&&j!=7) unlucky++;
                    if(unlucky==0) ret+=pow(2,(S-i-1))+8*(S-i-1)*pow(2,(S-i-2));
                    else if(unlucky==1) ret+=pow(2,(S-i-1));
                    if(j!=4&&j!=7) unlucky--;
                }
            }
        }
        return ret;
    }

    long long find( long long a, long long b ) {
       vector<int>low=init(--a);
       int L=low.size();
       vector<int>high=init(b);
       int H=high.size();

       long long ans=0;
       for(int i=1;i<H;i++) ans+=pow(2,i-1)*(8*i+1);
       ans+=count(high);
       for(int i=1;i<L;i++) ans-=pow(2,i-1)*(8*i+1);
       ans-=count(low);
       return ans;
    }
};
