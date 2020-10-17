#include<iostream>
using namespace std;
struct node
{
	int data;
	struct node *next;
};

class CircularLinkedList
{
	public:
	node *root,*last,*trav;

	void createLinkedList()
	{
		root=last=NULL;
	}
	void insertRight(int e)
	{
		node *n;
		n=new node;
		n->data=e;
		n->next=NULL;
		if(root==NULL)
		{
			root=last=n;
			n=root;
		}
		else
		{
			last->next=n;
			last=n;
			last->next=root;
		}
	}
	void cycleList(int cycle)
	{
	   	int c=0;
	    trav=root;
	    while(c!=cycle)
	    {
	        while(trav->next!=root)
	         trav=trav->next;   
	        root=trav;
	       	c++; 
	    }
	}
	
	void printList()
	{
		node *t;
		if(root==NULL)
		cout<<"Empty List";
		else
		t=root;
		do
		{
			cout<<t->data<<" ";
			t=t->next;
		}
		while(t!=root);
	}
};

int main()
{
	CircularLinkedList cl;
	cl.createLinkedList();
	int a,c;
	do
	{
		cout<<"\n1.insertRight: \n2.printList: \n3.cycleList \n0.Exit:";
		cin>>c;
		switch(c)
		{
			case 1:
				cout<<"Enter Data:";
				cin>>a;
				cl.insertRight(a);
				break;
				
			case 2:
				cl.printList();
				break;
				
			case 3:
				cl.cycleList(2);
				break;
		
			case 0:
				cout<<"Exiting";
				break;
				
			default:
				cout<<"Invalid Input";
		}
	}
	while(c!=0);
}
