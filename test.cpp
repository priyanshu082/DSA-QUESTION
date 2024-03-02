#include<iostream>
#include<map>

using namespace std;

map<int,int> mpp;

int memonize(int a ,int b){
        int cnt=0;
        int key=a+b;
        if(mpp.find(key)!= mpp.end()){
            return cnt;
        } else {
            mpp[key]++;
            cnt++;
        }
}

int main(){

    vector<pair<int,int> > vec;

    vec.push_back(make_pair(2,5));
    vec.push_back(make_pair(1,3));
    vec.push_back(make_pair(2,5));
    vec.push_back(make_pair(2,5));
  
    int ans=0;

    //i am running code here 4 times 
    for(auto &p: vec){
       ans+=memonize(p.first,p.second);
    }

//answer will tell you the count 
//ans will come =2 because add function will run only 2 time
    cout<<ans<<endl;

    return 0;
}