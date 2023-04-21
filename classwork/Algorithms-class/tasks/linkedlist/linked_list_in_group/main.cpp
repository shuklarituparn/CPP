#include<iostream>
/*Program to reverse a linked list in a group of given size*/


using namespace std;
class node
{
public:
  int data;
  node *next;			//defining linked list.


    node (int d)		//making constructor for nodes
  {
    data = d;
    next = NULL;
  }
};
void insertAtTail (node * &head, int data)	//function to insert new element at tail of the list
{
  if (head == NULL)
    {
      head = new node (data);
      return;
    }
  node *tail = head;
  while (tail->next != NULL)
    {
      tail = tail->next;
    }
  tail->next = new node (data);
}

int buildList (node * &head)	//function to build the list.
{
  int n;
  cout << "Enter the size of list:";
  cin >> n;
  cout << endl;
  int a = n;
  cout << "Enter data of the nodes\n";
  while (n--)
    {
      int data;
      cin >> data;
      insertAtTail (head, data);	//New element will be inserted at end.
    }
  return a;
}

void printList (node * head)		//function to print linked list.
{
  if (head == NULL)
    {
      return;
    }
  cout << head->data << " ";
  printList (head->next);    //recursive printing the linked list
}

struct node *reverse (node * head, int k)	//function to reverse linked list in groups
{
  if (head == NULL)
    {
      return NULL;
    }
  struct node *next = NULL;  //three pointer to track the node
  struct node *prev = NULL;
  struct node *curr = head;
  int count = 0;
  while (curr && count < k)
    {
      next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
      count++;
    }

  head->next = reverse (curr, k);  //recursively calling the reverse functions  
  return prev;
}

int main ()				//main function
{
  int k;
  node *head = NULL;

  int n = buildList (head);
  cout << "Linked list data: ";
  printList (head);
  cout << "\nEnter the group size: ";
  cin >> k;
  head = reverse (head, k);
  cout << "\nAfter reversing linked list in groups of given size\n";
  cout << "Linked list data: ";
  printList (head);		//printing new linked list.
}