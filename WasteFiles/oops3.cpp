#include<iostream>

using namespace std;

class Humans{
    public:
    int h;
    int w;
    int a;

    public:
    int getAge(){
        return a;
    }
    
    void setWeight(int w){
        this->w=w;
    }
};



class Male:public Humans{  //inheritance of human class
    public:
    string color;

    void sleep(){
        cout<<"Male Is sleeping"<<endl;
    }
};



int main(){

    Male Object1;
    Object1.setWeight(43);
    cout<<Object1.w<<endl;
    return 0;
}