#include <bits/stdc++.h>
using namespace std;

class Zoo {
public:
    long long theCount( vector <int> answers ){
        sort(answers.begin(),answers.end());
        map<int,int> mp;
    	for(auto i:answers) mp[i]++;
        // 値が飛び飛び
        answers.erase(unique(answers.begin(),answers.end()),answers.end());
        int a=answers.size(),b=answers.back();
        if(a!=b+1) return 0;
        // 順番に並んでいるか
        bool flg=0; int n=b;
    	for(auto m:mp){
            int i=m.second;
            // 前半
            if(!flg&&i!=2){
                if(i==1){
                    flg=1;
                    n=m.first;
                }
                else return 0;
            }
            // 後半
            if(flg&&i!=1) return 0;
    	}
        return pow(2,n+1);
    }
};
