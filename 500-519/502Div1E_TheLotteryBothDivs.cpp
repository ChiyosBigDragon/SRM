#include <bits/stdc++.h>
using namespace std;

class TheLotteryBothDivs {
public:
   double find( vector <string> goodSuffixes ) {
       vector<string> number;
       for(auto itr=goodSuffixes.begin();itr!=goodSuffixes.end();itr++){
           string tmp=*itr;
           reverse(tmp.begin(),tmp.end());
           number.push_back(tmp);
       }
       sort(number.begin(),number.end());

       double ans=0;
       while(number.size()){
           string num=*number.begin();
           int digit=num.size();
           ans+=pow(10,-digit);
           auto itr=number.begin();
           while(itr!=number.end()){
               string tmp=*itr;
               if(num==tmp.substr(0,digit)) itr=number.erase(itr);
               else itr++;
           }
       }
       return ans;
   }
};
