// create linkedlist with function insertAtBeginning , insertAtEnd , insertAtParticularIndex  , size , print linkedlist 
#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};
struct Node *head;
int size();
void insertNodeAtBeginning(){
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter the data : ");
    scanf("%d",&newnode->data);
    newnode->next = NULL;
    if(head == NULL){
        head = newnode;
        printf("You data is stored at begin successfully");
    }
    else{
        newnode->next = head;
        head = newnode;
        printf("You data is stored at begin successfully");
    }
}
void insertNodeAtTheIndex(){
    struct Node *temp = head;
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter the index : ");
    int index;
    scanf("%d",&index);
    printf("Enter the data : ");
    scanf("%d",&newnode->data);
    newnode->next = NULL;
    if(temp == NULL){
        head = newnode;
    }
    else{
        if(index == 0){
            newnode->next=head;
            head = newnode;
        }
        else{
            index--;
            while(index!=0){
                temp = temp->next;
                index--;
            }
            newnode->next = temp->next;
            temp->next = newnode;
            printf("The data is added at index successfully");
        }
    }
}
void insertNodeAtEnd(){
    struct Node *newnode = (struct Node *) malloc(sizeof(struct Node));
    printf("Enter the data to store : ");
    scanf("%d",&newnode->data);
    newnode->next = NULL;
    if(head == NULL){
        head  = newnode;
        printf("You data is stored at end successfully");
    }
    else{
        struct Node *temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newnode;
        printf("You data is stored at end successfully");
    }
}
void printLinkedList(){
    struct Node *temp = head;
    if(size() == 0){
        printf("The linked list is empty");
    }
    else{
        while(temp != NULL){
            printf("%d ",temp->data);
            temp = temp->next;
        }
    }
}
int size(){
    struct Node *temp = head;
    if(temp == NULL){
        return 0;
    }
    else{
        int size=0;
        while(temp != NULL){
            size++;
            temp = temp->next;
        }
        return size;
    }
}
void main(){
    int choice = 0;
    while(choice != 5 ){
        printf("\n1 for insert data \n2 for insert data at end \n3 for insert node at particular index  \n4 for printing linked list \n5 for exit \nEnter your choice : ");
        scanf("%d",&choice);
        if(choice  == 1){
            insertNodeAtBeginning();
        }
        else if(choice == 2){
            insertNodeAtEnd();
        }
        else if(choice==3){
            insertNodeAtTheIndex();
        }
        else if(choice == 4){
            printLinkedList();
        }
        else{
            printf("Thank you\n");
            break;
        }
    }
}