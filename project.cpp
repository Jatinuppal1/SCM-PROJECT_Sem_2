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
struct node
{
    int info;
    struct node *next;
}*last;

class circular_llist
{
    public:
        void create_node(int value);
        void add_begin(int value);
        void add_after(int value, int position);
        void delete_element(int value);
        void search_element(int value);
        void display_list();
        void update();
        void sort();
        circular_llist()
        {
            last = NULL;
        }
};

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
