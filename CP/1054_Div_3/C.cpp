#include <iostream>
#include <vector>
#include<unordered_set>
#include <algorithm>
using namespace std;



int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int k;
        cin>>k;
       
        vector<int> vec(n);
        for (int i = 0; i < n; i++) {
            cin >> vec[i];
        }
       

        unordered_set<int> st(vec.begin(),vec.end());
        int cnt=0;
        int cntk=0;
        for(int i=0;i<k;i++){
            if(!st.count(i)) cnt++;
        }
      
       for(int i=0;i<n;i++){
        if(vec[i]==k) cntk++;
       }

         cout<< max(cnt,cntk)<<endl;
    }
}
