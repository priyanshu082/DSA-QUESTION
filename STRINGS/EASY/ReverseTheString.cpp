#include<iostream>

using namespace std;

void reverseString(vector<char>& s) {
        int l=0;
        int h=s.size()-1;
        while(l<h){
            swap(s[l++],s[h--]);
        }
    }

int main(){

    return 0;
}