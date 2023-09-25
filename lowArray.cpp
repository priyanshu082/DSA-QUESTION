#include<iostream>
#include<vector>

using namespace std;

class LowArray
{
private:
vector<double> v; 
public:
LowArray(int max) //constructor
{v.resize(max);} //size the vector

void setElem(int index, double value) //put element Into
{ v[index] = value; } //array, at index

double getElem(int index) //get element from
{ return v[index]; } //array, at Index
};

int main(){
    LowArray arr(100);
    int nElems=0;
    int j;
    arr.setElem(0,77);
    arr.setElem(1,99);
    arr.setElem(2,44);
    arr.setElem(3,55);
    arr.setElem(4,22);
    arr.setElem(5,88);
    arr.setElem(6,11);
    arr.setElem(7,00);
    arr.setElem(8,66);
    arr.setElem(9,33);
    nElems=10;


    for( j=0;j<nElems;j++)
        cout<<arr.getElem(j)<<" ";
    
    cout<<endl;


    int searchkey=26;
    for(int j=0;j<nElems;j++)
        if(arr.getElem(j)==searchkey)
        break;
        if(j==nElems)
            cout<<"Can't found "<<searchkey<<endl;
        else
            cout<<"Found"<<searchkey<<endl;
        
    

    double deleteKey = 55;
    cout<<"Deleting element "<<deleteKey<<endl;
    for(j=0;j<nElems;j++)
        if(arr.getElem(j)==deleteKey)
        break;
        for(int k=j;k<nElems;k++)
            arr.setElem(k,arr.getElem(k+1));
            nElems--;

            for(j=0;j<nElems;j++)
            cout<<arr.getElem(j)<<" ";
            cout<<endl;
            return 0;
}