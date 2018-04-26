#include <iostream>
using namespace std;
/*
Write a class for Bubble sort. It should include:
1. Function that takes an array as input along with the size of the array. It must return the sorted array using Bubble sort.
2. Function that takes an linked list as input. It must return the sorted linked list using Bubble sort.
*/


class node
{
 public:
 int data;
 node *next;
};

//USUAL LINKED LIST STUFFS  
class linkedList
{
 public:
 int size=0;
 node *head,*tail;
 linkedList()
 {
  head=NULL;
  tail=NULL;
 }
 void addNode(int data)
 {
  node *temp=new node;
  temp->data=data;
  temp->next=NULL;
  if(head==NULL)
  {
   head=temp;
   tail=temp;
  }
  else
  {
   tail->next=temp;
   tail=temp;
  }
  size++;
 }
 void display()
 {
  node *temp=head;
  while(temp!=NULL)
  {
   cout<<temp->data<<"\t";
   temp=temp->next;
  }
 }
};


//HERE I HAVE TAKEN AN ARRAY THROUGH THE HELP OF A CLASS 
//FOR BETTER UTILISATION OF THE MODULARITY

class array
{
    public:
    int *arr;
    int len;
    array()
    {
        len=1;
        arr=new int[len];
    }
    void display()
    {
      for(int a=0;a<len;a++)
      {
        cout<<arr[a]<<"\t";
      }
    }
};

class BUBBLESORT
{
  public:
  
  //THIS FUNCTION IS FOR THE SORTING OF AN ARRAY
  int* bubbleSort(int *arr, int n)
 {
   int i, j;
   for (i = 0; i < n-1; i++)                           //THIS LOOP IS TO TRAVERSE THROUGH ALL THE ELEMENTS
   {
       // Last i elements are already in place   
       for (j = 0; j < n-i-1; j++) 
           if (arr[j] > arr[j+1])                      //COMPAARING ADJACENT ELEMENTS AND 
           {                                           //SWAPPING ACCORDINGLY
             int tmp=arr[j];
             arr[j]=arr[i];
             arr[i]=tmp;
           }
   }
    return arr;   
  }
  
  
  //TO TEST THE FUNCTIONING OF THE BUBBLESORTING OF AN ARRAY
  void testarr()
  {
    cout<<"\nEnter the number of array elements: ";
    int s;
    cin>>s;
    array A,ANEW;
    A.len=s;
    ANEW.len=s;
    cout<<"\nInput the array: ";
    for(int i=0;i<s;i++)
    {
     cin>>A.arr[i];
    }
    ANEW.arr=bubbleSort(A.arr,s);
    ANEW.display();
  }
  
    
  //HERE IS THE BUBBLESORT FUNCTION FOR LINKED LIST
  node* bubblesortLL(node* head, node* tail, int size)
  {
    int t;
    node* temp=head;
    for(int i=0;i<size;i++)                                //USING THE SAMECONCEPTASN ARRAY
    {                                                      //THIS LOOP TRAVERSES THROUGH ALL NODES OF THE SLL
      temp=head;
      while(temp!=tail)
      {
        if(temp->data>temp->next->data)                     //COMPARING ADJACENT ELEMENTS OF THE LINKED LIST
        {                                                   //AND THEN SWAPPNG THEM ACCORDINGLY
          t=temp->data;
          temp->data=temp->next->data;
          temp->next->data=t;
        }
        temp=temp->next;
      }
    }
    return head;
  }
 };
