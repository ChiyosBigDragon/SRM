#include <bits/stdc++.h>
using namespace std;

class MathContest {
public:
   int countBlack( string ballSequence, int repetitions ) {
       int n=ballSequence.size();
       vector<bool> balls;
       for(int i=0;i<repetitions;i++){
           for(int j=0;j<n;j++){
               if(ballSequence[j]=='B') balls.push_back(1);
               else balls.push_back(0);
           }
       }
       int black=0; bool rev=1,LR=1;
       auto left=balls.begin(),right=balls.end()-1;
       while(left!=right){
           bool color;
           if(LR){
               color=*left;
               left++;
           }else{
               color=*right;
               right--;
           }
           if(color^rev){
               LR=!LR;
           }else{
               rev=!rev;
               black++;
           }
           if(left==right){
               color=*left;
               if(!(color^rev)){
                   black++;
               }
           }
       }
       return black;
   }
};
