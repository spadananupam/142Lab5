#include<iostream>
#include<ctime>


using namespace std;

class Node 
{

	public:
		int data;
		Node* next;

		Node() 
		{
			data = 0;
			next = NULL;
		}
};

class SLList                        
{
	public:
		Node* head;
		Node* tail;
		int size;
		SLList() {
			head = NULL;
			tail = NULL;
			size = 0;
		}
		
		// Member functions of the SLList class.
		void insert(int d);
		int get(int i);
		int swap(int i,int j);
		int countItems();
		void display();
		Node* getNode(int i);
		int set(int i,int d);
};

Node* SLList::getNode(int i) {
/* 
 * Returns a pointer to the ith element of the list.
 * This function makes the code for insertAt, remove and removeAt
 * functions very readable
 */

	if (i > size || i < 1) {	// Check for validity of i.
		cout << "Invalid element position." << endl;
		return NULL;
	}

	if (i == size) {			// Optimisation. The list entire is not 
		return tail;			// traversed if only the last element is required.
	}

	Node* p = head;				// p is a placeholder variable used to 
	for (int j=1; j<i; ++j) {	// traverse through the list.
		p = p->next;
	}
	return p;
}

int SLList::set(int i, int d) {
	Node* p = getNode(i);
	p->data = d;
	return 0;
}

int SLList::swap(int i, int j) {
	if (i<1 || i>countItems() || j<1 || j>countItems()) {
		cout << "Invalid indices." << endl;
		return -1;
	}
	
	int temp = get(i);
	set(i, get(j));
	set(j, temp);

	return 0;
}

int SLList::get(int i) {
	Node* p = getNode(i);
	return p->data;
}

void SLList::insert(int d) 
{

	Node* new_node = new Node;
	new_node->data = d;
	new_node->next = NULL;

	if (head == NULL) {	
		head = new_node;	// Steps to perform when the list is empty.
		tail = new_node;
	} else {
		tail->next = new_node;	// Steps to perform when list is non-empty.
		tail = new_node;
	}

	++size;
}

int SLList::countItems() 
{
	return size;
}

void SLList::display() 
{
    Node *dis;
    dis=head;
    cout<<"\n";
    while(dis!=head)
    {
        cout<<dis->data<<"\t";
    }
    cout<<"NULL"<<endl;
}

class BUBBLESORT
{
  public:
  
  //THIS FUNCTION IS FOR THE SORTING OF AN ARRAY
  int* sort(int *arr, int n)
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

  
  //HERE IS THE BUBBLESORT FUNCTION FOR LINKED LIST
  Node* sort(Node* head, Node* tail, int size)
  {
    int t;
    Node* temp=head;
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
  


void swap(int a[], int i, int j) {
	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}


class QUICKSORT {
	public:
	void sort(int unsortedMonstrosity[], int start, int end);
	int* sort(int unsortedMonstrosity[], int length);
	void sort(SLList badStuff, int start, int end);
	SLList sort(SLList badStuff);
};

void QUICKSORT::sort(int unsortedMonstrosity[], int start, int end) {
	if (end <= 1)
		return;

	int x = unsortedMonstrosity[start + rand()%end];
	int p=start-1, j=start, q=start+end;

	while (j < q) {
		if (unsortedMonstrosity[j] < x) {
			swap(unsortedMonstrosity, j++, ++p);
		} else if (unsortedMonstrosity[j] > x) {
			swap(unsortedMonstrosity, j, --q);
		} else {
			j++;
		}
	}

	sort(unsortedMonstrosity, start, p-start+1);
	sort(unsortedMonstrosity, q, end-(q-start));
}

int* QUICKSORT::sort(int unsortedMonstrosity[], int length) {
	int* sortedMasterpiece = new int[length];
	for (int i=0; i<length; ++i) {
		sortedMasterpiece[i] = unsortedMonstrosity[i];
	}

	sort(sortedMasterpiece, 0, length);

	return sortedMasterpiece;
}

void QUICKSORT::sort(SLList badStuff, int start, int end) {
	if (end <= 1)
		return;

	int x = badStuff.get(start + rand()%end + 1);
	int p = start-1, j=start, q=start+end;

	while (j < q) {
		if (badStuff.get(j+1) < x) {
			badStuff.swap((j++)+1, 1+(++p));
		} else if (badStuff.get(j+1) > x) {
			badStuff.swap(j+1, 1+(--q));
		} else {
			++j;
		}
	}

	sort(badStuff, start, p-start+1);
	sort(badStuff, q, end-(q-start));
}

SLList QUICKSORT::sort(SLList badStuff) {
	SLList goodStuff;
	for (int i=1; i<=badStuff.countItems(); ++i) {
		goodStuff.insert(badStuff.get(i));
	}

	sort(goodStuff, 0, goodStuff.countItems());

	return goodStuff;
}

//THIS FUNCTION IS USED TO INPUT AND ASSORTS RANDOM VALUES TO THE ARRAY 

void RandomAssortmentArr(int t[], int n) {
	for (int i=0; i<n; i++) {
		t[i] = rand()%100;
	}
}

//THIS FUNCTION IS USED TO INPUT AND ASSORTS RANDOM VALUES TO THE LINKED LIST 

void RandomAssortmentLL(SLList &sll, int n) {
	for (int i=0; i<n; i++) {
		sll.insert(rand()%100);
	}
}

void BSTimeArr(int n) 
{
	int tempA[15000];
	BUBBLESORT bs;
	RandomAssortmentArr(tempA, n);
	clock_t begin = clock();
	bs.sort(tempA, n);
	clock_t end = clock();
	double time = double(end-begin)/CLOCKS_PER_SEC;
	cout << "\nThe time taken for bubblesorting "<<n<<" elements is "<<time;
}

void QSTimeArr(int n) 
{
	int tempA[15000];
	QUICKSORT qs;
	RandomAssortmentArr(tempA, n);
	clock_t begin = clock();
	qs.sort(tempA, n);
	clock_t end = clock();
	double time = double(end-begin)/CLOCKS_PER_SEC;

	cout << "\nThe time taken for quicksorting "<<n<<" elements is "<<time;
}


void BSTimeLL(int n) 
{
	SLList tempLL;
	BUBBLESORT bs;
	RandomAssortmentLL(tempLL, n);
	clock_t begin = clock();
	bs.sort(tempLL.head,tempLL.tail,n);
	clock_t end = clock();
	double time = double(end-begin)/CLOCKS_PER_SEC;

	cout << "\nThe time taken for bubblesorting "<<n<<" nodes in the linked list is "<<time;
}

void QSTimeLL(int n) 
{
	SLList tempLL;
	QUICKSORT qs;
	RandomAssortmentLL(tempLL, n);
	clock_t begin = clock();
	qs.sort(tempLL);
	clock_t end = clock();
	double time = double(end-begin)/CLOCKS_PER_SEC;
    cout<< "\nThe time taken for quicksorting "<<n<<" nodes in the linked list is "<<time;
}

int main() 
{
	cout << "COMPARING RUN-TIME FOR ARRAY" << endl;
	cout << "\n \nBubble sort: " << endl;
	BSTimeArr(10);
	BSTimeArr(100);
	BSTimeArr(250);
	BSTimeArr(500);
	BSTimeArr(800);
	BSTimeArr(1000);

	cout << "\n \nQuick sort: " << endl;
	QSTimeArr(10);
	QSTimeArr(100);
	QSTimeArr(250);
	QSTimeArr(500);
	QSTimeArr(800);
	QSTimeArr(1000);

	cout << "\n \nCOMPARING RUN-TIME FOR LINKED LIST" << endl;
	cout << "\n \nBubble sort: " << endl;
	BSTimeLL(10);
	BSTimeLL(100);
	BSTimeLL(250);
	BSTimeLL(500);
	BSTimeLL(800);
	BSTimeLL(1000);

	cout << "\n \nQuick sort: " << endl;
	QSTimeLL(10);
	QSTimeLL(100);
	QSTimeLL(250);
	QSTimeLL(500);
	QSTimeLL(800);
	QSTimeLL(1000);

	return 0;
}
