#include<stdio.h>
#include<stdlib.h>
#include "exam47.h"

// struct node{
//     int itemNo;
//     int price;
//     int quantity;
//     struct node *prev;
//     struct node *next;
// };

struct node *head;

void addItem(int ino, int price, int quantity){
    struct node *new,*t;
    new = (struct node*)malloc(sizeof(struct node)); //dynamic memory alloc. to new node
    new->itemNo = ino;
    new->price = price;
    new->quantity = quantity;
    new->next = NULL;
    new->prev = NULL;

    if(head == NULL){  //if list is empty initially new node is head
        head = new;
    }
    else{
      t = head;
      while(t->next != NULL){   //traversing till we get t->next null
          t = t->next;
      }
      t->next = new;
      new->prev = t;
    }
}

void printItems(){
    struct node *t;
    if(head == NULL)
    {
        printf("Empty Cart.\n");  //if head is null then list is empty
    }
    else{
        t = head;
        while(t != NULL)
        {   
            //printing data
            printf("\nItem No :- %d",t->itemNo);
            printf("\nItem Price :- %d",t->price);
            printf("\nItem Quantity :- %d",t->quantity);
            printf("\n********************************");
            t = t->next;  //pointing t to next node
        }
        printf("\n");
    }
}

void printItem(int ino){
    struct node *t;
	if(head == NULL)
	{
		printf("Empty list.\n");  //head is null then cart is empty
	}
	else
	{
		t = head;
		while(t->itemNo != ino && t->next != NULL)
		{
            //traverse t till condition fails
			t = t->next;
		}
		if(t->itemNo == ino)
		{
            //printing data of single item
			printf("\nItem No :- %d",t->itemNo);
            printf("\nItem Price :- %d",t->price);
            printf("\nItem Quantity :- %d",t->quantity);
            printf("\n********************************");
		}
		else
		{
			printf("\nElement not found : %d\n", ino);
		}

	}
}

void deleteItem(int ino)
{
  struct node *t, *t2;
  if(head == NULL)
  {
      printf("Empty List.\n"); //nothing to delete when head is null
  }
  else
  {
    t = head; //assign head to t
    t2 = head; //assign t to t2
    if(t->next == NULL)
    {
        //if t->next is null that means we have only one node or item and that has..
        //to be deleted so we have to kept head null for empty list
      //printf("WELCOME TO\n");
      head = NULL;
      free(t);
    }
    else{
    while(t->itemNo != ino && t->next != NULL)
    {
        //printf("AAAA\n");
        t2 = t;
        t = t->next;
    }
    //printf("@@@@@ %d\n",t->data);
    if(t->itemNo == ino)
    {
        if(t == head) 
        {
            //checking the item is at head position if yes then delete..
            //and assign head to next node
            // printf("$$$$ %d\n",root->data);
            // printf("$$$$ %d\n",t->data);
            // printf("$$$$ %d\n",t2->data);
            // printf("BBBB\n");
            head = t->next;
            //printf("$$$$ %d\n",head->itemNo);
            // root->left = NULL;
            //free(t);
        }
        else if(t->next == NULL)
        {
            //checking the item is at last position if yes then delete last element..
            //and assign null to previous node's next..
         //printf("CCC..\n"); 
         t->prev = NULL;  
         t2->next = NULL;
         //free(t);
        }
        else
         {
             //here code comes when except head and tail nodee to delete
             t2->next = t->next;
         }
         printf("%d is Deleted.\n",t->itemNo);
         free(t);  //free the memory
         
    }
    else
    {
        printf("%d not found.\n",ino);
    }
    
  }

  }
  
}

//Driver Function
int main(void){
    int itemNo;
    int price;
    int quantity;
    int choice;
    int key;

    do{
        printf("1.Add Item\n");
        printf("2.Print All Items\n");
        printf("3.Print Specific Item\n");
        printf("4.Delete Item\n");
        printf("0.Exit\n");

        printf("Enter Service Choice\n");
        scanf("%d",&choice);

        switch(choice){
            case 1 :
            printf("Enter Item Number\n");
            scanf("%d",&itemNo);
            printf("Enter Item Price\n");
            scanf("%d",&price);
            printf("Enter Item Quantity\n");
            scanf("%d",&quantity);

            addItem(itemNo,price,quantity);
            printf("---------------------------------------------------\n");
            break;

            case 2 :
            printItems();
            printf("---------------------------------------------------\n");
            break;

            case 3 :
            printf("Enter Item Number to be print\n");
            scanf("%d",&key);
            printItem(key);
            printf("---------------------------------------------------\n");
            break;

            case 4 :
            printf("Enter Item Number to be Deleted\n");
            scanf("%d",&key);
            deleteItem(key);
            printf("---------------------------------------------------\n");
            break;

            case 0 :
            exit;
            break;

            default :
            break;

        }

    }while(choice != 0);
}


