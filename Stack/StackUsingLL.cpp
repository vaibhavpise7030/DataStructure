#include <iostream>
using namespace std;

typedef struct node
{
	int data;
	struct node *next;
}NODE;

class DynamicStack
{
	public:
		NODE *tos;
		
		NODE* createNode(int e)
		{
			NODE *n=new NODE;
			n->data=e;
			n->next=NULL;
			return n;
		}
		
		void createStack()
		{
			tos=NULL;	
		}
		
		void push(int a)
		{
			NODE *newnode=createNode(a);
			if(tos==NULL)
			{
				tos=newnode;
			}
			else
			{
				newnode->next=tos;
				tos=newnode;
			}
		}
		void pop()
		{
			if(tos==NULL)
			{
				cout<<"stack is empty"<<endl;
			}
			else
			{
				NODE *temp;
				temp=tos;
				tos=tos->next;
				cout<<"poped: "<<temp->data;
				delete temp;
			}
		}
		
		void printStack()
		{
			NODE *trav;
			trav=tos;
			while(trav!=NULL)	
			{
				cout<<trav->data<<"\t";
				trav=trav->next;
			}
			cout<<"\n"<<endl;
		}
};



int main()
{
	int choice;
	DynamicStack s;
	s.createStack();
	cout<<" \n1.push \n2.pop  \n3.print \n0.Exit"<<endl;
	do
	{
		cout<< "Enter choice:"<<endl;
		cin>>choice;
		switch(choice)
		{
			case 1:
				
					int k;
					cout<<"Enter element to push"<<endl;
					cin>>k;
					s.push(k);
				break;
				
				case 2:
						s.pop();
					break;
					
				case 3:
						s.printStack();
						break;				
				case 0:
					cout<<"Exit"<<endl;
					break;
					
					default:
						cout<<"Enter Valid Choice"<<endl;
		}
	}while(choice!=0);
}

