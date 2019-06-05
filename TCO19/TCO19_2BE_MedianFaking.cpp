#include <bits/stdc++.h>
using namespace std;

class MedianFaking {
public:
    vector <int> minimize( int F, int M, vector <int> data, int goal ){
        vector<int> datasort=data; sort(datasort.begin(),datasort.end());
        int n=F*M;
        int mid=n/2; if(n%2==0) mid--;
        if(datasort[mid]==goal) return {0,0};
        pair<int,int> cntR[F],cntL[F];
        for(int i=0;i<F;i++){
            cntR[i].first=cntL[i].first=0;
            cntR[i].second=cntL[i].second=i;
        }
        for(int i=0;i<F*M;i++){
            if(data[i]>goal) cntR[i/M].first++;
            if(data[i]<goal) cntL[i/M].first++;
        }
        sort(cntR,cntR+F);
        reverse(cntR,cntR+F);
        sort(cntL,cntL+F);
        reverse(cntL,cntL+F);
        if(goal<datasort[mid]){
            int y=0;
            for(int i=0;i<F;i++){
                for(int j=0;j<M;j++){
                    int id=cntR[i].second*M+j;
                    if(data[id]>goal){
                        data[id]=goal;
                        y++;
                        vector<int> d=data;
                        sort(d.begin(),d.end());
                        if(d[mid]==goal){
                            return {i+1,y};
                        }
                    }
                }
            }
        }else{
            int y=0;
            for(int i=0;i<F;i++){
                for(int j=0;j<M;j++){
                    int id=cntL[i].second*M+j;
                    if(data[id]<goal){
                        data[id]=goal;
                        y++;
                        vector<int> d=data;
                        sort(d.begin(),d.end());
                        if(d[mid]==goal){
                            return {i+1,y};
                        }
                    }
                }
            }
        }
        return {0,0};
    }
};
