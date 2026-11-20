#include<stdio.h>
#include<stdlib.h>

struct node{
    float data;
    struct node *link;
};

void count(struct node *head){
    int n = 0;
    if(head==NULL){
        printf("List is empty!");
        return;
    }

    struct node *ptr = head;
    while(ptr !=NULL){
        n++;
        ptr = ptr->link;
    }
    printf("%d", n);
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


    count(head);

    return 0;
}

