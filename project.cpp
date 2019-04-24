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

void circular_llist::create_node(int value)
{
    struct node *temp;
    temp = new(struct node);
    temp->info = value;
    if (last == NULL)
    {
        last = temp;
        temp->next = last;
    }
    else
    {
        temp->next = last->next;
        last->next = temp;
        last = temp;
    }

    void circular_llist::add_begin(int value)
{
    if (last == NULL)
    {
        cout<<"First Create the list."<<endl;
        return;
    }
    struct node *temp;
    temp = new(struct node);
    temp->info = value;
    temp->next = last->next;
    last->next = temp;
}

void circular_llist::add_after(int value, int pos)
{
    if (last == NULL)
    {
        cout<<"First Create the list."<<endl;
        return;
    }
    struct node *temp, *s;
    s = last->next;
    for (int i = 0;i < pos-1;i++)
    {
        s = s->next;
        if (s == last->next)
        {
            cout<<"There are less than ";
            cout<<pos<<" in the list"<<endl;
            return;
        }
    }
    temp = new(struct node);
    temp->next = s->next;
    temp->info = value;
    s->next = temp;
    /*Element inserted at the end*/
    if (s == last)
    {
        last=temp;
    }
}

void circular_llist::delete_element(int value)
{
    struct node *temp, *s;
    s = last->next;
      /* If List has only one element*/
    if (last->next == last && last->info == value)  
    {
        temp = last;
        last = NULL;
        free(temp);
        return;
    }
    if (s->info == value)  /*First Element Deletion*/
    {
        temp = s;
        last->next = s->next;
        free(temp);
        return;
    }
    while (s->next != last)
    {
        /*Deletion of Element in between*/
        if (s->next->info == value)    
        {
            temp = s->next;
            s->next = temp->next;
            free(temp);
            cout<<"Element "<<value;
            cout<<" deleted from the list"<<endl;
            return;
        }
        s = s->next;
    }
    /*Deletion of last element*/
    if (s->next->info == value)    
    {
        temp = s->next;
        s->next = last->next;
        free(temp);		
        last = s;
        return;
    }
    cout<<"Element "<<value<<" not found in the list"<<endl;
}

void circular_llist::search_element(int value)
{
    struct node *s;
    int counter = 0;
    s = last->next;
    while (s != last)
    {
        counter++;
        if (s->info == value)
        {
            cout<<"Element "<<value;
            cout<<" found at position "<<counter<<endl;
            return;
        }
        s = s->next;
    }
    if (s->info == value)
    {
        counter++;
        cout<<"Element "<<value;
        cout<<" found at position "<<counter<<endl;
        return;
    }
    cout<<"Element "<<value<<" not found in the list"<<endl;
}

void circular_llist::display_list()
{
    struct node *s;
    if (last == NULL)
    {
        cout<<"List is empty, nothing to display"<<endl;
        return;
    }
    s = last->next;
    cout<<"Circular Link List: "<<endl;
    while (s != last)
    {
        cout<<s->info<<"->";
        s = s->next;
    }
    cout<<s->info<<endl;
}

void circular_llist::update()
{
    int value, pos, i;
    if (last == NULL)
    {
        cout<<"List is empty, nothing to update"<<endl;
        return;
    }
    cout<<"Enter the node position to be updated: ";
    cin>>pos;
    cout<<"Enter the new value: ";
    cin>>value;
    struct node *s;
    s = last->next;
    for (i = 0;i < pos - 1;i++)
    {
        if (s == last)
        {
            cout<<"There are less than "<<pos<<" elements.";
            cout<<endl;
            return;
        }
        s = s->next;
    }
    s->info = value;
    cout<<"Node Updated"<<endl;
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
