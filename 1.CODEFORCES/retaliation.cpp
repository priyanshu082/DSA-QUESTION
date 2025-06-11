#include<iostream>
#include<vector>
using namespace std;

bool isInteger(double num){
    return (num== (int)num);
}


int main(){
    int tc;
    cin>> tc;
    while(tc--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>> arr[i];
        }
        double a=arr[0];
        double b=arr[1];
        double x2 = (2 * a - b) * 1.0 / (n + 1);
        double x1 = a - n * x2;
        if(x2<0 || x1<0 || !isInteger(x2) || !isInteger(x1)){
            cout<<"NO"<<endl;
            continue;
        } 
        bool valid = true;
        int X1 = (int)x1, X2 = (int)x2;
            for(int i=0;i<n;i++){
                arr[i]-=x2*(n-i);
                arr[i]-=x1*(i+1);
                if(arr[i]!= 0){
                    valid=false;
                    break;
                }
            }
            if(valid)cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        
    }

    return 0;
}