#include <bits/stdc++.h>
using namespace std;

vector<int> edge[1010];
bool used[1010];
int dp[1010][2];

class MaxCutFree {
public:
    struct UnionFind{
        const int V;
        vector<int> par;
        vector<int> sz;
        UnionFind(const int V):V(V){
            par.resize(V+1);
            for(int i=0;i<=V;i++) par[i]=i;
            sz.resize(V+1,1);
        }
        bool unite(int x,int y){
            x=root(x),y=root(y);
            if(same(x,y)) return false;
            if(y<x) swap(x,y);
            par[y]=x;
            sz[x]+=sz[y];
            return true;
        }
        int root(int x){
        	if(par[x]==x) return x; // xはroot
        	return (par[x]=root(par[x])); // xの親のroot
        }
        bool same(int x,int y){
        	return (root(x)==root(y));
        }
        int size(int x){
            return sz[root(x)];
        }
    };
    void dfs(int from){
        if(used[from]) return;
        used[from]=1;
        bool leaf=1;
        for(int to:edge[from]){
            if(!used[to]){
                leaf=0;
                dfs(to);
                dp[from][0]+=max(dp[to][0],dp[to][1]);
                dp[from][1]+=dp[to][0];
            }
        }
        if(leaf){
            dp[from][0]=0;
            dp[from][1]=1;
        }
    }
    void init(){
        for(int i=0;i<1010;i++){
            edge[i].clear();
            used[i]=0;
            dp[i][0]=0;
            dp[i][1]=1;
        }
    }
    int solve( int n, vector <int> a, vector <int> b ){
        init();
        int m=a.size();
        for(int i=0;i<m;i++){
            UnionFind uf(n);
            for(int j=0;j<m;j++){
                if(i==j) continue;
                uf.unite(a[j],b[j]);
            }
            if(!uf.same(a[i],b[i])){
                edge[a[i]].push_back(b[i]);
                edge[b[i]].push_back(a[i]);
            }
        }
        int ret=0;
        for(int i=0;i<n;i++){
            if(!used[i]){
                dfs(i);
                ret+=max(dp[i][0],dp[i][1]);
            }
        }
        return ret;
    }
};
