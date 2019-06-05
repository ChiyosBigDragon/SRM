#include <bits/stdc++.h>
using namespace std;

class ToastXToast {
public:
   int bake( vector <int> undertoasted, vector <int> overtoasted ) {
       sort(undertoasted.begin(),undertoasted.end());
       sort(overtoasted.begin(),overtoasted.end());
       int o1=*overtoasted.begin(),u1=*undertoasted.begin();
       int o2=*(overtoasted.end()-1),u2=*(undertoasted.end()-1);

       if(o1<u1 or o2<u2) return -1;
       if(u2<o1) return 1;
       return 2;
   }
};
