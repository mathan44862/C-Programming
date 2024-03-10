// create linkedlist with function insertAtBeginning , insertAtEnd , insertAtParticularIndex  , size , print linkedlist , deletefirstnode , deletelastnode , deletenodeatindex
#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};
struct Node *head;
int size();
void insertNodeAtEnd();
void insertNodeAtBeginning();
void insertNodeAtBeginning(){
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter the data : ");
    scanf("%d",&newnode->data);
    newnode->next = head;
    head = newnode;
    printf("You data is stored at begin successfully");
}
void insertNodeAtTheIndex(){
    printf("Enter the index : ");
    int index;
    scanf("%d",&index);
    int listsize = size();
    if(listsize+1 == index){
        insertNodeAtEnd();
    }
    else if(listsize < index){
        printf("Invalid index");
    }
    else if(index == 1){
        insertNodeAtBeginning();
    }
    else{
        index--;
        struct Node *temp = head;
        struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
        printf("Enter the data : ");
        scanf("%d",&newnode->data);
        newnode->next = NULL;
        for(int i=0;i<index-1;i++){
            temp = temp->next;
        }
        newnode->next = temp->next;
        temp->next = newnode;
        printf("The data is added at index successfully");
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
void deleteNodeAtBeginning(){
    if(size() == 0){
        printf("The linkedlist is empty!");
    }
    else{
        struct Node *temp = head ;
        head = head->next;
        free(temp);
        printf("The data at the first is deleted");
    }
}
void deleteNodeAtEnd(){
    if(size()==0){
        printf("The linked list is empty!");
    }
    else{
        struct Node *temp = head;
        while(temp->next->next != NULL){
            temp = temp->next;
        }
        temp->next=NULL;
        printf("The data at the end is deleted");
    }
}
void deleteNodeAtParticularIndex(){
    int index;
    printf("Enter the index : ");
    scanf("%d",&index);
    int listcount = size();
    if(listcount == index){
        deleteNodeAtEnd();
    }
    else if(index == 1){
        deleteNodeAtBeginning();
    }
    else if(index > listcount){
        printf("Invalid index");
    }
    else{
        struct Node *temp = head;
        index--;
        for(int i=0;i<index-1;i++){
            temp = temp->next;
        }
        struct Node *res = temp->next;
        temp->next = temp->next->next;
        free(res);
    }
}
void main(){
    int choice = 0;
    while(choice != 8){
        printf("\n1 for insert data \n2 for insert data at end \n3 for insert node at particular index  \n4 for printing linked list \n5 for deleting node at beginning \n6 for deleting node at end \n7 for deleting node at particular index \n8 for exit \nEnter your choice : ");
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
        else if(choice == 5){
            deleteNodeAtBeginning();
        }
        else if(choice == 6){
            deleteNodeAtEnd();
        }
        else if(choice == 7){
            deleteNodeAtParticularIndex();
        }
        else if(choice == 8){
            printf("Thank you\n");
        }
        else{
            printf("Invalid choice");
            continue;
        }
    }
}