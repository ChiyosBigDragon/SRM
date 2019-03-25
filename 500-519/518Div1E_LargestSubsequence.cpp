#include <bits/stdc++.h>
using namespace std;

class LargestSubsequence {
public:
    string getLargest( string s ){
        int n=s.size();
        string t=s;
        for(int i=n-2;i>=0;i--){
            t[i]=max(t[i],t[i+1]);
        }
        string ans;
        for(int i=0;i<n;i++){
            if(s[i]==t[i]) ans+=s[i];
        }
        return ans;
    }
};
