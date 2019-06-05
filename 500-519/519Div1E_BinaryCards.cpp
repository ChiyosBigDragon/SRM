#include <bits/stdc++.h>
using namespace std;

class BinaryCards {
public:
    // 最上位bit
    unsigned long long MSB(unsigned long long n){
        n=n&0xFFFFFFFF00000000?n&0xFFFFFFFF00000000:n;
        n=n&0xFFFF0000FFFF0000?n&0xFFFF0000FFFF0000:n;
        n=n&0xFF00FF00FF00FF00?n&0xFF00FF00FF00FF00:n;
        n=n&0xF0F0F0F0F0F0F0F0?n&0xF0F0F0F0F0F0F0F0:n;
        n=n&0xCCCCCCCCCCCCCCCC?n&0xCCCCCCCCCCCCCCCC:n;
        n=n&0xAAAAAAAAAAAAAAAA?n&0xAAAAAAAAAAAAAAAA:n;
        return n;
    }
    long long largestNumber( long long A, long long B ){
        long long diff=MSB(A^B);
        return (B|(max(diff-1,0ll)));
    }
};
