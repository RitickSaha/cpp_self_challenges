#include <stdio.h>
#include <conio.h>
#include <math.h>
// #include <stdlib.h>
#include <string.h>
/*int hours, minutes, seconds, day, month, year;
	time_t now;
	time(&now);
	struct tm *local = localtime(&now);
	hours = local->tm_hour;
	minutes = local->tm_min;
	seconds = local->tm_sec;
	day = local->tm_mday;
	month = local->tm_mon + 1;
	year = local->tm_year + 1900;
	if (hours < 12)
		printf("Time is : %02d:%02d:%02d am\n", hours, minutes, seconds);
	else
		printf("Time is : %02d:%02d:%02d pm\n", hours - 12, minutes, seconds);
	printf("Date is : %02d/%02d/%d\n", day, month, year);*/
struct node
{
   char itemname[50];
   int itemcode;
   int cost;
   struct node *next;
};
struct sales
{
   char itemname[50];
   int itemcode;
   int cost;
   int price;
   struct sales *next;
};
struct node *temp, *next;
struct node *start = NULL;
struct sales *stemp, *next;
struct sales *sstart = NULL;
int count = 0, input, itemcode, cost, position, i;
int scode, squant;
char itemname[50];
void printbill()
{
   clrscr();
   printf("\t\t\t\t\t\t\tXYZ Pvt. Ltd.\n==============================================================================");
   printf("Invoice no:%d");
}
void insert_at_end(int itemcode, char itemname[], int cost);
void traverse();
void delete_item(int positon);
void salesrecord();
void modify_item(int position, int itemcode, char itemname[], int cost);
void insert_at_end(int itemcode, char itemname[], int cost)
{
   struct node *t;
   t = (struct node *)malloc(sizeof(struct node));
   count++;
   if (start == NULL)
   {
      start = t;
      start->itemcode = itemcode;
      strcpy(start->itemname, itemname);
      start->cost = cost;
      start->next = NULL;
      return;
   }
   temp = start;
   while (temp->next != NULL)
      temp = temp->next;
   temp->next = t;
   t->itemcode = itemcode;
   strcpy(t->itemname, itemname);
   t->cost = cost;
   t->next = NULL;
}
void traverse()
{
   struct node *t;
   clrscr();
   t = start;
   if (t == NULL)
   {
      printf("There is no Item in the sales list.\n");
      return;
   }

   printf("There are %d items in sales list.\n", count);
   printf("ITEM CODE \t ITEM NAME \t PRICE \n");
   while (t->next != NULL)
   {
      printf("%d\t\t%s\t\t%d Rs\n", t->itemcode, t->itemname, t->cost);
      t = t->next;
   }
   printf("%d\t\t%s\t\t%d Rs\n", t->itemcode, t->itemname, t->cost);
}
void delete_item(int position)
{
   if (start == NULL)
   {
      printf("The item list s empty.\n");
      return;
   }
   if (position + 1 > count || position < 0)
   {
      printf("Wrong positon entered.Try again!\n");
      return;
   }
   temp = start;
   if (position == 0)
   {
      start = temp->next;
      free(temp);
      count--;
      return;
   }
   for (i = 0; temp != NULL && i < position - 1; i++)
      temp = temp->next;
   next = temp->next->next;
   free(temp->next);
   temp->next = next;
   count--;
}
void createsalesnode(int scode, int squant)
{
   temp = start;
   for (; temp != NULL; temp = temp->next)
   {
      if (temp->itemcode == scode)
      {
         struct sales *t;
         t = (struct sales *)malloc(sizeof(struct sales));
         count++;
         if (sstart == NULL)
         {
            sstart = t;
            sstart->itemcode = temp->itemcode;
            strcpy(sstart->itemname, temp->itemname);
            sstart->cost = temp->cost;
            sstart->price = (int)temp->cost * squant;
            sstart->next = NULL;
            return;
         }
         stemp = sstart;
         while (stemp->next != NULL)
            stemp = stemp->next;
         t->itemcode = scode;
         strcpy(t->itemname, temp->itemname);
         t->cost = temp->cost;
         t->price = (int)temp->cost * squant;
         t->next = NULL;
      }
   }
}
void modify_item(int position, int itemcode, char itemname[], int cost)
{
   if (start == NULL)
   {
      printf("The item list s empty.There is nothing to modify!\n");
      return;
   }
   if (position + 1 > count || position < 0)
   {
      printf("Wrong positon entered\n");
      return;
   }
   if (position == 0)
   {
      start->itemcode = itemcode;
      strcpy(start->itemname, itemname);
      start->cost = cost;
   }
   temp = start;
   for (i = 0; temp != NULL && i < position; i++)
      temp = temp->next;
   temp->itemcode = itemcode;
   strcpy(temp->itemname, itemname);
   temp->cost = cost;
};

void addsales()
{
   clrscr();
   while (1)
   {
      printf("1. Add item\n");
      printf("2. Delete Previous item\n");
      printf("3. Clear All items\n");
      printf("4. Exit\n");
      scanf("%d", &input);
      if (input == 1)
      {
         printf("Enter the Item details:\n");
         printf("\nEnter the Item's code:");
         scanf("%d", &scode);
         temp = start;
         int codechk = 0;
         for (; temp != NULL; temp = temp->next)
         {
            if (scode == temp->itemcode)
            {
               printf("\nEnter the Sales Quantity:");
               scanf("%d", &squant);
               createsalesnode(scode, squant);
               codechk = 1;
            }
         }
         if (codechk == 0)
            printf("Sorry wrong item code.\n Please try again\n");
      }
      else if (input == 2)
      {
         int chk = 0;
         printf("Are you sure you want to delete the last item?\n Press 1 for YES and 2 for NO:");
         scanf("%d", chk);
         if (chk == 1)
            stemp = sstart;
         for (; stemp->next != NULL; stemp = stemp->next)
            ;
         free(stemp->next);
         stemp->next = NULL;
         if (chk == 0)
            break;
      }
      else if (input == 3)
      {
         int chk = 0;
         printf("Are you sure you want to clear all details?\n Press 1 for YES and 2 for NO:");
         scanf("%d", chk);
         if (chk == 1)
            free(sstart);
         if (chk == 0)
            break;
      }
      else if (input == 4)
         return;
      else
         printf("Please enter valid input.\n");
   }
   printf("\nEnter the Item's code:");
   scanf("%d", &scode);
   temp = start;
   for (temp != NULL; temp = temp->next;)
   {
      if (scode == temp->itemcode)
      {
         printf("\nEnter the Sales Quantity:");
         scanf("%d", &squant);
         createsalesnode(scode, squant);
      }
      else
         printf("Sorry wrong item code.\n Please try again\n");
   }
}
void login_as_manager()
{
   for (;;)
   {
      printf("1. Insert a new item\n");
      printf("2. Traverse through the item.\n");
      printf("3. Delete an item\n");
      printf("4. Modify an item\n");
      printf("5. Logout from Manager A/c\n");
      scanf("%d", &input);
      if (input == 1)
      {
         printf("Enter values of item:\n");
         printf("Enter the item code:");
         scanf("%d", &itemcode);
         printf("Enter name of the item:");
         scanf("%s", &itemname);
         printf("Enter price of the item:");
         scanf("%d", &cost);
         insert_at_end(itemcode, itemname, cost);
      }
      else if (input == 2)
         traverse();
      else if (input == 3)
      {
         printf("Enter the position of the item:");
         scanf("%d", &position);
         position = position - 1;
         delete_item(position);
      }
      else if (input == 4)
      {
         printf("Enter the position to be modified:");
         scanf("%d", &position);
         printf("Enter values of item:\n");
         printf("Enter the item code:");
         scanf("%d", &itemcode);
         printf("Enter name of the item:");
         scanf("%s", &itemname);
         printf("Enter price of the item:");
         scanf("%d", &cost);
         position = position - 1;
         modify_item(position, itemcode, itemname, cost);
      }
      else if (input == 5)
      {
         break;
      }
      else
         printf("Please enter valid input.\n");
   }
}
void login_as_accountant()
{
   for (;;)
   {
      printf("1. Biling\n");
      printf("2. Print current sales bill\n");
      printf("3. Get sales Records\n");
      printf("4. Clear sales Records\n");
      printf("5. Logout from Accountant's A/c\n");
      scanf("%d", &input);
      if (input == 1)
      {
         addsales();
      }
      else if (input == 2)
         printbill();
      else if (input == 4)
      {
         salesrecord();
      }
      else if (input == 4)
      {
         free(sstart);
         sstart = NULL;
      }
      else if (input == 4)
      {
         printf("Enter the position to be modified:");
         scanf("%d", &position);
         printf("Enter values of item:\n");
         printf("Enter the item code:");
         scanf("%d", &itemcode);
         printf("Enter name of the item:");
         scanf("%s", &itemname);
         printf("Enter price of the item:");
         scanf("%d", &cost);
         position = position - 1;
         modify_item(position, itemcode, itemname, cost);
      }
      else if (input == 5)
         break;
      else
         printf("Please enter valid input.\n");
   }
}
int main()
{
   int loginway = 0;
   char managerid, managerpass, billingpass, bllingid1, managerid1, managerpass1, billingpass1, bllingid;
   printf("Which way you want to login?\n");
   printf("Enter 1 to login as a Manager:\n");
    printf("Enter 2 to login as a Manager:\n");
   scanf("%d", &loginway);
   if (loginway == 1)
      login_as_manager();
   if (loginway == 2)
      login_as_accountant();
   return 0;
}
