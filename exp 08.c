#include <stdio.h>  
   
//Represent a node of the singly linked list  
struct node{  
    int data;  
    struct node *next;  
};      
   
//Represent the head and tail of the singly linked list  
struct node *head, *tail = NULL;  
   
//addNode() will add a new node to the list  
void addNode(int data) {  
    //Create a new node  
    struct node *newNode = (struct node*)malloc(sizeof(struct node));  
    newNode->data = data;  
    newNode->next = NULL;  
      
    //Checks if the list is empty  
    if(head == NULL) {  
        //If list is empty, both head and tail will point to new node  
        head = newNode;  
        tail = newNode;  
    }  
    else {  
        //newNode will be added after tail such that tail's next will point to newNode  
        tail->next = newNode;  
        //newNode will become new tail of the list  
        tail = newNode;  
    }  
}  
   
//deleteFromEnd() will delete a node from end of the list  
void deleteFromEnd() {  
      
    //Checks if the list is empty  
    if(head == NULL) {  
        printf("List is empty \n");  
        return;  
    }  
    else {  
        //Checks whether the list contains only one element  
        if(head != tail ) {  
            struct node *current = head;  
            //Loop through the list till the second last element such that current.next is pointing to tail  
            while(current->next != tail) {  
                current = current->next;  
            }  
            //Second last element will become new tail of the list  
            tail = current;  
            tail->next = NULL;  
        }  
        //If the list contains only one element   
        //Then it will remove it and both head and tail will point to NULL  
        else {  
            head = tail = NULL;  
        }  
    }  
}  
      
//display() will display all the nodes present in the list  
void display() {  
    //Node current will point to head  
    struct node *current = head;  
    if(head == NULL) {  
        printf("List is empty\n");  
        return;  
    }  
    while(current != NULL) {  
        //Prints each node by incrementing pointer  
        printf("%d ", current->data);  
        current = current->next;  
    }  
    printf("\n");  
}  
      
int main()  
{  
    //Adds data to the list  
    addNode(1);  
    addNode(2);  
    addNode(3);  
    addNode(4);  
      
    //Printing original list  
    printf("Original List: \n");  
    display();  
      
    while(head != NULL) {  
        deleteFromEnd();  
        //Printing updated list  
        printf("Updated List: \n");  
        display();  
    }  
          
    return 0;  
}  