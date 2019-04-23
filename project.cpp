#include<iostream>
using namespace std;

class Stack
 {
	int top;
	int size;
	int *stack;

      public:
	Stack();
	void push( int );
	void pop();
	void display();
	void menu();
 };

void Stack::menu()
 {
	 int k,a ;
	 cout << "\n What do you want to do :" ;
	 do
	   {
	         cout << "\n1. Push" ;
		 cout << "\n2. Pop" ;
	         cout << "\n Press 0 to leave." ;
		 cout << endl <<"\nYour choice - " ;
		 cin >> k ;
		 switch( k )
		       {
			       case 0 :
				       cout << "\nOut of Stack" << endl ;
				    break ;
			       case 1 :
				       cout << endl << "\nEnter the value - " ;
				       cin >> a ;
				       push( a ) ;
				    break ;
			       case 2 :
				       pop() ;
				    break ;
			       case 3 :
				       display() ;
				    break ;
			       default :
				    cout << "\nInvalid Input" ;
		       }
	   
	   }  while( k ) ;
 }

 Stack::Stack()
  {
	  top = -1 ;
	  cout << endl << "\nEnter size of stack - " ;
	  cin >> size ;
	  stack  = new int[ size ] ;
  }

void Stack::push( int data )
 {
	 if( top == size-1 )
		 cout << "\nStack Overflow !" ;
	 else
	  {
		 stack[ ++top ] = data ;
		 cout << endl << stack[ top ] <<" added to the stack." ;
	  }
 }

void Stack::pop()
 {
	 if( top == -1 )
		 cout << "\nStack Underflow !" ;
	 else
	  {
		 cout << endl << stack[ top-- ] << " deleted from the stack." ;
	  }
 }

void Stack::display()
 {
	 if( top == -1 )
		 cout << "\nStack is empty.";
	 else
	 {
	         cout << "\nElements of Stack ( from bottom to top ) are :" << endl;
	         for( int i=0 ; i<=top ; i++ )
		         cout << "\t" << stack[i] ;
	 }
 }
/**********************Doubly linklist--Ingit**************************************/
/*
 Class Declaration
 */
class double_llist
{
    public:
        void create_list(int value);
        void add_begin(int value);
        void add_after(int value, int position);
        void delete_element(int value);
        void search_element(int value);
        void display_dlist();
        void count();
        void reverse();
        double_llist()
        {
            start = NULL;
        }
};

/*
 * Create Double Link List
 */
void double_llist::create_list(int value)
{
    struct node *s, *temp;
    temp = new(struct node); 
    temp->info = value;
    temp->next = NULL;
    if (start == NULL)
    {
        temp->prev = NULL;
        start = temp;
    }
    else
    {
        s = start;
        while (s->next != NULL)
            s = s->next;
        s->next = temp;
        temp->prev = s;
    }
}
 
/*
 * Insertion at the beginning
 */
void double_llist::add_begin(int value)
{
    if (start == NULL)
    {
        cout<<"First Create the list."<<endl;
        return;
    }
    struct node *temp;
    temp = new(struct node);
    temp->prev = NULL;
    temp->info = value;
    temp->next = start;
    start->prev = temp;
    start = temp;
    cout<<"Element Inserted"<<endl;
}
 
/*
 * Insertion of element at a particular position
 */
void double_llist::add_after(int value, int pos)
{
    if (start == NULL)
    {
        cout<<"First Create the list."<<endl;
        return;
    }
    struct node *tmp, *q;
    int i;
    q = start;
    for (i = 0;i < pos - 1;i++)
    {
        q = q->next;
        if (q == NULL)
        {
            cout<<"There are less than ";
            cout<<pos<<" elements."<<endl;
            return;
        }
    }
    tmp = new(struct node);
    tmp->info = value;
    if (q->next == NULL)
    {
        q->next = tmp;
        tmp->next = NULL;
        tmp->prev = q;      
    }
    else
    {
        tmp->next = q->next;
        tmp->next->prev = tmp;
        q->next = tmp;
        tmp->prev = q;
    }
    cout<<"Element Inserted"<<endl;
}

/*
 * Deletion of element from the list
 */
void double_llist::delete_element(int value)
{
    struct node *tmp, *q;
     /*first element deletion*/
    if (start->info == value)
    {
        tmp = start;
        start = start->next;
        start->prev = NULL;
        cout<<"Element Deleted"<<endl;
        free(tmp);
        return;
    }
    q = start;
    while (q->next->next != NULL)
    {
        /*Element deleted in between*/
        if (q->next->info == value)
        {
            tmp = q->next;
            q->next = tmp->next;
            tmp->next->prev = q;
            cout<<"Element Deleted"<<endl;
            free(tmp);
            return;
        }
        q = q->next;
    }
     /*last element deleted*/
    if (q->next->info == value)
    {
        tmp = q->next;
        free(tmp);
        q->next = NULL;
        cout<<"Element Deleted"<<endl;
        return;
    }
    cout<<"Element "<<value<<" not found"<<endl;
}

/*
 * Display elements of Doubly Link List
 */
void double_llist::display_dlist()
{
    struct node *q;
    if (start == NULL)
    {
        cout<<"List empty,nothing to display"<<endl;
        return;
    }
    q = start;
    cout<<"The Doubly Link List is :"<<endl;
    while (q != NULL)
    {
        cout<<q->info<<" <-> ";
        q = q->next;
    }
    cout<<"NULL"<<endl;
}


int main()
 {
	int n ;
	cout << "This program can implement following structures :" ;
	do 
	 {
	     cout << "\n1. Stack ( of integers )" ;      // in beginning only stack added but later more options will be added.
	     cout << "\n Press 0 for exit." ;
	     cout << endl << "\nEnter your choice - " ;
	     cin >> n ;
	     switch( n )
		   {
		   	   case 0 :
		   	           cout << "\nThank You for visiting our program." ;
		   	           exit(0) ;    // this infinite loop will terminate here.
		           case 1 :
				   {
		   	             Stack s1 ;
				     s1.menu() ;
				   }
                                 break ;
		           default :
		   	           cout << "\nInvalid Input" ;
	           }

	} while( 1 ) ;

 }
