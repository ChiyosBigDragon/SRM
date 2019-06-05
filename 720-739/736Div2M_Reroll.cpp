#include <bits/stdc++.h>
using namespace std;

class Reroll {
public:
   int minimumDice( int target, vector <int> dice ) {
       int sum=0;
       sort(dice.begin(),dice.end());
       for(auto i=dice.begin();i!=dice.end();i++){
           sum+=*i;
       }
       if(sum==target) return 0;
       int ret=0;
       if(sum>target){
           reverse(dice.begin(),dice.end());
           for(auto i=dice.begin();i!=dice.end();i++){
               sum=sum-*i+1;
               ret++;
               if(sum<=target) return ret;
           }
       }else{
           for(auto i=dice.begin();i!=dice.end();i++){
               sum=sum-*i+6;
               ret++;
               if(sum>=target) return ret;
           }
       }
       return 0;
    }
};
