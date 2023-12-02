#include<iostream>

using namespace std;

template<class T>
class Myvector{
    protected:

    public:
    T *arr;
    int size;
    Myvector(int val):size(val),arr(new T[size]){}

    T dotProduct(Myvector& v){
        T sum=0;
        for(int i=0;i<size;i++){
            sum+=this->arr[i]*v.arr[i]; 
        }
        return sum;
    }
};

int main(){ 
    Myvector<float> v1(3),v2(3);
    v2.arr[0]=1.3;
    v2.arr[1]=2.3;
    v2.arr[2]=3.0;
    v1.arr[0]=4;
    v1.arr[1]=5.2;
    v1.arr[2]=6;

    float ans=v1.dotProduct(v2);

    cout<<ans<<endl;

    return 0;
}