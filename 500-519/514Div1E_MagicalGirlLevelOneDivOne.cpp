#include <bits/stdc++.h>
using namespace std;

class MagicalGirlLevelOneDivOne {
public:
    string isReachable( vector <int> jumpTypes, int x, int y ){
        string ret="NO";
        for(auto i:jumpTypes){
            if(i%2==0){
                ret="YES";
            }else{
                if((x+y)%2==0) ret="YES";
            }
        }
        return ret;
    }
};
