#include <bits/stdc++.h>
using namespace std;

class SRMCards {
public:
   int maxTurns( vector <int> cards ) {
       sort(cards.begin(),cards.end());

       int ret=0;
       while(cards.size()){
           ret++;
           int i=cards[0]; cards.erase(cards.begin());
           if(cards.size()&&cards[0]==i+1){
               cards.erase(cards.begin());
           }
       }
       return ret;
   }
};
