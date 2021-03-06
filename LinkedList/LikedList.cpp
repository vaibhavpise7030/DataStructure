#include<iostream>
using namespace std;

typedef struct node
{
	int data;
	
	struct node *next;
}NODE;

class LinkedList
{
	public:
		NODE *root;
	public:
		void init()
		{
		root=NULL;
		}
		NODE* createNode(int a)
		{
	      NODE *ref=new NODE;
		  ref->data=a;
		  ref->next=NULL;
		  return ref;	
		}
		
		void insertLeft(int b)
		{
			NODE *newnode;
			newnode=createNode(b);
			
			if(root==NULL)
			{
				root=newnode;
			}
			else
			{
				newnode->next=root;
				root=newnode;
			}
								
		}
		void insertRight(int c)
		{
			NODE *newnode,*trav;
			newnode=createNode(c);
			if(root==NULL)
			root=newnode;
			else
			{
				trav=root;
				while(trav->next!=NULL)
				{
					trav=trav->next;
				}
				trav->next=newnode;
			}
		}
		
		void display()
		{
			NODE *trav;
			trav=root;
			while(trav!=NULL)
			{
				cout<<trav->data<<"\t";
				trav= trav->next;
			}
			cout<<"\n"<<endl;
		}
		void deleteLeft()
		{
			if(root==NULL)
			{
				cout<<"LinkedList is Empty"<<endl;
			}
			else
			{
				NODE *temp;
				temp=root;
				root=root->next;
				cout<<"Deleted :"<<temp->data<<endl;
				delete temp;
			}
		}
		void deleteRight()
		{
			if(root==NULL)
			{
				cout<<"LinkedList is Empty"<<endl;
			}
			else
			{
				
				NODE *trav,*temp;
				trav=root;
				while(trav->next!=NULL)
				{
					temp=trav;
					trav=trav->next	;	
				}
				temp->next=NULL;
				cout<<"Deleted : "<<trav->data<<endl;
			    delete trav;
				
			}
		}
		
		int search(int key)
		{
			NODE *trav;
			trav=root;
			if(root==NULL)
			{
				cout<<"LinkedList is Empty"<<endl;
			}
			else
			{
			
			while(trav!=NULL)
			{
				if(key==trav->data)
				{
					return 1;
				}
				trav=trav->next;
			}
			
			}			
		}
		
		void deleteElement(int key)
		{
				NODE *trav,*temp,*del;
				trav=root;
				if(root==NULL)
				{
					cout<<"LinkedList is Empty"<<endl;
				}
				else
				{
			
					while(trav!=NULL)
					{
						if(key==trav->data)
					{
						temp->next=trav->next;
						del=trav;
						cout<<"Deleted: "<<del->data<<endl;
						delete del;
						break;
					}
						else
						{
							temp=trav;
						}
						trav=trav->next;
			}
			
			}
			
		}
};

int main()
{
	int choice;
	LinkedList l;
	l.init();
	cout<<" \n1.AddFirst \n2.AddLast \n3.Disp \n4.DeleteRight \n5.DeleteLeft \6.search \n7.delElement \n0.Exit"<<endl;
	
	do
	{
		
		cout<< "Enter choice:"<<endl;
		cin>>choice;
		switch(choice)
		{
			case 1:
				
					int k;
					cout<<"Enter element to Enqueue"<<endl;
					cin>>k;
					l.insertLeft(k);
				break;
				
				case 2:
					int j;
					cout<<"Enter element to Enqueue"<<endl;
					cin>>j;
					l.insertRight(j);
					break;
					
				case 3:
				    l.display();
					break;
					
				case 4:
					l.deleteRight();
					break;
					
				case 5:
					l.deleteLeft();
					break;
				
				case 6:
					int a;
					cout<<"Enter key to be searched"<<endl;
					cin>>a;
					if(1==l.search(a))
					{
						cout<<"Data is Found"<<endl;
					}
					else
					{
						cout<<"Data is Not Found"<<endl;
					}
					break;
					
				case 7:
					int d;
					cout<<"Enter element to be delete :"<<endl;
					cin>>d;
					l.deleteElement(d);
					break;
				case 0:
					cout<<"Exit"<<endl;
					break;
					
					default:
						cout<<"Enter Valid Choice"<<endl;
	}
	}while(choice!=0);

}


