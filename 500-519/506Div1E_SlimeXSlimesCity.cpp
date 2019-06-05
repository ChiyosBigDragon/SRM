#include <bits/stdc++.h>
using namespace std;

class SlimeXSlimesCity {
public:
   int merge( vector <int> population ) {
       int n=population.size();
       sort(population.begin(),population.end());
       population.push_back(0);

       bool b[n];
       long long sum=0;
       for(int i=0;i<n;i++){
           sum+=population[i];
           if(sum>=population[i+1]) b[i]=1;
           else b[i]=0;
       }
       int ans=0;
       for(int i=n-1;i>=0;i--){
           if(b[i]) ans++;
           else break;
       }
       return ans;
   }
};
