#include<stdio.h>
#include<stdlib.h>
//stack using linked list
struct node{
    int data;
    struct node *next;  
};
struct node* top=NULL;
struct node*push(int x){
    struct node*newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->next=top;
    top=newnode;
    return top;
}
struct node*pop(){
    if(top==NULL){
        printf("Stack is empty\n");
        return NULL;
    }
    struct node*temp=top;
    top=top->next;
    return temp;
}
void peek(){
    if(top==NULL){
        printf("Stack is empty\n");
        return;
    }
    printf("Top element is %d\n",top->data);
}
void display(){
    if(top==NULL){
        printf("Stack is empty\n");
        return;
    }
    struct node*temp=top;
    printf("Stack elements are: ");
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
int main(){
    int choice,x;
        printf("1.Push\n2.Pop\n3.Peek\n4.Display\n5.Exit\n");
        while(1){
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter the element to push: ");
                scanf("%d",&x);
                push(x);
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }

            }   
         }
