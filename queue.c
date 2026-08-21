//queue implementation using linked list
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};
struct node* front=NULL;
struct node* rear=NULL;
void enqueue(int x){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->next=NULL;
    if(front==NULL){
        front=newnode;
        rear=newnode;
    }
    else{
        rear->next=newnode;
        rear=newnode;
    }
}
void dequeue(){
    if(front==NULL){
        printf("Queue is empty\n");
        return;
    }
    struct node* temp=front;
    front=front->next;
    free(temp);
}
void display(struct node* front){
    if(front==NULL){
        printf("Queue is empty\n");
        return;
    }
    struct node* temp=front;
    printf("Queue elements are: ");
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
int main(){
    int choice,x;
    printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
    while(1){
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter the element to enqueue: ");
                scanf("%d",&x);
                enqueue(x);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display(front);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}