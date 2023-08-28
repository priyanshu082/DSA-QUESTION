#include<stdio.h>
#include<stdlib.h>


//new structure is defined here that will store node ;
struct Node {
    int data;
    struct Node* next;
};

//function to print all the linkedlist
void transversal(struct Node *ptr){
    while(ptr!=NULL){
    printf("Element : %d\n" ,ptr->data);
    ptr=ptr->next;
    }
}

//delte first elemment of the linkedList 
struct Node * delteHead(struct Node * head){
    struct Node* p=head;
    head=head->next;
    free(p);
    return head;
}

//delte any node you want to delte
struct Node * delteIndex(struct Node * head,int index){
    struct Node *p=head;
    struct Node *q=head->next;
    for(int i=0;i<index-1;i++){
        p=p->next;
        q=q->next;
    }

    p->next=q->next;
    free(q);
    return head;
}

//deleting the last linkedList element
struct Node * delteLast(struct Node *head){
    struct Node* p=head;
    struct Node* q=head;
    while(q->next!=NULL){
        p=p->next;
        q=q->next;
    }
    p->next=NULL;
    free(q);
    return head;
}

int main(){

    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    head=(struct Node *)malloc(sizeof(struct Node));
    second=(struct Node *)malloc(sizeof(struct Node));
    third=(struct Node *)malloc(sizeof(struct Node));
    fourth=(struct Node *)malloc(sizeof(struct Node));

    head->data=8;
    head->next=second;

    second->data=82;
    second->next=third;

    third->data=823;
    third->next=fourth;

    fourth->data=90;
    fourth->next=NULL;

printf("Before \n");
 transversal(head);

head=delteLast(head);
// head=delteLast(head);
// head=delteLast(head);

printf("After \n");
 transversal(head);

    return 0;
}