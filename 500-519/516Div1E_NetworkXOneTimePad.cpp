#include <bits/stdc++.h>
using namespace std;

class NetworkXOneTimePad {
public:
    int crack( vector <string> plaintexts, vector <string> ciphertexts ){
        vector<long long> p,c;
        for(auto i:plaintexts){
            string s=i; reverse(s.begin(),s.end());
            long long a=1,sum=0;
            for(auto j:i){
                sum+=a*(j-'0');
                a<<=1;
            }
            p.push_back(sum);
        }
        for(auto i:ciphertexts){
            string s=i; reverse(s.begin(),s.end());
            long long a=1,sum=0;
            for(auto j:i){
                sum+=a*(j-'0');
                a<<=1;
            }
            c.push_back(sum);
        }
        int ret=0;
        for(auto i:p){
            long long key=c[0]^i;
            bool flg1=1;
            for(auto j:c){
                bool flg2=0;
                for(auto k:p){
                    if((j^key)==k) flg2=1;
                }
                if(!flg2) flg1=0;
            }
            if(flg1) ret++;
        }
        return ret;
    }
};
