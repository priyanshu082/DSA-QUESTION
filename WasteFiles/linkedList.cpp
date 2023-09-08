#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
int avail=0;

void traversal(int data[],int pointer[], int size)
{

   printf("\nIndex\tItems\t Pointing_To\n");
   for(int i=0; i<size; i++)
   {
    if(data[i]!=-1){
        printf("%d\t%d\t%d\n",i,data[i],pointer[i]);
    }
   }
} 


void insertion(int data[], int pointer[], int size){
    int index, element, pointing_to;
    while(1){
        cout<<"Enter the index you want to insert element at"<<endl;
        cin>>index;
        cout<<"Enter the value of the element you want to insert"<<endl;
        cin>>element;
        cout<<"Enter the index at which you want to make this element point to"<<endl;
        cin>>pointing_to;
        if(data[index]==-1 && element>-1 && pointing_to>-1 && index>-1 && index<size){
            if(avail<size){
            //we are also checking for the index. that it is greater than -1 and also smaller the largest index possible
            //data[index]=-1 means that location is empty and is valid for insertion
            //whenever an insert function is called, we increment the value of avail variable so that we can check for the overflow every time we insert an element.
            // cout<<"Inside overflow condition"<<endl;
            data[index]=element;
            pointer[index]=pointing_to;
            avail+=1;//incrementing the value of avail after a valid entry has been made into the linked list
            break;
            }
            else{
                cout<<"The linked_list is full"<<endl;
            }
        }
        else{
            cout<<"Invalid entry, please try again"<<endl;
            break;
        }
    }
    // data[index]=element;
    // pointer[index]=pointing_to;
    // avail+=1;
}



void delete_1(int data[],int pointer[], int size)
{
   int index, prev_loc, i=0;
   if(avail==0){
    cout<<"Can't delete from empty linked list"<<endl;
   }
   else{
    while(1){
        cout<<"Enter the index you wish to delete from"<<endl;
        cin>>index;
        if(index>-1 && index<size){
            if(data[index]!=-1)//checking if the given location is already empty or not
            {   
                // cout<<"Just before the for loop"<<endl;
                while(i<size){
                    // cout<<"Inside the for loop"<<endl;
                    if(pointer[i]==index){//trying to find the entry in the pointer array which will give us the element that is currently pointing to the element to be deleted
                    // cout<<"Inside the second if condition"<<endl;
                    pointer[i]=pointer[index];
                    data[i]=data[index];//reassigning the data values to the new index or we can shifting the data upward 
                    break;
                    }
                    i=pointer[i];
                }
                //making the pointer of the element preceeding the element to be deleted to point to the element succeeding the element to be deleted
                data[index]=-1;
                pointer[index]=-1;
                avail=avail-1;//logic of avail is that it keeps incrementing when a new entry is made into the linked list until it becomes 
                // equal to size and it keeps decrementing until it becomes equal to 0 which denotes empty linked list
                break;
            }
        }
        else{
            cout<<"Invalid location "<<endl;
            break;
        }
    }
   }
}



int search(int data[],int pointer[],int size)
{
   int element, i=0, node=0;
   cout<<"Enter the item to search for"<<endl;
   cin>>element;
   while(pointer[i]!=-1)
   {
      if(element==data[i])
      {
         printf("\nItem Found!! at NODE %d\n",node);
         return 1;
      }
      i=pointer[i];
      node++;
   }
   printf("\nUnable to find Item ,Node Compared %d\n",node);
   return 0;
}




int main(){
    
    int size;
    cout<<"Enter the number of elements for the array implmentation of linked list"<<endl;
    cin>>size;
    int linked_list[size], pointer[size];
    for(int i=0;i<size;i++){
        linked_list[i]=-1;
        pointer[i]=-1;
    }

    int choice;
    while(1){
        cout<<"Enter the operation you want to perform "<<endl;
        cout<<"1 for Insertion "<<endl;
        cout<<"2 for Deletion "<<endl;
        cout<<"3 for Searching"<<endl;
        cout<<"4 for Exiting the execution"<<endl;
        cin>>choice;
        switch (choice)
        {
        case 1:
            // cout<<"Inside case 1"<<endl;
            insertion(linked_list, pointer, size);
            traversal(linked_list, pointer, size);
            break;
        case 2:
            // cout<<"Inside case 2"<<endl;
            delete_1(linked_list, pointer, size);
            traversal(linked_list, pointer, size);
            break;
        case 3:
            // cout<<"Inside case 3"<<endl;
            search(linked_list, pointer, size);
            traversal(linked_list, pointer, size);
            break;
        case 4:
            // cout<<"Inside case 4"<<endl;
            exit(0);
            break;
        default:
            cout<<"Invalid input, please try again"<<endl;
            break;
        }
    // break;
    }
    return 0;
}
