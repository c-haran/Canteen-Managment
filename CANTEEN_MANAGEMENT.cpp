#include<iostream>
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<cstring>
#include<iomanip>
using namespace std;
char name[50],c[20];
int ID[100],BILL[1000];
struct Item
{
	int id;
	char ItemName[100];
	int ItemPrice;
	int ItemCount;
	struct Item *next;
}*First=NULL,*Primary=NULL,*Temp=NULL,*SelectedItemsList=NULL;

class Canteen
{	
	public:
		Canteen();
		Canteen(char pu);
};
Canteen::Canteen()
{
		cout<<"\t\t\t\t\t\t\tINSTITUTE CANTEEN MANAGEMENT";
    	cout<<"\nCONSUMER INFORMATION"<<endl;
    	cout<<"===================="<<endl;
   		cout<<"\nNAME:";
    	gets(name);
    	mobile:;
    	cout<<"\nMOBILE NUMBER:";
    	cin>>c;
    	int len=strlen(c);
    	if(len!=10)
    	{
    		cout<<"Enter a Valid mobile number."<<endl;
    		goto mobile;
		}
}
Canteen::Canteen(char input)
{
		int h;
		cout<<"\n\t\t\t\t INSTITUTE CANTEEN MANAGEMENT\n";
		cout<<"\n\t\t\t\t  BILL INFO\n";
		for (h = 0; name[h]!='\0'; h++) 
		{
    		if(name[h] >= 'a' && name[h] <= 'z')
		    {
        		name[h] = name[h] - 32;
      		}
   		}
		cout<<"\nNAME:"<<name;
		cout<<"\nMOBILE NUMBER:"<<c<<endl;
		cout<<"================================================="<<endl;
}
int IDstore(int ID[],int Id,int i)
{
	for(int k=0; k<i-1; k++)
    {
        if(ID[k]==Id)
        {
           		 
        	return 1;
		}
		
 
    }
    	return 0;
}
void CreatListBySelf()
{
	struct Item *Last;
	First=new Item;
	First->id=1;
	strcpy(First->ItemName,"Buiscuits");
	First->ItemCount=1000;
	First->ItemPrice=10;
	First->next=NULL;
	Last=First;
	Primary=First;
	
	Temp=new Item;
	Temp->id=2;
	strcpy(Temp->ItemName,"Chocolates");
	Temp->ItemCount=1000;
	Temp->ItemPrice=5;
	Temp->next=NULL;
	Last->next=Temp;
	Last=Temp;
  	
  	Temp=new Item;
	Temp->id=3;
	strcpy(Temp->ItemName,"Chips");
	Temp->ItemCount=1000;
	Temp->ItemPrice=10;
	Temp->next=NULL;
	Last->next=Temp;
	Last=Temp;
	
	Temp=new Item;
	Temp->id=4;
	strcpy(Temp->ItemName,"Soaps");
	Temp->ItemCount=1000;
	Temp->ItemPrice=25;
	Temp->next=NULL;
	Last->next=Temp;
	Last=Temp;

	Temp=new Item;
	Temp->id=5;
	strcpy(Temp->ItemName,"Tooth Paste");
	Temp->ItemCount=1000;
	Temp->ItemPrice=36;
	Temp->next=NULL;
	Last->next=Temp;
	Last=Temp;
	
	Temp=new Item;
	Temp->id=6;
	strcpy(Temp->ItemName,"Hair Oil");
	Temp->ItemCount=1000;
	Temp->ItemPrice=10;
	Temp->next=NULL;
	Last->next=Temp;
	Last=Temp;
	
	Temp=new Item;
	Temp->id=7;
	strcpy(Temp->ItemName,"Detergent");
	Temp->ItemCount=1000;
	Temp->ItemPrice=45;
	Temp->next=NULL;
	Last->next=Temp;
	Last=Temp;
	
	Temp=new Item;
	Temp->id=8;
	strcpy(Temp->ItemName,"Pen");
	Temp->ItemCount=1000;
	Temp->ItemPrice=10;
	Temp->next=NULL;
	Last->next=Temp;
	Last=Temp;
	
	Temp=new Item;
	Temp->id=9;
	strcpy(Temp->ItemName,"Book");
	Temp->ItemCount=1000;
	Temp->ItemPrice=50;
	Temp->next=NULL;
	Last->next=Temp;
	Last=Temp;
	
	Temp=new Item;
	Temp->id=10;
	strcpy(Temp->ItemName,"Perfume");
	Temp->ItemCount=1000;
	Temp->ItemPrice=120;
	Temp->next=NULL;
	Last->next=Temp;
	Last=Temp;
	
}
int BillSum(int arr[], int n)
{
    int sum = 0; 
    for (int i = 0; i < n; i++)
    sum += arr[i];
 
    return sum;
}
void DisplayList(struct Item *DisplayItem)
{	
	while(DisplayItem!=0)
	{
		cout<<"Item Id:"<<DisplayItem->id<<endl;
		cout<<"Item Name:"<<DisplayItem->ItemName<<endl;
		cout<<"Item Cost:"<<DisplayItem->ItemPrice<<"/-"<<endl;
		cout<<endl;
		DisplayItem=DisplayItem->next;
	}
}
void BillDisplayList(struct Item *DisplayItem)
{	
	int p=0;
	while(DisplayItem!=0)
	{
		cout<<"\nItem Id:"<<DisplayItem->id<<endl;
		cout<<"Item Name:"<<DisplayItem->ItemName<<endl;
		cout<<"Item Cost:"<<DisplayItem->ItemPrice<<"/-"<<endl;
		cout<<"Item Count:"<<DisplayItem->ItemCount<<endl;
		cout<<"Total cost of "<<DisplayItem->ItemName<<":"<<DisplayItem->ItemCount*DisplayItem->ItemPrice<<"/-"<<endl;
		BILL[p++]=DisplayItem->ItemCount*DisplayItem->ItemPrice;
		
		cout<<endl;
		
		DisplayItem=DisplayItem->next;
	}
	
	cout<<"Total Bill: Rs "<<BillSum(BILL,p)<<" only"<<endl;
	cout<<"\nThankyou\t\t\tVisit Again"<<endl;
	cout<<"================================================="<<endl;
}

struct Item *SearchInList(struct Item *SearchList,int id2)
{
	while(SearchList!=NULL)
	{
		if(id2==SearchList->id)
		{
			return (SearchList);
		}
		SearchList=SearchList->next;
	}
	
	
		
		return NULL;
	
	
}
struct Item *BuyItems()
{	
	unsigned int Quantity;
	int id1,i=0;
	char LocalChoice;
	struct Item *SelectedItemsListTemp;
	struct Item *SelectedItems;
	SelectedItems=new Item;
	cout<<"\nEnter the Id of your selected item:";
	cin>>id1;
	ID[i++]=id1;
	SelectedItems=SearchInList(First,id1);
	if(SelectedItems!=NULL)
	{
		
		cout<<"\nEnter the quantity of the selected item:";
		cin>>Quantity;
		if(Quantity<=SelectedItems->ItemCount)
		{
			SelectedItems->ItemCount=Quantity;	
			SelectedItems->next=NULL;
			SelectedItemsList=SelectedItems;
			SelectedItemsListTemp=SelectedItems;	
		}
		else
		{
			cout<<"\nSorry , the quantity of the item you selected is OUT OF STOCK"<<endl;
			cout<<"\nAvailable quantity:"<<SelectedItems->ItemCount;
			i--;
			goto function;
		}
		
		function:;
		{
			cout<<"\nDo you want to add some more items?(Y/N):";
			cin>>LocalChoice;
			if (LocalChoice=='Y'||LocalChoice=='y')
			{
				CreatListBySelf();
				cout<<"\nEnter the Id of your selected item:";
				cin>>id1;
				ID[i++]=id1;
				if(IDstore(ID,id1,i)==0)
				{
				SelectedItems=new Item;
				SelectedItems=SearchInList(First,id1);
				if(SelectedItems!=NULL)
				{
					cout<<"\nEnter the quantity of the selected item:";
					cin>>Quantity;
					if(Quantity<SelectedItems->ItemCount)
					{
						SelectedItems->ItemCount=Quantity;
						if(SelectedItemsList==NULL)
						{
							SelectedItemsList=SelectedItems;
						}
						SelectedItemsListTemp->next=SelectedItems;
						SelectedItemsListTemp=SelectedItems;
						SelectedItemsListTemp->next=NULL;
						goto function;
					}
					else
					{
						cout<<"\nSorry , the quantity of the item you selected is OUT OF STOCK"<<endl;
						cout<<"\nAvailable quantity:"<<SelectedItems->ItemCount;
						i--;
						goto function;
					}
				
				}
				else
				{
					cout<<"\nItem Not found\nPlease Enter a valid id"<<endl;	
					i--;
					goto function;
				}
				}
				else
				{
					cout<<"\nItem has been already added,Please try another item"<<endl;
					i--;
					goto function;
				}
			}
			else
			{	
				cout<<"\nThankyou\t\t\tVisit Again"<<endl;
				cout<<"================================================="<<endl;
				return (SelectedItemsList);
			
			}
		}	
	}
	else
	{	
		cout<<"\nItem Not found\nPlease Enter a valid id"<<endl;
		i--;
		goto function;
	}
}
int main()
 {
	unsigned int a;
	char input;
	CreatListBySelf();
	
   	Canteen cc;
   	start:;
	cout<<"\n1.MENU & PURCHASE"<<endl;
	cout<<"2.QUANTITY AVAILABLE"<<endl;
	cout<<"3.EXIT"<<endl;
	cout<<"\nENTER YOUR CHOICE:";
	cin>>a;
	cout<<endl;
    switch(a)
	{
    	case 1:
			DisplayList(First);
    		cout<<"\nDO YOU WANT TO PURCHASE(Y/N):";
    		cin>>input;
			if(input=='Y'||input=='y')
			{	
			
				SelectedItemsList=BuyItems();
				Canteen ff(input);
				BillDisplayList(SelectedItemsList);
			}
			break;
		case 2:
			DisplayList(First);
			goto start;
			break;
		case 3:
			cout<<"\nThankyou\t\t\tVisit Again"<<endl;
			cout<<"================================================="<<endl;
			exit(0);
			break;
		default:
			cout<<"\nEntered a wrong choice\nPlease select an existing choice:"<<endl;
			goto start;;
			
 	}
	return 0;
 
}
