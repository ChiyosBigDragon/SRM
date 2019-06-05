#include <bits/stdc++.h>
using namespace std;

class EllysAndXor {
public:
    int getMax( vector <int> numbers ){
        int n=numbers.size();
        int ret=0;
        for(int mask=0;mask<(1<<(n-1));mask++){
            int sum=numbers[0];
            for(int i=0;i<n-1;i++){
                if(mask>>i&1){
                    sum&=numbers[i+1];
                }else{
                    sum^=numbers[i+1];
                }
            }
            ret=max(ret,sum);
        }
        return ret;
    }
};
