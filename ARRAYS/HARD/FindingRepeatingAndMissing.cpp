#include<iostream>
#include <map>


using namespace std;

//brute appraoch would running loop inside loop i>e tc=n@2 and sc will be n

//better appraoch would be using hashing 
vector<int> findMissingRepeatingNumbers(vector < int > a) {
    int missing=-1;
    int repeating=-1;
    int n=a.size();
     map<int ,int> hash;// int hash[n+1]={0}; //or we can use map for hashing 
    for(int i=0;i<n;i++){ 
        hash[a[i]]++;
    }
    for(int i=0;i<n;++i){
        if(hash[i+1]==0) missing=i+1;
        if(hash[i+1]==2) repeating=i+1;
    }
    vector<int> vec;
    vec.push_back(repeating);
    vec.push_back(missing);
    return vec;
}

//optimal appraoch 1
vector<int> findMissingRepeatingNumbers(vector < int > a) {
    int n=a.size();
    long long sn=n*(n+1)/2;
    long long s2n=(n*(n+1)*(2*n+1))/6;
    long long s=0;
    long long s2=0;
    for (int i=0;i<n;i++){
        s+=a[i];
        s2+=(long long)a[i]*(long long)a[i];
    }
    int val1=s-sn;
    int val2=s2-s2n;
    val2=val2/val1;
    long long x=(val1+val2)/2;
    long long y=(x-val1);
    return {(int)x,(int)y};
}

int main(){

    return 0;
}