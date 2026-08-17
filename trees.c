#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *left;
    struct node *right;
};
struct node* createNode(int data){
    struct node* newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=data;
    newNode->left=NULL;
    newNode->right=NULL;
    return(newNode);
}
struct node*insertion(struct node* root,int data){
    if(root==NULL){
        return createNode(data);
    }
    else{
        if(data<=root->data){
            root->left=insertion(root->left,data);
        }
        else{
            root->right=insertion(root->right,data);
        }
        return root;
    }
}
struct node* minnode(struct node* root){
    while(root->left!=NULL){
        root=root->left;
    }
    return root;
}
struct node*deletion(struct node* root,int data){
    if(root==NULL){
        return root;
    }
    if(data<root->data){
    root->left=deletion(root->left,data);
    }
    else if(data>root->data){
        root->right=deletion(root->right,data);
    }
    else{
        if(root->left==NULL){
            struct node* temp=root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL){
            struct node* temp=root->left;
            free(root);
            return temp;
        }
        else{
            struct node*temp=minnode(root->right);
            root->data=temp->data;
            root->right=deletion(root->right,temp->data);
            return root;
        }
    }
}
void inorder(struct node* root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}
int main(){
    struct node* root=NULL;
    int n;
    printf("Enter the number of nodes\n");
    scanf("%d",&n);
    int i,data;
    for(i=0;i<n;i++){
        printf("Enter the data of node %d\n",i+1);
        scanf("%d",&data);
        root=insertion(root,data);
    }
    printf("Enter the data to be deleted\n");
    scanf("%d",&data);
    root=deletion(root,data);
    printf("Inorder traversal after deletion:\n");
    inorder(root);
    return 0;
}