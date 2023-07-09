#include <iostream>
#include <cmath>
#include <map>

using namespace std;

int main(){
int n;
cin>> n;
int arr[n];
for(int i=0;i<n;i++){
    cin>> arr[i];
}

//map m data store kra jaa rh h h
//pehle map ko initilaize kia h frr uske bd arr ka data map  save kraya h with key .
map<int ,int> mpp;
for(int i=0;i<n;i++){
    mpp[arr[i]]++;
}


//iterating the map ,it.first ka mtlb yha or key jo store hui h ,,,,aur it.secind ka mtlb yha data h 
for(auto it : mpp){
    cout<<it.first<<"->"<<it.second<<endl;
}


//ye yha opr check krne k liye h ki kon kon se number mere map kitni br h . ,,jo hum number input le rhe h vo as a key store h and vo key se hmra input kia gya number match krega to vo us key k cooresponding jo data h usko  output dega.
int p;
cin>> p;
while(p--){
    int number;
    cin>>number;
    //fetch
    cout<< "comes" << mpp[number]<< "times"<< endl;
}

 
    return 0;

}

//we can also use string in mapping ....at that time we store key as a character so we use the form map<char,int>. rest of all will be  same 