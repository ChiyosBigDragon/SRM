#include <bits/stdc++.h>
using namespace std;

class RotatedClock {
public:
    string getEarliest( int hourHand, int minuteHand ){
        int h=hourHand%30*12;
        int ansh=20,ansm=20;
        for(int i=0;i<12;i++){
            hourHand-=30;
            if(hourHand<0) hourHand+=360;
            minuteHand-=30;
            if(minuteHand<0) minuteHand+=360;
            if(minuteHand==h){
                if(hourHand/30<ansh){
                    ansh=hourHand/30;
                    ansm=minuteHand/6;
                }
            }
        }
        string ret;
        if(ansh!=20){
            if(ansh<10) ret+="0";
            ret+=to_string(ansh);
            ret+=":";
            if(ansm<10) ret+="0";
            ret+=to_string(ansm);
        }
        return ret;
    }
};
