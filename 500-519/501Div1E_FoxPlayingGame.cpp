#include <bits/stdc++.h>
using namespace std;

class FoxPlayingGame {
public:
   double theMax( int nA, int nB, int paramA, int paramB ) {
       double scoreA=paramA/1000.0,scoreB=paramB/1000.0;
       double ret1=scoreA*nA;
       double ret2=ret1; for(int i=0;i<nB;i++) ret2*=scoreB;
       // Bの絶対値1未満
       if(abs(scoreB)<1){
           // Aが非負→A*nA
           if(scoreA>=0) return ret1;
           // Aが負
           else{
               // Bが非負→A*nA*(B^nB)
               if(scoreB>=0) return ret2;
               // Bが負→A*nA*B
               return ret1*scoreB;
           }
       }
       // Bの絶対値1以上
       else{
           // Aが非負→A*nA*(B^nB)偶数回
           if(scoreA>=0){
               if(nB%2==0) return ret2;
               else return ret2/scoreB;
           }
           // Aが負
           else{
               // Bが非負→A*nA
               if(scoreB>=0) return ret1;
               // Bが負→A*nA*(B^nB)奇数回
               if(nB%2==1) return ret2;
               else return ret2/scoreB;
           }
       }
    }
};
