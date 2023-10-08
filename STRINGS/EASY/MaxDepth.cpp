#include<iostream>

using namespace std;

int maxDepth(string s) {
        int depth=0;
        int maxDepth=0;
        int i=0;
        while(i<s.size()){
            if(s[i]=='('){
                depth++;
                maxDepth=max(maxDepth,depth);
                i++;
            } 
            else if(s[i]==')' && depth>0){
                depth--;
                i++;
            } else i++;
        }
        if(depth!=0) return -1;
        else return maxDepth;
    }

int main(){

    return 0;
}