#include<iostream>
#include<cmath>

using namespace std;

int main(){
    string q;
    cin>>q;
    string s="abcdefghijklmnopqrstuvwxyz";

    int hash[26]={0};
    for(int i=0;i<s.size();i++){
        hash[s[i]-'a']++; //we have used here the ASCII numbers as small 'a' has ASCII of 97 and b has 98 and so on z has 122 ,,,here we have just subtracted the charactetr from small a that qwill give us the number for
        //if we look here 'f'-'a' this implies 102-97=5  so f will be assinged 5th number of array of hash ;
        //here the character automatically get coverted in the ASCII 
    }

    int z;
    cin>>z;
    while(z--) {
        char c;
        cin>>c;
        cout<<"the " << c << " has come "<< hash[c-'a']<<" times."<<endl;

    }
   

    return 0;

}