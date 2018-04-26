/*
Write a class for Quick sort. It should include:
1. Function that takes an array as input along with the size of the array. It must return the sorted array using Quick sort.
2. Function that takes an linked list as input. It must return the sorted linked list using Quick sort.
*/



#include<iostream>
using namespace std;

class node
{
 public:
 int data;
 node *next;
};

//THE USUAL STUFFS IN A SINGLE LINKED LIST
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
   cout<<temp->data<<" ";
   temp=temp->next;
  }
 }
};

//HERE IS THE CLASS NAMED QUICKSORT

class QUICKSORT
{
public:
    
    //This function puts the pivot(i.e. the last element in this case) in its correct chronological position
    //and sepaprates the array into two halves, returning the index of the new position of pivot
    
   
    
int arrangeARR(int *arr,int l,int r)
{
    int pivot=arr[r];
    int x=l-1;                                    //stores the index of the recent smaller element than the pivot
    for(int i=l;i<r;i++)
    {
        if(arr[i]<=pivot)                         //if the element is smaller
        {
            x++;
            int t=arr[i];                         //swapping 
            arr[i]=arr[x];
            arr[x]=t;
        }
    }
    int tmp=arr[x+1];
    arr[x+1]=arr[r];
    arr[r]=tmp;
    return x+1;                                   //the new index of the pivot
}

    
    //This is a recursive function that individually recurses the left half and right half of the array
int *qsort(int *ar, int left, int right)
{
    if(left<right)
    {
        int s=arrangeARR(ar, left, right);        //s stores the index of pivot
        int* ax=qsort(ar,left,s-1);
        int* bx=qsort(ar,s+1,right);
    }
    return ar;
}
    
   
void display(int* ars,int s)
{
    for(int a=0;a<s;a++)
    {
        cout<<*(ars+a)<<"\t";
    }
}
    
    //This functon is just to test the array passed hence
int testarr()
{
    int A[7]={3,5,7,2,0,9,4};
    int *sortarr=qsort(A,0,6);
    display(sortarr,7);
    return 0;
}

node *arrangeLL(node *head, node *end, node *newHead, node *newEnd)
{
    node *pivot = end;
    node *prev = NULL, *cur = head, *tail = pivot;
    /*
    
    This would separate the linked list and create a nw one, with newhead and newend as head and tail
    In the following while loop, if brings all the element to the front of pivot 
    And else brings all the larger element to the back of pivot
    
    */
    while (cur != pivot)
    {
        if (cur->data < pivot->data)
        {
            /*
            First node that has a value less than the pivot - becomes
            the new head
            */
            if (newHead == NULL)
                newHead = cur;
            prev = cur;  
            cur = cur->next;
        }
        else 
        {
            /*
             If cur node is greater than pivot
             Move cur node to next of tail, and change tail
            */
            if (prev!=NULL)
                prev->next = cur->next;
            node *tmp = cur->next;
            cur->next = NULL;
            tail->next = cur;
            tail = cur;
            cur = tmp;
        }
    }
    // If the pivot data is the smallest element in the current list,
    // pivot becomes the head
    if (newHead == NULL)
        newHead = pivot;
 
   
    newEnd = tail;
    return pivot;
}

    
node *quickSortLL(node *head, node *tail)
{
    
    if (head==tail)
        return head;
    /*
    
    The main job here is to distinctly separate the linked list into two 
    such that the left half is recursed and the right half is recursed separately
    newh and newt does that
    
    */
 
    node *newh = NULL, *newt = NULL;
    node *pivot = arrangeLL(head, tail, newh, newt);
    /*
     If pivot is the smallest element - no need to recur for
     the left part.
    */
    if (newh != pivot)
    {
        
        node *tmp = newh;
        while (tmp->next != pivot)
            tmp = tmp->next;
        tmp->next = NULL;
 
        
        newh = quickSortLL(newh, tmp);
 
        //Since I had already broken the list, so re-linking the list once again
        node* c=newh;
        while (c != NULL && c->next != NULL)
          c = c->next;
        tmp=c;
        tmp->next =  pivot;
    }
    pivot->next = quickSortLL(pivot->next, newt);
    return newh;
}

};
