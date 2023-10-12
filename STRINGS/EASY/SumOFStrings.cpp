#include<iostream>

using namespace std;


string addStrings(string num1, string num2) {
        string ans="";
        int n=num1.size();
        int m=num2.size();
        int i=n-1;
        int j=m-1;
        int carry=0;
        while(i>=0 || j>=0 || carry){
            int x=(i>=0) ? num1[i--]-'0':0;
            int y=(j>=0) ? num2[j--]-'0':0;
            int sum=x+y+carry;
                carry=sum/10;
                sum=sum%10;
            ans+=to_string(sum);
        }
       
            while(i>=0){
                if(carry!=0){
                     int x=num1[i--]-'0';
                    int sum=x+carry;
                    if(sum>=10){
                    carry=sum/10;
                    sum=sum%10;
                    }else carry=0;
                    ans+=to_string(sum);
                }else {
                    ans+=num1[i--];
                }
           
            }
             while(j>=0){
                if(carry!=0){
                     int y=num2[j--]-'0';
                    int sum=y+carry;
                    if(sum>=10){
                    carry=sum/10;
                    sum=sum%10;
                    }else carry=0;
                    ans+=to_string(sum);
                }else {
                    ans+=num2[j--];
                }
            
            }

            if(carry!=0) ans+=to_string(carry);
            reverse(ans.begin(),ans.end());
            return ans;
    }

//shorter version of above code
    string addStrings(string num1, string num2) {
       string ans="";
        int i=num1.size()-1;
        int j=num2.size()-1;
        int carry=0;
        while(i>=0 || j>=0 || carry){
            int x=(i>=0) ? num1[i--]-'0':0;
            int y=(j>=0) ? num2[j--]-'0':0;
            int sum=x+y+carry;
                carry=sum/10;
                sum=sum%10;
            ans+=to_string(sum);
        }
            reverse(ans.begin(),ans.end());
            return ans;
    }

int main(){

    return 0;
}