#include <bits/stdc++.h>
using namespace std;
const int INF=1145141919;

class MysteriousRestaurant {
public:
    int calc(char c){
        int ret;
        if('0'<=c&&c<='9') ret=c-'0';
        if('A'<=c&&c<='Z') ret=c-'A'+10;
        if('a'<=c&&c<='z') ret=c-'a'+36;
        return ret;
    }
    int maxDays( vector <string> prices, int budget ){
        int day[7];
        int ret=0,n=prices.size(),m=prices[0].size();
        for(int i=0;i<n;i++){
            if(ret<7){
                string tmp=prices[i];
                sort(tmp.begin(),tmp.end());
                char c=tmp.front();
                int cost=calc(c);
                if(budget-cost>=0){
                    day[i]=cost;
                    budget-=cost;
                    ret++;
                }else{
                    return ret;
                }
            }else{
                budget+=day[i%7];
                int cost=INF;
                for(int j=0;j<m;j++){
                    int sum=0;
                    for(int k=i;k>=0;k-=7){
                        sum+=calc(prices[k][j]);
                    }
                    cost=min(cost,sum);
                }
                if(budget-cost>=0){
                    day[i%7]=cost;
                    budget-=cost;
                    ret++;
                }else{
                    return ret;
                }
            }
        }
        return ret;
    }
};
