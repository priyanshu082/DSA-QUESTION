#include <iostream>
#include <cmath>

using namespace std;

int main(){

     int n;
     cin>> n;
     int arr[n];
     for(int i=0;i<n;i++){
        cin>> arr[i];
     }

     int hash[13]={0}; //here we have intialize all the values of hasharray to 0
     for(int i=0;i<n;i++){
        hash[arr[i]]+=1;  //here it is checking if the number is repeated than it will do +1 to the 0 o that particular block assingned to the number of the array
     }

cout << "enter the numbers";
     int p;
     cin>> p;
     while(p--){
        int number;  //we input the number we want to check that how times that number exists
        cin>> number;
        cout<<"the number is "<< hash[number]<<endl; //it will print out that how many times a number is printed
     }
    return 0;

}