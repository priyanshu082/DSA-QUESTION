#include<iostream>
#include<vector>

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
       char mat[10][10];
        for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){
                cin >> mat[i][j];
            }
        }

        int ans=0;
        for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){
                if(mat[i][j]=='X'){
                    int ring = min(min(i, j), min(9 - i, 9 - j)) + 1;
                    ans += ring;
                }
            }
        }
        cout<<ans<<endl;
    }
}