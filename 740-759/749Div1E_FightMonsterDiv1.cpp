#include <bits/stdc++.h>
using namespace std;
const int INF=1145141919;
const long long LINF=8931145141919364364;

class FightMonsterDiv1 {
public:
    bool calc(long long h,long long a,long long l, long long d, long long n){
        // nomagic
        if(h<=a*n+(a/100*l)*(n*(n-1)/2)) return true;
        // magic
        if(d+1<=n){
            long long x=n-d-1;
            long long sum=a*x+(a/100*l)*(x*(x+1)/2-x);
            h-=sum;
            long long sum1=a*(n-1)+(a/100*l)*((n-1)*(n-2)/2)-(a*x+(a/100*l)*(x*(x-1)/2));
            h-=5*sum1;
            if(h<=0) return true;
        }else{
            n--;
            long long sum=a*n+(a/100*l)*(n*(n-1)/2);
            if(h<=5*sum) return true;
        }
        return false;
    }
    long long fightTime( long long hp, long long attack, int level, long long duration ){
        long long ok=1;
        while(1){
            if(!calc(hp,attack,level,duration,ok)){
                ok*=2;
            }
            else break;
        }
        long long ng=ok/2;
        while(abs(ng-ok)>1){
            long long n=(ok+ng)/2;
            if(calc(hp,attack,level,duration,n)){
                ok=n;
            }else{
                ng=n;
            }
        }
        return ok;
    }
};
