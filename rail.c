#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define size 5


typedef struct NODE
{
	int seat_no;
	int age;
	char name[20];
        char gender[5];
        char source_station[20];
        char destination_station[20];
        char coach_type[15];
        char birth_type[10];
        int contact_no;
        
	struct NODE *next;
} node;

node* deq();
void create();
int reserve(node*);
int cancel(int);
void enq(node*);
void display();


node *start;
node *front;
node *rear;
int count=0;
int num=0;

void create( )
{
	node *new;
	new=(node *)malloc(sizeof(node));
	new->seat_no=1;
	printf("Name: ");
	scanf("%s", new->name);
	printf("Age : ");
	scanf("%d", &new->age);
        printf("gender : ");
        scanf("%s", new->gender);
        printf("source_station : ");
        scanf("%s", new->source_station);
        printf("destination_station : ");
        scanf("%s", new->destination_station);
        printf("coach_type : ");
        scanf("%s", new->coach_type);
        printf("birth_type : ");
        scanf("%s", new->birth_type);
        printf("contact_no : ");
        scanf("%d", &new->contact_no);
        
	start=new;
	new->next=NULL;
	num++;
	
}

int reserve(node *start)
{
	
	if(start==NULL)
	{
   		 create(start);
		 return 1;
	}
	else 
	{
	
	node *temp, *new_node;
	temp=start;
	while(temp->next!=NULL)
	{ 
	  temp=temp->next;
	}
	
	new_node=(node *)malloc(sizeof(node));
	
	printf("Name: ");
	scanf("%s", new_node->name);
	printf("Age : ");
	scanf("%d", &new_node->age);
        printf("gender: ");
        scanf("%s", new_node->gender);
        printf("source_station: ");
        scanf("%s", new_node->source_station);
        printf("destination_station: ");
        scanf("%s", new_node->destination_station);
        printf("coach_type : ");
        scanf("%s", new_node->coach_type);
        printf("birth_type : ");
        scanf("%s", new_node->birth_type);
        printf("contact_no : ");
        scanf("%d", &new_node->contact_no);
        new_node->next=NULL;
	if(num<=size-1)
	{
		num++;
		new_node->seat_no=num;
		temp->next=new_node;
		
		return 1;
	}
	else
	{
		enq(new_node);
		return 0;
	}
}
}


int cancel(int seat)
{
	node *ptr, *preptr, *new;
	ptr=start;
	preptr=NULL;
	if(start==NULL)
	return -1;
	if(ptr->next==NULL && ptr->seat_no==seat)
		{
		start=NULL;
		num--;
		free(ptr);
		return 1;
		
		}
		
	else{	
	while(ptr->seat_no!=seat && ptr->next!=NULL)
		{
			preptr=ptr;
			ptr=ptr->next;
		}
		if(ptr==NULL && ptr->seat_no!=seat)
			return -1;
		else
			preptr->next=ptr->next;
		free(ptr);
		new=deq();
		while(preptr->next!=NULL)
			preptr=preptr->next;
		preptr->next=new;
		num--;
		return 1;
	
	}
}

void enq(node *new_node)
{
	if(rear==NULL)
	{
		rear=new_node;
		rear->next=NULL;
		front=rear;
	}
	else
	{
		node *temp;
		temp=new_node;
		rear->next=temp;
		temp->next=NULL;
		rear=temp;
	}
	count++;
}

node* deq()
{
	node *front1;
	front1=front;
	if(front==NULL)
		return NULL;
	else
	{
	    count-- ;
		if(front->next!=NULL)
		{
			front=front->next;
			front1->next=NULL;
			return front1;
		}
		else
		{
			front=NULL;
			rear=NULL;
			
			return front1;
		}
	}	
			
	
}


void display()
{
	node *temp;
	temp=start;
	while(temp!=NULL)
	{
		printf("\nseat number: %d\n", temp->seat_no);
		printf("Name : %s\n\n", temp->name);
                printf("Age : %d\n\n", temp->age);
                printf("gender : %s\n\n", temp->gender);
                printf("source_station : %s\n\n", temp->source_station);
                printf("destination_station : %s\n\n", temp->destination_station);
                printf("coach_type : %s\n\n", temp->coach_type);
                printf("birth_type : %s\n\n", temp->birth_type);
                printf("contact_no : %d\n\n", temp->contact_no);
                temp=temp->next;
       }
    
}

int main()
{
	int choice, status=0,canc=0, seat=0;
	start=NULL;
	rear=NULL;
	front=NULL;
	
	
	
	printf("\t\t\t***RAILWAY RESERVATION***\t\t\t\t\n");
	int ch =0;
	while(ch!=4)
	{
	printf("\n\nDo you want to - \n 1. Reserve a ticket? \n 2. Cancel Booking \n 3. Display passenger details \n 4. exit\n\n");
	scanf("%d", &choice); 
	switch(choice)
	{	
		case 1 :  status=reserve(start);
	              if(status==0)
	                printf("\nBooking Full!! \nYou are added to waiting list. Waiting list number %d", count);
	              else
	                printf(" \nBooking Successful!!! Enjoy your journey! Your seat No is %d\n\n", num);
	                
	              break;
	        
	    case 2:   printf(" \n Give the seat number to be cancelled\n");
	              scanf(" %d", &seat);
	              if(seat>num)
	              printf("Invalid!!");
	              else
	              {
	              canc=cancel(seat);
	              if(canc==-1)
	              	printf("\nseat number invalid!!\n");
	              else
	              	printf("\nyour ticket  cancelled successfully\n");
	              	}
	              break;
	              
	    case 3: display();
	    break;
	    case 4: exit(0);   
	    break;
	    default: printf("\nWrong choice!\n");       
	              
	                 
		          
	
	}
	
}

}