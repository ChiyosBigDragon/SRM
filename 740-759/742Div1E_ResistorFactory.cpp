#include <bits/stdc++.h>
using namespace std;

class ResistorFactory {
public:
    vector <int> construct( long long nanoOhms ){
        if(nanoOhms==1e9) return {};
        vector<int> ret;
        vector<double> use={1};
        // 構築{1,2,…,2^49,1/2,…,1/2^50}
        for(long long i=1;i<50;i++){
            use.push_back(1LL<<i);
            ret.push_back(i-1);
            ret.push_back(i-1);
            ret.push_back(0);
        }
        use.push_back(0.5);
        ret.push_back(0);
        ret.push_back(0);
        ret.push_back(1);
        for(long long i=2;i<=50;i++){
            use.push_back(pow(2,-i));
            ret.push_back(i+48);
            ret.push_back(i+48);
            ret.push_back(1);
        }
        vector<int> ans;
        long long l=nanoOhms/1e9;
        double r=nanoOhms/1e9-l;
        for(int id=49;id>=0;id--){
            if(l>=use[id]){
                l-=use[id];
                ans.push_back(id);
            }
        }
        for(int id=50;id<100;id++){
            if(r>=use[id]){
                r-=use[id];
                ans.push_back(id);
            }
        }
        // for(auto i:ans) cout<<i<<endl;
        int n=ans.size();
        if(n==1){
            if(ans[0]>1){
                ret.push_back(ans[0]-1);
                ret.push_back(ans[0]-1);
            }else{
                ret.push_back(ans[0]+1);
                ret.push_back(ans[0]+1);
            }
            ret.push_back(0);
        }else{
            ret.push_back(ans[0]);
            ret.push_back(ans[1]);
            ret.push_back(0);
            int cnt=100;
            for(int i=2;i<n;i++){
                ret.push_back(cnt++);
                ret.push_back(ans[i]);
                ret.push_back(0);
            }
        }
        // vector<double> simu={1};
        // int nn=ret.size();
        // for(int i=0;i<nn;i+=3){
        //     if(ret[i+2]==0) simu.push_back(simu[ret[i]]+simu[ret[i+1]]);
        //     else simu.push_back(simu[ret[i]]*simu[ret[i+1]]/(simu[ret[i]]+simu[ret[i+1]]));
        // }
        // printf("%.10lf\n",simu.back());
        return ret;
    }
};
