#include<stdio.h>
// #include<conio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
struct Node *head; // declaring head global 

struct Node *createnode(){
    struct Node *temp;
    temp = (struct Node*)malloc(sizeof(struct Node));
    temp -> next=NULL; 
    return temp;
}

void createlist(int n){
    struct Node *temp, *new;
    head = temp = NULL;
    while(n>0){
        new = createnode();
        printf("Enter data: ");
        scanf("%d",&new->data);
        if(head==NULL){
            head=new;
            temp=new;
        }
        else{
            temp->next = new;
            temp = new;
        }
        n--;
    }

}

void display(){
    struct Node *temp;
    temp = head;
    if(temp==NULL){
        printf("Linked list not present");
    }
    else{
        while(temp!=NULL){
        printf(" %d ", temp->data);
        temp = temp -> next;
        }
    }
}

void insertbeg(){
    struct Node *temp, *new;
    new = createnode();
    printf("Enter the value u wanna add at beginning: ");
    scanf("%d",&new->data);
    temp = head;
    if(head==NULL){
        head = new;
    }
    else{
        new->next=temp;
        head=new;
    }
}

void main(){
    int n,ins;
    printf("Enter no. of nodes - ");
    scanf("%d",&n);
    createlist(n);
    printf("Linked list:\n");
    display();
    printf("\nEnter 1 to add a node at beginning else 0: ");
    scanf("%d",&ins);
    if (ins==1){
        insertbeg();
    }
    display();
}