#include <bits/stdc++.h>
using namespace std;

class FoxProgression {
public:
   int theCount( vector <int> seq ) {
       if(seq.size()==1) return -1;

       vector<int> ari,geo;
       int only=seq[0]; bool ret=1;
       for(auto itr=seq.begin()+1;itr!=seq.end();itr++){
           int n=*(itr-1),m=*itr;
           if(only!=m) ret=0;
           ari.push_back(m-n);
       }
       if(ret) return 1;

       int ans=0; int n=ari[0]; bool flg=1;
       for(auto itr=ari.begin();itr!=ari.end();itr++){
           if(*itr!=n) flg=0;
       }
       if(flg) ans++;

       for(auto itr=seq.begin()+1;itr!=seq.end();itr++){
           int n=*(itr-1),m=*itr;
           if(m%n==0) geo.push_back(m/n);
           else return ans;
       }

       n=geo[0]; flg=1;
       for(auto itr=geo.begin();itr!=geo.end();itr++){
           if(*itr!=n) flg=0;
       }
       if(flg&&n!=0) ans++;

       return ans;
   }
};
