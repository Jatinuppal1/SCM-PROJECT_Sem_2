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

    temp->info = value;
    temp->next = last->next;
    last->next = temp;
}

void circular_llist::add_after(int value, int pos)
{
    if (last == NULL)

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

void circular_llist::sort()
{
    struct node *s, *ptr;
    int temp;
    if (last == NULL)
    {
        cout<<"List is empty, nothing to sort"<<endl;
        return;
    }
    s = last->next;
    while (s != last)
    {
        ptr = s->next;
        while (ptr != last->next)
        {
            if (ptr != last->next)
            {
                if (s->info > ptr->info)
                {
                    temp = s->info;
                    s->info = ptr->info;
                    ptr->info = temp;
                }
            }
            else
            {
                break;
            }
            ptr = ptr->next;
        }
        s = s->next;
    }
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

/*
 * Number of elements in Doubly Link List
 */
void double_llist::count()
{
    struct node *q = start;
    int cnt = 0;
    while (q != NULL)
    {
        q = q->next;
        cnt++;
    }
    cout<<"Number of elements are: "<<cnt<<endl;
}

/*
 * Reverse Doubly Link List
 */
void double_llist::reverse()
{
    struct node *p1, *p2;
    p1 = start;
    p2 = p1->next;
    p1->next = NULL;
    p1->prev = p2;
    while (p2 != NULL)
    {
        p2->prev = p2->next;
        p2->next = p1;
        p1 = p2;
        p2 = p2->prev;
    }
    start = p1;
    cout<<"List Reversed"<<endl;
}
/***********************end of doubly link list*****************/


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

void List::create()
{
    Node *temp;
    temp=new Node;
    int n;
    cout<<"\nEnter an Element:";
    cin>>n;
    temp->info=n;
    temp->next=NULL;
    if(first==NULL)
    {
        first=temp;
        last=first;
    }

    else
    {
        last->next=temp;
        last=temp;
    }
}

void List::insert()
{
    Node *prev,*cur;
    prev=NULL;
    cur=first;
    int count=1,pos,ch,n;
    Node *temp=new Node;
    cout<<"\nEnter an Element:";
    cin>>n;
    temp->info=n;
    temp->next=NULL;
    cout<<"\nINSERT AS\n1:FIRSTNODE\n2:LASTNODE\n3:IN BETWEEN FIRST&LAST NODES";
    cout<<"\nEnter Your Choice:";
    cin>>ch;
    switch(ch)
    {
    case 1:
        temp->next=first;
        first=temp;
        break;
    case 2:
        last->next=temp;
        last=temp;
        break;
    case 3:
        cout<<"\nEnter the Position to Insert:";
        cin>>pos;
        while(count!=pos)
        {
            prev=cur;
            cur=cur->next;
            count++;
        }
        if(count==pos)
        {
            prev->next=temp;
            temp->next=cur;
        }
        else
            cout<<"\nNot Able to Insert";
        break;

    }

}

void List::delet()
{
    Node *prev=NULL,*cur=first;
    int count=1,pos,ch;
    cout<<"\nDELETE\n1:FIRSTNODE\n2:LASTNODE\n3:IN BETWEEN FIRST&LAST NODES";
    cout<<"\nEnter Your Choice:";
    cin>>ch;
    switch(ch)
    {
    case 1:
        if(first!=NULL)
        {
            cout<<"\nDeleted Element is "<<first->info;
            first=first->next;
        }
        else
            cout<<"\nNot Able to Delete";
        break;
    case 2:
        while(cur!=last)
        {
            prev=cur;
            cur=cur->next;
        }
        if(cur==last)
        {
            cout<<"\nDeleted Element is: "<<cur->info;
            prev->next=NULL;
            last=prev;
        }
        else
            cout<<"\nNot Able to Delete";
        break;
    case 3:
        cout<<"\nEnter the Position of Deletion:";
        cin>>pos;
        while(count!=pos)
        {
            prev=cur;
            cur=cur->next;
            count++;
        }
        if(count==pos)
        {
            cout<<"\nDeleted Element is: "<<cur->info;
            prev->next=cur->next;
        }
        else
            cout<<"\nNot Able to Delete";
        break;
    }
}

void List::display()
{
    Node *temp=first;
    if(temp==NULL)
    {
        cout<<"\nList is Empty";
    }
    while(temp!=NULL)
    {
        cout<<temp->info;
        cout<<"-->";
        temp=temp->next;
    }
    cout<<"NULL";
}

void List::search()
{
    int value,pos=0;
    bool flag=false;
    if(first==NULL)
    {
        cout<<"List is Empty";
        return;
    }
    cout<<"Enter the Value to be Searched:";
    cin>>value;
    Node *temp;
    temp=first;
    while(temp!=NULL)
    {
        pos++;
        if(temp->info==value)
        {
            flag=true;
            cout<<"Element"<<value<<"is Found at "<<pos<<" Position";
            return;
        }
        temp=temp->next;
    }
    if(!flag)
    {
        cout<<"Element "<<value<<" not Found in the List";
    }
}
