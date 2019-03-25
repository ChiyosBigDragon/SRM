#include <bits/stdc++.h>
using namespace std;

class TheNumbersWithLuckyLastDigit {
public:
   int find( int n ) {
       int di[]={5,2,3,5,1,3,4,1,2,4};
       int mi[]={20,11,12,23,4,15,16,7,8,19};
       int i=n%10;
       if(n>=mi[i]) return di[i];
       return -1;
   }
};
