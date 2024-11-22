#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
struct node{
    int ssn;
    char name[10];
    char des[10];
    long int sal;
    long int ph;
    struct node *left;
    struct node *right;
};typedef struct node * NODE;
NODE insfront(NODE first){
    NODE newnode;
    newnode=(NODE)malloc(sizeof(struct node));
    printf("\n Enter ssn, name,designation,salary,phone number\n");
    scanf(" %d %s %s %d %d",&newnode->ssn,newnode->name,newnode->des,&newnode->sal,&newnode->ph);
    if(first==NULL){
        newnode->right=NULL;
        first=newnode;
        return first;
    }
    newnode->right=first;
    first->left=newnode;
    first=newnode;
    return first;
}
NODE inslast(NODE first){
    NODE newnode;
    newnode=(NODE)malloc(sizeof(struct node));
    printf("\n Enter ssn, name,designation,salary,phone number\n");
    scanf(" %d %s %s %d %d",&newnode->ssn,newnode->name,newnode->des,&newnode->sal,&newnode->ph);
    if(first==NULL){
        newnode->right=NULL;
        first=newnode; 
        return first;
    }
    newnode->right=NULL;
     NODE temp=first;
    while(temp->right!=NULL)
    temp=temp->right;
    temp->right=newnode;
    newnode->left=temp;
    return first;
}
NODE delfront(NODE first){
    NODE temp;
    if(first==NULL){
    printf("\nthe list is Empty\n");
    return first;
    }else{
        temp=first;
        
        printf("\n the ssn %d details are deleted\n",temp->ssn);
        first=first->right;
        free(temp);
        return first;
        
    }
}
NODE dellast(NODE first){
    NODE prev,pres;
    if(first==NULL){
    printf("\nthe list is Empty\n");
    return first;
    }else{
        pres=first;
        while(pres->right!=NULL){
            prev=pres;
            pres=pres->right;
        }
        
        printf("\n the ssn %d details are deleted\n",pres->ssn);
        prev->right=NULL;
        free(pres);
        return first;
        
    }
}
void display(NODE first){
    NODE temp;
    if(first==NULL)
    printf("\nthe list is Empty\n");
    else{
        temp=first;
          printf("\n SSN Name Designation salary phone number\n");
        while(temp!=NULL){
            printf("%d\t %s\t %s\t %d\t %d\n",temp->ssn,temp->name,temp->des,temp->sal,temp->ph);
            temp=temp->right;
        }
    }
    
}

void main(){
    int ch;
    NODE first = NULL;
    while(1){
        printf("\n1:insfront 2:inslast  3:delfront  4:dellast 5:display 0:Exit\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:first=insfront(first);
                   break;
            case 2:first=inslast(first);
                   break;
            case 3:first=delfront(first);
                   break;
            case 4:first=dellast(first);
                   break;
            case 5:display(first);
                   break;
            default:exit(0);
        }
    }
}