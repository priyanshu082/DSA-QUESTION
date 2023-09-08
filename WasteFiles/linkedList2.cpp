#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

void transversal(int linkedList[],int pointer[],int size){
    cout<<"\nIndex\tData\tPointing_to\n";
    for(int i=0;i<size; i++){
        if(linkedList[i]!=-1){
            cout<<i<<"\t"<<linkedList[i]<<"\t    "<<pointer[i]<<endl;
        }
    }
}


int avail=0;
void insertion(int linkedList[],int pointer[],int size){
    cout<<"Enter the index at which you want to insert at"<<endl;
    int index;
    cin>>index;
    cout<<"Enter the elment"<<endl;
    int ele;
    cin>>ele;
    cout<<"Enter the index at which you want to make this element point to"<<endl;
    int pointing;
    cin>>pointing;
    if(index>-1 && index<size && linkedList[index]==-1 && ele>-1 && pointing>-1){
        if(avail<size){
            linkedList[index]=ele;
            pointer[index]=pointing;
            ++avail;
        } else{
            cout<<"The Linkedlist is full"<<endl;
        }
    } else{
        cout<<"Wrong entry"<<endl;
    }
}



void deletion(int linkedList[],int pointer[],int size){
    int index,prev_loc,i=0;
    if(avail==0){
        cout<<"Cant Delte from empty Linked list"<<endl;
    } else{
        while(1){
            cout<<"Enter the index you wish to delete from"<<endl;
            cin>>index;
            if(index>-1 && index<size){
                if(linkedList[index]!=-1){
                    while(i<size){
                        if(pointer[i]==index){
                            pointer[i]=pointer[index];
                            linkedList[i]=linkedList[index];
                            break;
                        }
                        i=pointer[i];
                    }
                    linkedList[index]=-1;
                    pointer[index]=-1;
                    avail=avail-1;
                    break;
                }
            }
            else {
                cout<<"Invalid location"<<endl;
                break;
            }
        }
    }
}



int searching(int linkedList[],int pointer[],int size){
    int ele,i=0,index=0;
    cout<<"Enter the item to search for"<<endl;
    cin>>ele;
    while(pointer[i]!=-1){
        if(ele==linkedList[i]){
            cout<<"Element found! at Index "<<index<<endl;
            return 1;
        }
        i=pointer[i];
        index++;
    }
    cout<<"Element is not present!"<<endl;
    return 0;
}

int main(){

    int size;
    cout<<"Enter the size of linkedList You want to create"<<endl;
    cin>>size;
    int n=size;

    int linkedList[size],pointer[size];
    for(int i=0;i<n;i++){
        linkedList[i]=-1;
        pointer[i]=-1;
    }

    int choice;
    while(1){
        cout<<"Enter the operation you want to perform"<<endl;
        cout<<"1 for insetion"<<endl;
        cout<<"2 for deletion"<<endl;
        cout<<"3 for searching"<<endl;
        cout<<"4 for transversal"<<endl;
        cout<<"5 To Quit"<<endl;
        cin>>choice;
        switch(choice){
        case 1:
            insertion(linkedList,pointer,size);
            transversal(linkedList,pointer,size);
            break;
        case 2:
            deletion(linkedList,pointer,size);
            transversal(linkedList,pointer,size);
            break;
        case 3:
            searching(linkedList,pointer,size);
            // transversal(linkedList,pointer,size);
            break;
        case 4:
            transversal(linkedList,pointer,size);
            break;
        case 5:
           exit(0);
           break;
        default:
        cout<<"!*Invalid Input*!"<<endl;
        break;   
        }
    }
    return 0;
}