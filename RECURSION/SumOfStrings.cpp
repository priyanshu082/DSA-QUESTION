#include<iostream>

using namespace std;

class Solution {
public:

    string addStrings(string num1,string num2,int i,int j,int carry){
        if(i<0 && j<0){
            if(carry){
                return to_string(carry);
            } else return "";
        }

        int x=(i>=0) ? num1[i]-'0' : 0;
        int y=(j>=0) ? num2[j]-'0' : 0;
        int sum=x+y+carry;
        int newcarry=sum/10;
        sum=sum%10;

        string currentDigit=to_string(sum);
        string beforeDigit=addStrings(num1,num2,i-1,j-1,newcarry);
        return beforeDigit+currentDigit;

}
    string addStrings(string num1, string num2) {
     int i=num1.size()-1;
     int j=num2.size()-1;
     int carry=0;
     return addStrings(num1,num2,i,j,carry);
    }
};

int main(){
    return 0;
}