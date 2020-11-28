#include<iostream>
#include<string.h>
using namespace std;

class Student
{
	public:
		
    int Id;

    string Name;
    string Course;
    double Percentage;
public:

    Student( string name,string Course,double Percentage)
    {
        static int AutoID=101;
        this->Id=++AutoID;
        this->Name=name;
        this->Course=Course;
        this->Percentage=Percentage;
    }

    Student()
    {
    }

    void Disp()
    {
        cout<<"Id: "<<this->Id<<" Name: "<<this->Name<<" Course: "<<this->Course<<" Percentage:"<<this->Percentage<<endl;
    }
};

static int size;
Student arr[4];

void AddStudent(Student s)
{
    if(size == 4)
    {
        cout<<"Array is full"<<endl;
    }
    else
    {
        arr[size++]=s;
    }

}

void BubbleSort()
{
	int i,j;
	Student temp;
	
	for(i=0;i<size-1; i++)
	{
		for(j=0; j<size-1; j++)
		{
			if(arr[j].Percentage>arr[j+1].Percentage)
			{
				temp= arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
}

void SelectionSort()
{
	int i,j,key;
	Student temp;
	
	for(i=0;i<size-1; i++)
	{
		key=i;                 
		                        
		for(j=i+1; j<size; j++)
		{
			if(arr[key].Percentage>arr[j].Percentage)
			{
				key=j;
			}
		}
		
		temp=arr[i];
		arr[i]=arr[key];
		arr[key]=temp;		
	}	
}

void printAll()
{
    for(int i=0; i<size;i++)
    {
        arr[i].Disp();
    }
}

void PrintIndex(int index)
{
    arr[index].Disp();
}

int main()
{
    Student s1("Akash","Dac",60);
    Student s2("Ganesh","DBDA",70);
    Student s3("Vaibhav","DESD",50);
    Student s4("Anand","PGAI",40);
    //Student s5("Patil");

    AddStudent(s1);
    AddStudent(s2);
    AddStudent(s3);
    AddStudent(s4);
   // AddStudent(s5);
//BubbleSort();

SelectionSort();
    printAll();
   // PrintIndex(2);
    return 0;
}
