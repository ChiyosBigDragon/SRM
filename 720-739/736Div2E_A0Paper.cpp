#include <bits/stdc++.h>
using namespace std;

class A0Paper {
public:
   string canBuild( vector <int> A ) {
       reverse(A.begin(),A.end());
       for(auto i=A.begin();i!=A.end();i++){
           *(i+1)+=*i/2;
       }
       if(A.back()>0) return "Possible";
       return "Impossible";
   }
};
