#include <bits/stdc++.h>
using namespace std;

class MafiaGame {
public:
   double probabilityToLose( int N, vector <int> decisions ) {
       vector<int> member(N,0);
       for(auto itr=decisions.begin();itr!=decisions.end();itr++){
           member[*itr-1]++;
       }
       sort(member.begin(),member.end()); reverse(member.begin(),member.end());
       // 投票1回目
       int loseVote=0,loseNum=0;
       for(int i=0;i<N;i++){
           int vote=member[i];
           if(vote>loseVote){
               loseVote=vote; loseNum=1;
           }else if(vote==loseVote){
               loseNum++;
           }else{
               break;
           }
       }
       // 敗者の票数が1なので決まらない
       if(loseVote==1) return 0;
       // 投票2回目以降
       int tmp=loseNum;
       while(1){
           if(loseNum==1) return 1.0/tmp;
           if(loseNum==0) return 0;
           loseNum=N%loseNum;
       }
   }
};
