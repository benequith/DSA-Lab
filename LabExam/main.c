/*
    Name: Soumyadip Ghosh
    Stream: CSE-A
    Autonomy Roll Number: 12619001158

 */
#include <stdio.h>
#include <stdlib.h>


struct node{
    int data;
    struct node *prev, *next;
};

struct node *head=NULL, *tail=NULL;


struct node *insfront(struct node *head,int data);
struct node *insend(struct node *head,int data);
struct node *delfront(struct node *head);
struct node *delend(struct node *head);
void display(struct node *head);


int main()
{
    int ch,ch2,d;
    do{
       printf("\n1. Enqueue\n2. Dequeue\n3. Exit\nEnter your choice:");
       scanf("%d",&ch);
       switch(ch){
        case 1: printf("\nEnter the data:");
                scanf("%d",&d);
                printf("\n Where do you want to insert\n1. Enqueue at front\n2. Enqueue at end\nEnter your choice:");
                scanf("%d",&ch2);
                if(ch2==1)
                head= insfront(head,d);
                else
                head=insend(head,d);

                display(head);
                break;

        case 2: printf("\n Where do you want to delete\n1. Dequeue at front\n2. Dequeue at end\nEnter your choice:");
                scanf("%d",&ch2);
                if(ch2==1)
                head=delfront(head);
                else
                head=delend(head);
                display(head);
                break;

        case 3: exit(0);
                break;

        default: printf("\nWrong choice. Enter again");
                 break;
       }
    }
    while(1);
    return 0;
}


struct node *insfront(struct node *head, int data){

    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->next=NULL;
    temp->prev=NULL;
    if(head==NULL){
        head=temp;
        tail=temp;
    }

    else{
        temp->next=head;
        head->prev=temp;
        head=temp;
    }
    return head;
};


struct node *insend(struct node *head, int data){

    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->next=NULL;
    temp->prev=NULL;
    if(head==NULL && tail==NULL){
        head=temp;
        tail=temp;
    }

    else{
        temp->prev=tail;
        tail->next=temp;
        tail=temp;
    }
    return head;
};


struct node *delfront(struct node *head){

    struct node *temp=head;
    if(head==NULL){
        printf("\nThere is nothing to delete. Queue is empty");
    }
    else if(head->next==NULL){
        head=NULL;
        return head;
    }
    else{
        head=head->next;
        head->prev=NULL;
        temp->next=NULL;
        free(temp);
    }

    return head;

};


struct node *delend(struct node *head){
    struct node *temp=tail;
    if( tail==NULL){
        printf("\nThere is nothing to delete. Queue is empty");
    }
    else if(tail->prev==NULL){
        tail=NULL;
        head=NULL;
        return head;
    }
    else{
        tail=tail->prev;
        tail->next=NULL;
        temp->prev=NULL;
        free(temp);
    }

    return head;

};

void display(struct node *head){
    struct node *temp=head;
    if(head==NULL){
        printf("\nQueue is empty");
    }
    else{
        while(temp!=NULL){
        printf("%d-->",temp->data);
        temp=temp->next;
        }
    }

}
