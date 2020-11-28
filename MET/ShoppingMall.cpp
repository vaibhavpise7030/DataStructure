
#include<iostream>
#include<string.h>
using namespace std;

class Mall
{
public:
        int Itemno;
        double Price;
        int Qty;

public:
    Mall(int Itemno,double Price, int Qty)
    {
        this->Itemno=Itemno;
        this->Price=Price;
        this->Qty=Qty;
    }

    Mall()
    {
    }

   void Display()
   {
       cout<<"ID : "<<this->Itemno<<" Price : "<<this->Price<<" Quatity : "<<this->Qty<<endl;
   }
};

typedef struct small
{
    Mall data;
    struct small *prev;
    struct small *next;
}NODE;

NODE *root=NULL;
NODE *last=NULL;

class MallADT
{
public:

    MallADT()
    {
    }

    NODE* createNode(Mall ref)
    {
        NODE *newnode= new NODE();
        newnode->data=ref;
        newnode->prev=NULL;
        newnode->next=NULL;
        return newnode;
    }

    public: void AddItem(Mall ref)
    {
        NODE *newnode= createNode(ref);

        if(root==NULL)
        {
            root=newnode;
            last=newnode;
        }
        else
        {
            NODE *trav= root;

            while(trav->next!=NULL)
            {
                trav=trav->next;
            }

            trav->next=newnode;
            newnode->prev=trav;
            last= newnode;
        }
    }


    int search(int no)
    {
        NODE *trav=root;

        while(trav!=NULL)
        {
            if(trav->data.Itemno==no)
            {
                trav->data.Display();
                return 1;
            }
            else
            {
                trav=trav->next;
            }
        }
        return 0;
    }

    void del(int no)
    {
        NODE *trav=root;
        NODE *temp;
        NODE *l= last;


        if(trav->data.Itemno==no)
        {
            root= trav->next;
            root->prev=NULL;

            delete trav;
        }

        else if(l->data.Itemno==no)
        {
            l->prev->next=NULL;
            last= l->prev;
            delete l;
        }
        else
        {
            while(trav!=NULL)
        {
            if(trav->data.Itemno==no)
            {
                temp =trav;

                temp->next->prev= temp->prev;
                temp->prev->next= temp->next;

                delete temp;

            }
            else
            {
                trav=trav->next;
            }
        }

        }

    }

    public: void print()
    {
        NODE *trav= root;

        while(trav!=NULL)
        {
            trav->data.Display();
            trav=trav->next;
        }
    }
};



int main()
{
    MallADT ob;

    Mall m1(101,25000,5);
    Mall m2(102,50000,2);
    Mall m3(103,30000,4);

    ob.AddItem(m1);
    ob.AddItem(m2);
    ob.AddItem(m3);

   /* if(ob.search(102))
    {
        cout<<"Found"<<endl;
    }
    else
    {
        cout<<"Not Found"<<endl;
    }*/

    ob.del(101);
    ob.del(103);

    ob.print();

    return 0;
}







