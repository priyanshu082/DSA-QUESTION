#include<iostream>

using namespace std;

string convert(string s, int numRows) {
        if(numRows==1 || s.size()==1) return s;
        vector<string> vecAns(numRows);
        int i=0,row=0;
        int flag=0;
        while(i<s.size()){
            while(i<s.size() && flag==0){
            vecAns[row++].push_back(s[i++]);
            if(row==numRows){
                row-=2;
                flag=1;
            }
        }
            while(i<s.size() && flag==1){
            vecAns[row--].push_back(s[i++]);
            if(row==-1){
                row=1;
                flag=0;
            }
            }

        }
        string ans="";
        for(int i=0;i<numRows;i++){
            ans+=vecAns[i];
    }
        return ans;
    }

int main(){

    return 0;
}