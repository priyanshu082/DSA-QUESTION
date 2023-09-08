#include<stdio.h>

#define TABLE_SIZE 10

//quadratic probing 
int quadhashing(int key) {
    return key%TABLE_SIZE;
}

int main(){
    int hashtable[TABLE_SIZE];

    for(int i=0;i<TABLE_SIZE;i++){
        hashtable[i]=-1;
    }

     printf("Enter the number of value you want add:");
     int numValue;
     scanf("%d",&numValue);

     for(int i=0;i<numValue;i++){
        int value;
        printf("%d.Enter the value: ",i);
        scanf("%d",&value);

        int index=quadhashing(value);
        int originalIndex=index;

        while(hashtable[index]!=-1){
            index=(index+i*i)%TABLE_SIZE;

            if(index==originalIndex){
                printf("Hash is full ,can't Add\n");
                break;
            }
        }

        if(hashtable[index]==-1){
            hashtable[index]=value;
            printf("Inserted %d at index %d.\n\n",value,index);
        }

        
     }

     printf("Final Hash Table :\n");
     for(int i=0;i<TABLE_SIZE;i++){
        if(hashtable[i]!=-1){
            printf("Index %d : %d \n",i,hashtable[i]);
        } else {
            printf("Index %d: Empty\n",i);
        }
     }
    return 0;
}