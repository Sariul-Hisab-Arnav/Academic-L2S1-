#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;
};


void print(struct node *head){
    if(head==NULL){
        printf("List is empty!");
        return;
    }

    struct node *ptr = head;
    while(ptr !=NULL){
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }
    printf("\n");
}


struct node *addNodefront(struct node *head,int data){

    struct node *temp = malloc(sizeof(struct node));

    if(temp==NULL){
        return head;
    }

    temp->data = data;
    temp->link = NULL;

    if(head ==NULL){
        return temp;
    }

    temp->link = head;
    head = temp;
    return head;
}



int main(){
    struct node *head = malloc(sizeof(struct node));
    if(head==NULL){
        return 1;
    }
    head->data = 145;
    head->link = NULL;

    struct node *current = malloc(sizeof(struct node));
    if(current==NULL){
        free(head);
        return 1;
    }

    current->data = 245;
    current->link = NULL;
    head->link = current;

    struct node *current2 = malloc(sizeof(struct node));
    if(current2==NULL){
        free(current);
        free(head);
        return 1;
    }
    current2->data = 345;
    current2->link = NULL;
    current->link = current2;


    head= addNodefront(head,100);
    print(head);

    return 0;
}
