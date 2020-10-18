
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
    NODE *rear;

     LinkedList()
    {
        rear=NULL;
    }

    NODE* createNode(int b)
    {
        NODE *ref= new NODE;
        ref->data=b;
        ref->next=NULL;
        return ref;
    }

    void Enque(int a)
    {
        NODE *newnode;
        newnode= createNode(a);

        if(rear== NULL)
        {
            rear=newnode;
        }
        else
        {
            NODE *trav;
            trav=rear;

            while(trav->next!=NULL)
            {
                trav=trav->next;
            }
            trav->next=newnode;
        }
    }

    void Dque()
    {
        if(rear==NULL)
        {
            cout<<"List is Empty"<<endl;
        }
        else
        {
            NODE *temp;
            temp=rear;
            rear=temp->next;
            cout<<"Deleted Element: "<<temp->data<<endl;
            delete temp;
        }
    }

    void display()
    {
        if(rear==NULL)
        {
            cout<<"List is Empty"<<endl;
        }
        else
        {
            NODE *trav;
            trav=rear;

            while(trav!=NULL)
            {
                cout<<trav->data<<"\t";
                trav=trav->next;
            }
            cout<<"\n"<<endl;
        }

    }

};

int main()
{
    int choice;
    LinkedList ob;
   // ob.init();
	cout<<" \n1.Enque \n2.Dque \n3.display \n0.Exit"<<endl;
    do
    {
        cout<<"Enter Choice"<<endl;
        cin>>choice;

        switch(choice)
        {
        case 1:
            int val;
            cout<<"Enter Element"<<endl;
            cin>>val;
            ob.Enque(val);
            break;

        case 2:
            ob.Dque();
            break;

        case 3:
            ob.display();
            break;

        case 0:
            cout<<"Exit"<<endl;
            break;

        default:
            cout<<"Invalid Choice"<<endl;

        }

    }while(choice!=0);

    return 0;
}
