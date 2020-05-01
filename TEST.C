/*---------------------*/
 /* TELEPHONE DIRECTORY */
 /*---------------------*/
# include <stdio.h>
# include <conio.h>
# include <string.h>
# include <stdlib.h>

int menu(); 
void add(); 
void find(); 
void edit(); 
void del(); 
void disp(); 

struct node {
char lname[20], fname[20], tel[15], adrs[75];
struct node *next;
};
typedef struct node node;
node *start, *temp;

int menu()
{
int ch;
gotoxy(30,5);
printf(" TELEPHONE DIRECTORY ");
gotoxy(30,6);
printf(" =================== ");
gotoxy(30,10);
printf(" 1. Add ");
gotoxy(30,11);
printf(" 2. Find ");
gotoxy(30,12);
printf(" 3. Edit ");
gotoxy(30,13);
printf(" 4. Delete ");
gotoxy(30,14);
printf(" 5. Display All ");
gotoxy(30,15);
printf(" 6. EXIT ");
gotoxy(30,20);
printf(" Enter your choice(1-6):");
gotoxy(55,20);
scanf("%d", &ch);
return ch;
}

void add()
{
	
node *ptr,*prev;
temp=(node *)malloc(sizeof(node));
printf("First name: ");
scanf("%s", temp->fname);
printf("Last name:");
scanf("%s", temp->lname);
printf("Telephone No.: ");
scanf("%s", temp->tel);
printf("Address: ");
scanf("%s",temp->adrs);
temp->next=NULL;
if(start==NULL) 
	{
		start=temp;
	}
else 
	{
		prev=ptr=start;
		while(strcmp(temp->fname,ptr->fname)>0)
			{
				prev=ptr;
 				ptr= ptr->next;
				if (ptr == NULL) break;
 			}
		if(ptr==prev) 
			{
				temp->next=start;
				start=temp;
			}
				else if(ptr==NULL)
				prev->next=temp;
		else 
			{
				temp->next=ptr;
				prev->next=temp;
			}
	}
}

void find()
{
	node *ptr;
	char str[20];
	if(start==NULL)
		{
			printf("\n\t\t\tTelephone Directory is Empty....\n");
			getch();
			return;
		}
	printf("Enter name to find : ");
	scanf("%s",str);
 	ptr=start;
 	while(strcmp(ptr->fname,str)!=0)
		{
			ptr= ptr->next;
			if (ptr == NULL) break;
 		}
	if(ptr!=NULL) 
		{
			printf("First Name : %s\n",ptr->fname);
			printf("Last Name : %s\n",ptr->lname);
			printf("Phone Number : %s\n",ptr->tel);
			printf("Address : %s\n",ptr->adrs);
		}
	else 
		{
			printf("No Matching Records Found .......\n");
		}
 	getch();
}

void edit()
{
	node *ptr;
	char str[50];
	if(start==NULL) 
		{
			printf("\n\t\t\tTelephone Directory is Empty....\n");
			getch();
			return;
		}
	else
       		{
			printf("First Name to Edit : ");
			scanf("%s",str);
 			ptr=start;
 			while(strcmp(ptr->fname,str)!=0)
				{
					ptr= ptr->next;
				}
		if(ptr!=NULL) 
		{
			printf("First Name : ", ptr->fname);
			scanf("%s", ptr->fname);
			printf("Last Name : ", ptr->lname);
			scanf("%s", ptr->lname);
			printf("Phone Number : ", ptr->tel);
			scanf("%s", ptr->tel);
			printf("Address :");
			scanf("%s", ptr->adrs);
		}
		else 
		{
			printf("No Matching Records Found .......\n");
		}
 		getch();
	}
}

void del()
{
	node *ptr,*prev,*temp;
	char str[20],yn='n';
	if(start==NULL) 
		{
			printf("\n\t\t\tTelephone Directory is Empty....\n");
			getch();
			return;
		}
	printf("First Name to Delete : ");
	scanf("%s",str);
 	prev=ptr=start;
 	while(strcmp(ptr->fname,str)!=0)
		{
 		prev=ptr;
 		ptr= ptr->next;
		if (ptr == NULL) break;
 		}
	if(ptr!=NULL)
		{
			printf("\nDeleting Record.....Confirm [y/n]: ");
			yn=getch();
			printf("\n\n---------------------------------------------------------");
			printf("\nFirst Name : %s\n",ptr->fname);
			printf("Last Name : %s\n",ptr->lname);
			printf("Phone Number : %s\n",ptr->tel);
			printf("Address : %s\n",ptr->adrs);
			printf("---------------------------------------------------------");
			if(yn=='y') 
				{
					if (ptr==start) 
						{
							temp=start->next;
							free(start);
							start=temp;
						}
					else 
						{
							temp=ptr->next;
							free(ptr);
							prev->next=temp;
						}
					printf("\n\n1 Record Deleted....");
				}
			else
				{
					printf("\n\nRecord not Deleted....");
				}
		}
	else 
		{
			printf("\nNo Matching Records Found .......");
		}
 	getch();
}

void disp()
{
	node *ptr;
	if(start==NULL) 
		{
			printf("\n\t\t\tTelephone Directory is Empty....\n");
			getch();
			return;
		}
	clrscr();
	printf("\t\t------------------------------\n");
	for(ptr=start; ptr!=NULL; ptr=ptr->next) 
		{
			printf("\t\tFirst name: %s", ptr->fname);
			printf("\n\t\tLast name:%s", ptr->lname);
			printf("\n\t\tTelephone No.: %s", ptr->tel);
			printf("\n\t\tAddress: %s\n", ptr);
			printf("\n\t\t------------------------------\n");
 		}
 	getch();
}

int main()
{
	int ch;
	start=(node *)malloc(sizeof(node));
	start=NULL;
	do
		{
			clrscr();
			ch=menu();
			clrscr();
			switch(ch) 
			{
				case 1: add();
				break;
				
				case 2: find();
				break;
			
				case 3: edit();
				break;

				case 4: del();
				break;

				case 5: disp();
				break;
	 		}
 		}while(ch!=6);
	return 0;
}
