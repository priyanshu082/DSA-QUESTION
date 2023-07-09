#include <iostream>
using namespace std;

void p3(int n ){
    for(int i=0;i<=n;i++){
        for(int j=1;j<i+1;j++){
            cout<< j <<" ";
        }
        cout<< endl;
    }
}
void p4(int n ){
    for(int i=0;i<=n;i++){
        for(int j=1;j<i+1;j++){
            cout<< i <<" ";
        }
        cout<< endl;
    }
}
void p5(int n ){
    for(int i=n;i>=0;i--){
        for(int j=0;j<i;j++){
            cout<< "*" <<" ";
        }
        cout<< endl;
    }
}
void p6(int n ){
    for(int i=n;i>=0;i--){
        for(int j=1;j<=i;j++){
            cout<< j <<" ";
        }
        cout<< endl;
    }
}
void p7(int n ){
    for(int i=0;i<n;i++){
            for(int k=0;k<=n-1-i;k++){
                cout<< " ";
            }
            for(int l=1;l<=2*i+1;l++){
                cout<<"*";
            }
          for(int k=0;k<=n-1-i;k++){
                cout<< " ";
            }
        cout<<endl;
    }
}
void p8(int n ){
    for(int i=0;i<n;i++){
            for(int k=0;k<=i;k++){
                cout<< " ";
            }
            for(int l=1;l<=2*n-(2*i+1);l++){
                cout<<"*";
            }
          for(int k=0;k<=i;k++){
                cout<< " ";
            }
        cout<<endl;
    }
}
void p9(int n ){
    for(int i=1;i<=n;i++){
        if(i>=0 && i<=(n+1)/2){
             for(int k=0;k<i;k++){
                cout<< "* ";
            }
        }
            else{
             for(int k=n-i+1;k>0;k--){
                 cout<< "* ";
             }
            }
            
        cout<<endl;
    }
}
void p10(int n ){
    int start;
    for(int i=0;i<n;i++){
        if(i%2==0) start=1;
        else start=0;
        for(int j=0;j<=i;j++){
            cout<< start << " ";
            start= 1-start;
        }
        cout << endl;
    }
}
void p11(int n ){
   for(int i=1;i<=n;i++){
    //number 
    for(int j=1;j<=i;j++){
        cout<< j;
    }
    // spaces
    for(int k=0;k<2*(n)-2*i;k++){
        cout<< " ";
    }
    // number
      for(int j=i;j>0;j--){
        cout<< j;
    }
    cout<< endl;
   }
}
void p12(int n ){
    int num=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            cout<< num << " ";
            num=num+1;
        }
        cout<< endl;
    }
}
void p13(int n){
    for(int i=0;i<n;i++){
        for(char j='A';j<='A'+i;j++){
            cout<< j <<" ";
        }
        cout<< endl;
    }
}
void p14(int n ){
    for(int i=0;i<n;i++){
        for(char j='A';j<'A'+(n-i-1);j++){
            cout << j << " ";
        }
        cout << endl;
    }
}
void p15(int n ){
    for(int i=0;i<n;i++){
        char ch='A'+1;
        for(int j=0;j<=i;j++){
            cout << ch <<" ";
        }
        cout <<endl;
    }
}


int main(){
    int p;
cin>> p;
p15(p);
    return 0;

}