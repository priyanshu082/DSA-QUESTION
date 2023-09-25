 #include <iostream> 
 using namespace std;
int main() {
int arr[100]; 
int nElems = 0; 
int j; 
int searchKey; 
arr[0] =77; //insert 10 Items arr[l] =99;
arr[2] =44;
arr[3] =55;
arr[4] = 22; 
arr[5] = 88; 
arr[6] = 11; 
arr[7] =00; 
arr[8] = 66; 
arr[9] = 33;
nElems=10;


for(j=0; j<nElems; j++){
//display items cout << arrU] <<" ";
cout <<arr[j]<< " ";
} 
cout<<endl;

searchKey = 66; 
for(int j=0;j<nElems;j++)
if(arr[j] == searchKey) 
break;
if(j==nElems)
cout<<"Can't Find "<< searchKey<< endl;
else
cout<<"Found "<<searchKey<<endl;

searchKey = 55; 
cout<<"Deleting"<< searchKey <<endl;
for(int j=0;j<nElems;j++)
if(arr[j] == searchKey) 
break;
for(int k=j;k<nElems;k++)
arr[k]=arr[k+1];
nElems--;


for(int j=0;j<nElems;j++)
cout<<arr[j]<<" ";

cout <<endl;
return 0;
}
