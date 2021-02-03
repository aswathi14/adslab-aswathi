#include<stdlib.h>
struct node
{ struct node *left;
  int data;
  struct node *right;
}   ;
struct node *head=NULL;
struct node * GetNode() ;
void insertLast() ;
void insertFirst();
void display();
void search();
 void insertpos();
 void deletefirst();
 void deletelast();
 void deletePos();
void main()
{   int opt=0    ;
   while(opt!=9)
   {  printf("\nMenu\n1.INSERT FIRST \n2.INSERT LAST \n3.INSERT at POSITION\n4.DELETE FIRST \n5.DELETE LAST \n6.DELETE AT POSITION\n 7.SEARCH \n8.DISPLAY \n9.Exit \nEnter the Choice:");
      scanf("%d",&opt);
      switch(opt)
      { case 1:insertFirst();
		break;
	case 2:insertLast();
	       break   ;
	case 3:insertpos();
		break;
	 case 4:deletefirst();
		break;
	  case 5:deletelast();
		break;
	 case 6:deletePos();
		  break;
	  case 7:search();
		 break;
	case 8:display();
		 break;
      }
   }
   printf("Good Bye");
   getch();
   }
void display()
{ struct node *ptr=head;
  if (head==NULL)
  { printf("\n List Empty");
    return;
  }
  printf("The Elements are\n");
  while(ptr!=NULL)
  {  printf("%d\t",ptr->data);
     ptr=ptr->right;
   }
}
struct node * GetNode()
  { int x;
   struct node *ne=(struct node *)malloc(sizeof(struct node ));
    if (ne==NULL)
     printf("insufficient memory\n");
    else
   {      printf("Enter the value to insert ");
	 scanf("%d",&x);
	 ne->left=NULL ;
     ne->right=NULL ;
     ne->data=x;
   }
     return ne;
}
void insertFirst()
{    struct node *ne;
    ne=GetNode();
    if (ne==NULL)  return;
    if (head==NULL)
       head=ne;
    else
     { head->left=ne;
      ne->right=head;
      head=ne;
    }
    display();
}
void insertLast()
{  struct node *ne,*ptr;
    ne=GetNode();
  if (ne==NULL)       return;
   if (head==NULL)
     head=ne;
   else
   {  ptr=head;
      while(ptr->right!=NULL)
      { ptr=ptr->right;
      }
      ptr->right=ne;
      ne->left=ptr;
   }
   display();
}
 void insertpos()
 {   int value;
    struct node *ne,*ptr,*ptr1;
    ne=GetNode();
  if (ne==NULL)     return;
  if (head==NULL)
 {  printf("List is Empty so the node is inserted as the first node");
   head=ne;
   return;
 }
  printf("Enter the key value after which the node has to be inserted\n ");
  scanf("%d",&value);
   ptr=head;
 while(ptr->right!=NULL && ptr->data!=value)
 {  ptr=ptr->right;
 }
 if (ptr->right==NULL)
 {  ptr->right=ne;
    ne->left=ptr;
    printf("\n node is inserted at the last position");
 }
  else
  {     ptr1=ptr->right;
	ne->right=ptr1;
	ne->left=ptr;
	ptr->right=ne ;
	ptr1->left=ne;


    }
   printf("\nthe Element is inserted\n");
   display();
}

void deletefirst()
{  struct node *ptr;
   if (head==NULL)
   {     printf("list is empty\n");
	  return;
    }
    ptr=head;
    head=head->right;
    if (head!=NULL)
	 head->left=NULL;
    free(ptr);
    display();
}
void deletelast()
{  struct node *ptr,*prev;
   if (head==NULL)
    {  printf("\nList is empty\n");
       return;
     }
     if (head->right==NULL)
       { free(head);
	  head=NULL;
          return;
	}
      ptr=head->right;
      while(ptr->right!=NULL)
      {  ptr=ptr->right;
      }
       prev=ptr->left;
       prev->right=NULL;
       free(ptr);
       display();
}
void deletePos()
{  struct node *ptr,*prev,*next;
   int x;
   if (head==NULL)
	{ printf("\nlist is empty\n");
	  return;
	 }
    printf("Enter the element to delete; ");
    scanf("%d",&x);
    if (head->data==x)
       {          ptr=head;
	  head=ptr->right;
	  if (head!=NULL)
	  { head->left=NULL;}
	  free(ptr);
	  return;
	}

    ptr=head;
    while(ptr->data!=x && ptr->right!=NULL)
    { ptr=ptr->right;
    }
     if (ptr->data==x)
     {        next=ptr->right;
	  prev=ptr->left;
	  prev->right=ptr->right;
	  if (next!=NULL)
	       next->left=ptr->left;
	   free(ptr);
	   return;
       }
      printf("\nElement not present in the list\n");
}
void search()
{  struct node *ptr;
int x;
  if (head==NULL)
       { printf("\nLinkedList Empty");
	  return;
	 }
   printf("Enter  element to search : ");
   scanf("%d",&x);
   ptr=head;
   while(ptr!=NULL)
   {  if (ptr->data==x)
      {   printf("\nElement present in the list\n");
	 break;
       }
       ptr=ptr->right;
    }
    if (ptr==NULL)
      printf("\n Element not in the List\n");
}
