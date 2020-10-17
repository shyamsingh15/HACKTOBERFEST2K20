/*
2) Define a structure “customer” of a book seller that contains following data members
a. name, customer number, customer type, purchase amount, discount.
b. Define the following function to perform the mention tasks.
i. input_data() : to input the data of a customer.
ii. output_data(): to output the data of a customer.
iii. computeDiscount() : to compute discount it uses the following data
Customer type	 Discount
Senior citizen    10%
Student           20%
Author            30%
c. Define an array of structure for 5 customers to perform the above tasks.
*/
#include<stdio.h>
#include<stdlib.h>
struct customer
{
	char name[50],cust_typ;
	int cust_no;
	float purchase_amt,discount;
}customers[5];
//Function to compute discount
float Discount(int i)
{
	if(customers[i].cust_typ=='c')
		return (customers[i].purchase_amt*0.1);
	if(customers[i].cust_typ=='s')
		return (customers[i].purchase_amt*0.2);
	if(customers[i].cust_typ=='a')
		return (customers[i].purchase_amt*0.3);
}
//Function to enter type
char Type()
{
	int t;
	while(1)
	{
		printf("\nPress\n1.Senior citizen\n2.Student\n3.Author\nEnter : ");
		scanf("%d",&t);
		if(t==1)
			return 'c';
		else if(t==2)
			return 's';
		else if(t==3)
			return 'a';
		else 
			printf("\nWrong Choice !!! Please Re-enter\n");
	}
}
//Function to input data
void input(int i)
{
	printf("Enter the name : ");
	scanf("%s",customers[i].name);
	printf("Enter the customer type : \n");
	customers[i].cust_typ=Type();
	printf("Enter the customer number : ");
	scanf("%d",&customers[i].cust_no);
	printf("Enter the purchase amount : ");
	scanf("%f",&customers[i].purchase_amt);
	customers[i].discount=Discount(i);
	printf("\n");
}
//function to output data
void output_data(int i)
{
	
	printf("Name : %s",customers[i].name);
	printf("\nCustomer Number : %d",customers[i].cust_no);
	if(customers[i].cust_typ=='c')
		printf("\nCustomer Type : Senior Citizen");
	if(customers[i].cust_typ=='s')
		printf("\nCustomer Type : Student");
	if(customers[i].cust_typ=='a')
		printf("\nCustomer Type : Author");
	printf("\nPurchase Amount : %f",customers[i].purchase_amt);
	printf("\nNDiscount : %f",customers[i].discount);
	printf("\n");
}
//Driver Function

int main()
{
	int i,n,choice;
	while(1)
	{
		printf("1.Save_data\n2.Show_data\n3.Exit\nEnter your choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1 :
				i=0;
				printf("Enter the value of n : ");
				scanf("%d",&n);
				while(i<n)
				{
					printf("\nEnter the details of %d customer\n",i+1);
					input(i);
					i++;
				}	
			break;
			case 2 :
				i=0;
				while(i<n)
				{
					output_data(i);
					i++;
				}
			break;
			case 3 :
				exit(1);
			break; 
		}
	}
	return 0;
}
