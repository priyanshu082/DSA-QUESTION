#include<iostream>

using namespace std;

class Solution {
public:

    void remove(string &s,string &part){
        int pos=s.find(part);
        if(pos!=string::npos){
           string string_left=s.substr(0,pos);
            string string_right=s.substr(pos+part.size(),s.size()); //here we have just passed the size ...it will automatically understsand that we want to remove till end.
            s=string_left+string_right;
            remove(s,part);
        }
        else return;
    }
    string removeOccurrences(string s, string part) {
       remove(s,part);
       return s;
    }
};

int main(){

    return 0;
}