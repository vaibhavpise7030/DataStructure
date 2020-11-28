#include<iostream>
using namespace std;


typedef struct node
{
	int data;
	struct node *left;
	struct node *right;
}NODE;

static int cnt;

class Tree
{
public:
		
	NODE* createNode(int data)
	{
		NODE *ref=new NODE;
		ref->data=data;
		ref->left=NULL;
		ref->right=NULL;
		return ref;
	}	
	
	NODE* AddNode(NODE *root, int data)
	{
		NODE *newnode= createNode(data);
		
		if(root==NULL)
		{
			return newnode;
		}
		else
		{
			if(newnode->data<root->data)
			{
				if(root->left==NULL)
				{
					root->left=newnode;
				}
				else
				{
					AddNode(root->left,data);
				}
			}
			else
			{
				if(root->right==NULL)
				{
					root->right=newnode;
				}
				else
				{
					AddNode(root->right,data);
				}
			}
		}	
	}
	
	void inorder(NODE *root)
	{
		if(root!=NULL)
		{
			inorder(root->left);
			cout<<"   "<<root->data;
			inorder(root->right);	
		}
	}
	
	void preorder(NODE *root)
	{
		if(root!=NULL)
		{
			cout<<"   "<<root->data;
			preorder(root->left);
			preorder(root->right);	
		}
	}
	
	void postorder(NODE *root)
	{
		if(root!=NULL)
		{
			postorder(root->left);
			preorder(root->right);	
			cout<<"   "<<root->data;
		}
	}
	
	int count(NODE *root)
	{
		if(root!=NULL)
		{
		    count(root->left);
			count(root->right);	
			++cnt;		
		} 
		return  cnt;                                 
	}                                          
};
                                   

int main()
{
	Tree ob;
	NODE *root= ob.AddNode(NULL,50);
	ob.AddNode(root,40);
	ob.AddNode(root,30);
	ob.AddNode(root,80);
	ob.AddNode(root,20);
	ob.AddNode(root,35);
	//ob.inorder(root);
	
	//ob.postorder(root);
	//ob.preorder(root);
	cout<<ob.count(root);
//	cout<<cnt;
}
