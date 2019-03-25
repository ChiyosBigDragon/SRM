#include <bits/stdc++.h>
using namespace std;

class PerfectSequences {
public:
   string fixIt( vector <int> seq ) {
       int n=seq.size();
       if(n==1) return "Yes";
       long long PRO[n];
       long long SUM=0;
       for(int i=0;i<n;i++){
           SUM+=seq[i];
           PRO[i]=1;
           for(int j=0;j<n;j++){
               if(j!=i) PRO[i]*=seq[j];
           }
       }
       for(int i=0;i<n;i++){
           long long sum=SUM-seq[i],pro=PRO[i]-1;
           if(pro==0){
               if(sum==0) return "Yes";
               else continue;
           }
           if(sum%pro==0&&sum/pro!=seq[i]&&sum/pro>=0) return "Yes";
       }
       return "No";
   }
};
