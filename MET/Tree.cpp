#include<iostream>
using namespace std;

typedef struct node
{
    int data;
    struct node *r;
    struct node *l;
}NODE;

static int cnt;
static int leafnode;

class Tree
{

public:

    NODE* createNode(int data)
    {
        NODE *ref=new NODE;
        ref->data=data;
        ref->r=NULL;
        ref->l=NULL;

        return ref;
    }

    NODE* insert(NODE *root, int a)
    {
        NODE *newnode=createNode(a);

        if(root==NULL)
        {
            return newnode;
        }

        else
        {
            if(newnode->data < root->data)
            {
                if(root->l==NULL)
                {
                    root->l=newnode;
                }
                else
                {
                    insert(root->l,a);
                }
            }
            else
            {
                if(root->r==NULL)
                {
                    root->r=newnode;
                }
                else
                {
                    insert(root->r,a);
                }

            }
        }
    }

    void inorder(NODE *root)
    {
        if(root!=NULL)
        {
        inorder(root->l);
        cout<<"\t"<<root->data;
        inorder(root->r);
        }
    }

    void preorder(NODE *root)
    {
        if(root!=NULL)
        {
            cout<<"\t"<<root->data;
            preorder(root->l);
            preorder(root->r);
        }
    }

    void postorder(NODE *root)
    {
        if(root!=NULL)
        {
            postorder(root->l);
            postorder(root->r);
            cout<<"\t"<<root->data;
        }
    }

    int count(NODE *root)
    {
        if(root!=NULL)
        {
        count(root->l);
        cnt++;
        count(root->r);
        }
        return cnt;
    }


    int countLeaf(NODE *root)
    {
        if(root!=NULL)
        {
        countLeaf(root->l);

        if(root->l==NULL && root->r==NULL)
        {
            leafnode++;
        }

        countLeaf(root->r);
        }
        return leafnode;
    }

};

int main()
{
    Tree ob;

    NODE *root=NULL;
    root= ob.insert(root,50);

    ob.insert(root,30);
    ob.insert(root,20);
    ob.insert(root,80);
    ob.insert(root,70);
    ob.insert(root,35);
    ob.insert(root,100);

    //ob.inorder(root);

    //ob.preorder(root);
    //ob.postorder(root);
   //cout<<endl<<ob.count(root)<<endl;

   cout<<ob.countLeaf(root);
}
