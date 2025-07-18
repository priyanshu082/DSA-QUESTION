#include<iostream>
#include <vector>


using namespace std;


bool canPassAllDoors(int n,int x,vector<int> doors){
    bool button =false;
    int i=0;
    while(i<doors.size()){
        if(doors[i]==0){
            i++;
            continue;
        } else {
            if(!button){
                button=true;
                i+=x;
            }else return false;
        }
    }

    return true;
}


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        vector<int> doors(n);
        for (int i = 0; i < n; ++i) {
            cin >> doors[i];
        }

        if (canPassAllDoors(n, x, doors)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}