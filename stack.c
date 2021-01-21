#include<stdio.h>
#include<stdlib.h>
struct node
{ int data;
struct node *link;
};
struct node *TOP=NULL;

void push()
{ struct node *ne=(struct node*)malloc(sizeof(struct node));
if(ne==NULL)
{ printf("out of memory\n");
return; }
printf("enter element to push\n");
scanf("%d",&ne->data);
ne->link=TOP;
TOP=ne; 
}
void pop()
{ struct node *ptr;
if (TOP==NULL)
{ printf("stack is rempty\n");
return; }
printf("popped element is %d\n",TOP->data);
ptr=TOP;
TOP=TOP->link;
free(ptr);
}
void search()
{ struct node*ptr;
int x,pos=1;
if(TOP==NULL)
{ printf("stack empty\n");
return; }
ptr=TOP;
printf("enter the element to search\n");
scanf("%d",&x);
while(ptr!=NULL)
{ if(ptr->data==x)
{ printf("element found at %d position from top\n",pos);
break;
}
ptr=ptr->link;
pos++; }
if (ptr==NULL)
printf("element not found\n"); 
}
void display()
{ struct node *ptr=TOP;
if(TOP==NULL)
{ printf("stack empty\n");
return; }
ptr=TOP;
printf("elements are \n");
while(ptr!=NULL)
{ printf("%d\n ",ptr->data);
ptr=ptr->link;
}
}
void main()
{ int ch=0;
while (ch!=5)
{ printf("MENU\n1.PUSH\n2.POP\n3.SEARCH\n4.DISPLAY\n5.EXIT\n");
printf("enter your choice\n");
scanf("%d",&ch);
switch(ch)
{ case 1:push();
break;
case 2:pop();
break;
case 3:search();
break;
case 4:display();
break;
case 5: printf("bye");
return; }
}
}