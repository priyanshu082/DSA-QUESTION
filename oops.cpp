#include<iostream>

using namespace std;

class Hero{
    private:
    int health;

    public:
    char level;

    Hero(){

    }

    //paramiterised constructor 
    Hero (int health){
        cout<<"this->"<<this<<endl; //this is a pointer it contains the adress of the particular object you are calling
        this->health=health; 
    }




    //copy constructor
     Hero (Hero& temp){
        cout<<"copy constructor is called"<<endl;
        cout<<"this->"<<this<<endl; //this is a pointer it contains the adress of the particular object you are calling
        this->health=health; 
    }

    int getHealth(){
        return health;
    }

    void setHealth(int h){
        health=h;
    }
};

int main(){

    //static allocation 
    Hero gopal(20);
   
    gopal.level='B';

    cout<<"adress of gopal is " << &gopal<<endl;
    cout<<"Health of Gopal is "<< gopal.getHealth()<<endl;
    cout<<"Level of gopal is "<< gopal.level<<endl;

    cout<<"\n"<<endl;




    //dynamic allocation
    Hero *love=new Hero(50);
    
    love->level='A';

    cout<<"adress of love is " << &love<<endl;
    cout<<"Health of love is "<< love->getHealth()<<endl;
    cout<<"Level of love is "<< love->level<<endl;

    cout<<"\n"<<endl;
    

    Hero nikhil(*love);
    
    //copy constructor is callled 
    cout<<"adress of nikhil is " << &nikhil<<endl;
    cout<<"Health of nikhil is "<<nikhil.getHealth()<<endl;
    return 0;
}