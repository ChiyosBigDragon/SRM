#include <bits/stdc++.h>
using namespace std;
const int INF=1145141919;

class TheLuckyGameDivTwo {
public:
   int find( int a, int b, int jLen, int bLen ) {
    int lucky[]={4,7,44,47,74,77,444,447,474,477,744,747,774,777,4444,4447,4474,4477,4744,4747};
   	int num[5000]={}; for(auto i:lucky) num[i]=1;
   	for(int i=1;i<5000;i++) num[i]+=num[i-1];
    jLen--; bLen--;

   	int ans=0;
   	for(int i=a;i+jLen<=b;i++){
   		int bSum=INF;
   		for(int j=i;j+bLen<=i+jLen;j++){
   			bSum=min(bSum,num[j+bLen]-num[j-1]);
   		}
   		ans=max(ans,bSum);
   	}
   	return ans;
   }
};
