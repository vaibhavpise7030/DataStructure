#include<iostream>
using namespace std;

typedef struct node
{
	int data;
	struct node *next;
	struct node *previous;
}NODE;
static int cnt;
class Doubly
{
	public:
	
	NODE* root=NULL;
	
	NODE* createnode(int a)
	{
		NODE* newnode=new node;
		newnode->data=a;
		newnode->next=NULL;
		newnode->previous=NULL;
		return newnode;
	}
	
	void insertleft(int b)
	{
		cnt++;
		NODE *newnode=createnode(b);
		if(root==NULL)
		{	
		 root=newnode;
		}
		
		else
		{
			root->previous=newnode;
			newnode->next=root;
			root=newnode;
		}
	 
	}
	void insertRight(int c)
	{
		cnt++;
		NODE *newnode=createnode(c);
		
		if(root==NULL)
		{
			root=newnode;
		}
		
		else
		{
			NODE *trav=root;
			while(trav->next!=NULL)
			{
				trav=trav->next;
			}
			
			trav->next=newnode;
			newnode->previous=trav;
		}		
	}
	void AddatPosition(int data,int pos)
	{       
	     
			NODE *newnode=createnode(data);
			if(cnt==pos-1)
			{
				insertRight(data);
			}
			else if(cnt<pos)
			{
				cout<<"Invalid position"<<endl;
			}
			else if(root==NULL || pos<=1)
			{
				insertleft(data);
			}
			else
			{
				NODE *trav=root;
			
			 for(int i=1;i<pos-1;i++)
			 {
			 	trav=trav->next;	 	
			 }
			 
			 newnode->next=trav->next;
			 trav->next->previous=newnode;
			 trav->next=newnode;
			 newnode->previous=trav;
			 cnt++;		 
			}
	}
	
	void DelAtLeft()
	{
		if(root==NULL)
		{
			cout<<"List is Empty"<<endl;
		}
		else
		{
			NODE *temp=root;
			root=root->next;
			root->previous=NULL;
			cout<<"Delete :"<<temp->data<<endl;
			delete temp;
			cnt--;
		}
	}
	
	void DelAtRight()
	{
		if(root==NULL)
		{
			cout<<"List is Empty"<<endl;
		}
		else
		{
			NODE *trav=root;
			while(trav->next!=NULL)
			{
				trav=trav->next;
			}
			
			NODE *temp=trav;
			trav->previous->next=NULL;
			cout<<"Deleted: "<<temp->data<<endl;
			delete temp;
			cnt--;
		}
	}
	
	void DelAtPos(int pos)
	{
		
			if(cnt==pos)
			{
				DelAtRight();
			}
			else if(cnt<pos)
			{
				cout<<"Invalid position"<<endl;
			}
			else if(root==NULL || pos<=1)
			{
				DelAtLeft();
			}
			else
			{
				NODE *trav=root;
			
			 for(int i=1;i<pos;i++)
			 {
			 	trav=trav->next;	 	
			 }
			 NODE *temp=trav;
			 
			 trav->previous->next=trav->next;
			 trav->next->previous=trav->previous;
			 cout<<"Deleted: "<<temp->data<<endl;
			 delete temp;
			cnt--;		 
			}
	}
	
	void DelALL()
	{
		if(root==NULL)
		{
			cout<<"List is empty"<<endl;
		}
		else
		{
			NODE *temp;
			while(root!=NULL)
			{
				temp=root;
				root=root->next;
				delete temp;
			}
			cnt=0;
		}
	}
	
	
	void print()
	{
		NODE *trav=NULL;
		trav=root;
		if(root==NULL)
		{
			cout<<"List is empty"<<endl;
		}
		else
		{
			cout<<"Inforward direction"<<endl;
			
			while(trav!=NULL)
			{		
				cout<<"\t"<<trav->data;
				trav=trav->next;
			}
		
			trav=root;
			while(trav->next!=NULL)
			{
				trav=trav->next;
			}
			cout<<"\n";
		
		cout<<"Inreverse direction"<<endl;
			while(trav!=NULL)
			{
				cout<<"\t"<<trav->data;
				trav=trav->previous;
			}
			cout<<"\n";	
    	}	
	}
		
};
	
	int main()
	{
		Doubly ob;
		int choice;
		cout<<"\n1:AddFirst \n2:AddLast \n3:Addatposition \n4:DelFirst \n5:DelLAst \n6:Count \n7: DelPosition \n8:DeleteAll \n9: Display \n0:Exit\n"<<endl;
		do
		{
			cout<<"enter choice"<<endl;
			cin>>choice;
			
			switch(choice)
			{
				case 1:
					int val;
					cout<<"Enter Element"<<endl;
					cin>>val;
					ob.insertleft(val);
					break;
					
				case 2:
					int val1;
					cout<<"Enter element"<<endl;
					cin>>val1;
					ob.insertRight(val1);
					break;
					
				case 3:
					int val2,pos;
					
					cout<<"enter position"<<": ";
					cin>>pos;
					
					cout<<"enter element"<<": ";
					cin>>val2;
					ob.AddatPosition(val2,pos);
					break;
					
				case 4:
					ob.DelAtLeft();
					break;
					
				case 5:
					ob.DelAtRight();
					break;
				
				case 6:
					cout<<"no of nodes "<<cnt<<endl;
					break;
					
				case 7:
					int d;
					cout<<"Enter Position: ";
					cin>>d;
					ob.DelAtPos(d);	
					break;
					
				case 8:
					ob.DelALL();
					break;
					
				case 9:
					ob.print();
					break;
				
				case 0:
					cout<<"Exit"<<endl;
					break;
					
				default:
					cout<<"Invalid Choice"<<endl;				
			}
						
		}while(choice!=0);
		
	}
