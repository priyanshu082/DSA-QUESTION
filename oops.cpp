#include<iostream>

using namespace std;

class Hero{
    private:
    int health;

    public:
    char level;
    static int timeToComplete;

    Hero(){
        cout<<"constructor called"<<endl;
    }



    //paramiterised constructor 
    Hero (int health){
        cout<<"this->"<<this<<endl; //this is a pointer it contains the adress of the particular object you are calling
        this->health=health; 
    }




    //copy constructor
    //  Hero (Hero& temp){
    //     cout<<"copy constructor is called"<<endl;
    //     cout<<"this->"<<this<<endl; //this is a pointer it contains the adress of the particular object you are calling
    //     // this->health=health; 
    // }

    int getHealth(){
        return health;
    }

    void setHealth(int h){
        health=h;
    }

    //static functions can only call static data type
    static int random(){
        return timeToComplete;
    }


    //DESTRUCTOR
    ~Hero(){
        cout<<"Destructor bhai called"<<endl;
    }
};

//static data is initialised outside the class
int Hero::timeToComplete=5;

int main(){

    Hero a;

    cout<<Hero::random()<<endl;
    // cout<<Hero::timeToComplete<<endl;

    // cout<<a.timeToComplete<<endl;

    // Hero *b=new Hero;

    // b->timeToComplete=10;
    // cout<<Hero::timeToComplete<<endl;

    // cout<<a.timeToComplete<<endl;

    return 0;
}

//     //statically
//     Hero a;

//     //dynamically
//     Hero *b=new Hero;


//     //for dynamically allocated memeory we need to call destructor manually but for statically allocated destrcutor is called automatically
//     //manually called destructor
//     delete b;



//  return 0;
// }



//     //static allocation 
//     Hero gopal(20);
   
//     gopal.level='B';

//     cout<<"adress of gopal is " << &gopal<<endl;
//     cout<<"Health of Gopal is "<< gopal.getHealth()<<endl;
//     cout<<"Level of gopal is "<< gopal.level<<endl;

//     cout<<"\n"<<endl;




//     //dynamic allocation
//     Hero *love=new Hero(50);
    
//     love->level='A';

//     cout<<"adress of love is " << &love<<endl;
//     cout<<"Health of love is "<< love->getHealth()<<endl;
//     cout<<"Level of love is "<< love->level<<endl;

//     cout<<"\n"<<endl;
    

//     Hero nikhil(*love);
    
//     //copy constructor is callled 
//     cout<<"adress of nikhil is " << &nikhil<<endl;
//     cout<<"Health of nikhil is "<<nikhil.getHealth()<<endl;



    
//     return 0;
// }