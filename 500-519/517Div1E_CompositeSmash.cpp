#include <bits/stdc++.h>
using namespace std;

// 0=未/1=ok/2=no
int memo[100010];
class CompositeSmash {
public:
    int goal;
    // 素因数分解
    vector<int> prime_factorization(int n){
        vector<int> v;
        if(n==1) v.push_back(1);
        int i=2;
        while(n>1){
            if(n%i==0){
                n/=i;
                v.push_back(i);
            }else{
                i++;
            }
        }
        return v;
    }
    // 探索
    bool dfs(int n,vector<int> v){
        if(memo[n]==1) return true;
        if(memo[n]==2) return false;
        // cout<<n<<endl;
        if(n==goal) {memo[n]=1;return true;}
        // どう割っても無理
        if(n%goal!=0) {memo[n]=2;return false;}
        // 素因数の組み合わせ
        int vv=v.size();
        for(int i=1;i<=vv/2;i++){
            vector<int> p;
            for(int j=0;j<vv-i;j++) p.push_back(0);
            for(int j=0;j<i;j++) p.push_back(1);
            do{
                 vector<int> l,r;
                 int le=1,ri=1;
                 for(int j=0;j<vv;j++){
                     if(p[j]){
                         l.push_back(v[j]);
                         le*=v[j];
                     }else{
                         r.push_back(v[j]);
                         ri*=v[j];
                     }
                 }
                 // cout<<le<<" "<<ri<<endl;
                if(!dfs(le,l)&&!dfs(ri,r)) {memo[n]=2;return false;}
            }while(next_permutation(p.begin(),p.end()));
        }
        memo[n]=1; return true;
    }
    // 判定
    string thePossible( int N, int target ){
        goal=target;
        for(int i=0;i<100010;i++) memo[i]=0;
        if(dfs(N,prime_factorization(N))) return "Yes";
        else return "No";
    }
};
