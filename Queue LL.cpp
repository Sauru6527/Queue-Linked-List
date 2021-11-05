#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
struct node *front;
struct node *rear;
struct node *head = NULL;
void isempty();
void enqueue();
void Display();
void Dequeue();
void Front();
void Rear();
void Count();
void Search();

int main()
{
	int choice;
	while(1)
	{
	
	puts("\n********QUEUE OPERATION********\n");
	puts("1:   IS  EMPTY ");
	puts("2:   IS  FULL");
	puts("3:   IS  ENQUEUE");
	puts("4:   IS  DEQUEUE");
	puts("5:   IS  FRONT");
	puts("6:   IS  REAR");
	puts("7:   IS  DISPLAY");
	puts("8:   IS  COUNT");
	puts("9:   SEARCH");
	puts("10:   EXIT");

	printf("\nENTER CHOICE = ");
	scanf("%d",&choice);
	
	switch(choice)
	{
	  case 1:
	         isempty();
	  	     break;
	  	
	  	case 2:
	  	     // isfull();
	  	      break;
	  		
	  		case 3:
	  		      enqueue();
	  			    break;
	  			
	  			case 4:
	  			       Dequeue();
	  				   break;
	  				
	  				case 5:
	  			          Front();
	  			     	   break;
	  			     	   
	  			     	case 6:
	  			             Rear();
	  			     	       break;
	  				
	  			     	case 7:
	  			              Display();
	  			     	       break;
	  			     	       
	  			     	    case 8:
	  			               Count();
	  			     	       break;
	  			     	       
	  			     	       case 9:
	  			     	             Search();
	  			     	              break;
	  			     	              
	  			     	              case 10:
	  			     	              	printf("PROGRAM CLOSED\n");
	  			     	              return 0;
	    }
     } 
	return 0;
}


void isempty()
{
	if(head==NULL)
	{
		printf("QUEUE IS EMPTY");
	}
	
	else
	{
		printf("QUEUE IS NOT EMPTY");
	}
	return;
}

void enqueue()
{
   int value;
   struct node *temp=head;
    struct node *ptr = NULL;
   
   ptr=(struct node*)malloc(sizeof(struct node));
   
   if(ptr==NULL)
   {
   	printf("MEMORY ALLOCATION FAILED\n");
   	return;
   }
   
   printf("ENTER VALUE = ");
   scanf("%d",&value);
   
    ptr->data = value;
    ptr->next = NULL;
    
	if(head==NULL)                 //ONLY ENGINE
	{
		head = ptr;
	}

	else                          //ONE OR MORE THAN ONE NODE
	{
	  while(temp->next!=NULL)
	  {
	  	temp=temp->next;
	  }
	  temp->next=ptr;
	}
}

void Display()
{
	struct node *temp=head;
	
	if(head==NULL)
	{
		printf("LIST EMPTY >>> CAN NOT DELETE \n");
		return;
	}
	
	while(temp!=NULL)
	{
     	printf(" %d",temp->data);
		temp=temp->next;
	}	
	return;
}

void Dequeue()
{
	struct node *temp = head;
	
	if(head==NULL)
	{
		printf("LIST IS EMPTY >>>  NOTHING TO DELETE \n");
		return;
	}
	
	else
	{
		head=temp->next;
		free(temp);
	}
	return;
}

void Front()
{	
    struct node *temp = head;
    int front;
	if(head==NULL)
	{
		printf("LIST IS EMPTY >>>  NOTHING TO DELETE \n");
		return;
	}
	
	else
	{
		front = temp->data;
		printf(" %d",front);	
	}
	
  	return;
}

void Rear()
{
	struct node *temp = head;
	if(head==NULL)
	{
		printf("LIST IS EMPTY >>>\n");
		return;
	}
	
	else
	{
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		printf(" %d",temp->data);
	}
	return;
}


void Count()
{
	int cnt = 0;
	struct node *temp = head;
     
    if(head==NULL)
	{
		printf("LIST IS EMPTY >>>\n");
		return;
	}	
	
	else
       {
       	 while(temp!=NULL)
       	  {
       	  	cnt++;
       	  temp=temp->next;
		  }
		
       	 printf(" COUNT = %d\n",cnt);
	   }
	   
	   return;
}


void Search()
{
	int value;
	int flag=0;
	struct node *temp = head;
  
	  if(head==NULL)
	{
		printf("LIST IS EMPTY >>>\n");
		return;
	}	
	
	else
	{
		printf("ENTER VALUE = ");
		scanf("%d",&value);
		
		while(temp!=NULL)
		{
			flag=0;
		     if(value==temp->data)
		  	 {
			 	flag=1;
			 	break;
				 }	
		   temp=temp->next;
		}
		
		if(flag==1)
		{
			printf(" %d  VALUE FOUND \n",value);
		    return;	
		}
		
		else
		{
			printf("VALUE NOT FOUND\n");
			return;
		}	
	}
}
