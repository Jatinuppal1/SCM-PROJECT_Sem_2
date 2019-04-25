#include<iostream>
#include<cstdio>
#include<cstdlib>
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
	void stmenu();
 };

void Stack::stmenu()
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

/*
 * Node Declaration
 * Doubly llist
 */
struct dnode
{
    int info;
    struct dnode *next;
    struct dnode *prev;
}*dstart;

/*
 * Node Declaration
 * Circular llist and Singly llist
 */
struct node
{
	int info;
	struct node *next;
} *sfirst, *slast, *clast;
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
	void cmenu();
	circular_llist()
		{
			clast = NULL;
		}
};

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
        void count();
        void reverse();
	void dmenu();
        double_llist()
        {
            dstart = NULL;
        }
};

void circular_llist::create_node(int value)
{
    struct node *temp;
    temp = new(struct node);
    temp->info = value;
    if (clast == NULL)
    {
        clast = temp;
        temp->next = clast;
    }
    else
    {
        temp->next = clast->next;
        clast->next = temp;
        clast = temp;
    }

void circular_llist::add_begin(int value)
{
    if (clast == NULL)
    {
	    cout << "First Create the list." << endl;
	    return;
    }
    struct node *temp;
    temp = new(struct node);
    temp->info = value;
    temp->next = clast->next;
    clast->next = temp;
}

/*
 * Create Double Link List
 */
void double_llist::create_list(int value)
{
    struct dnode *s, *temp;
    temp = new(struct dnode); 
    temp->info = value;
    temp->next = NULL;
    if (dstart == NULL)
    {
        temp->prev = NULL;
        dstart = temp;
    }
    else
    {
        s = dstart;
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
    if (dstart == NULL)

    {
        cout<<"First Create the list."<<endl;
        return;
    }
    struct dnode *temp;
    temp = new(struct dnode);
    temp->prev = NULL;
    temp->info = value;
    temp->next = dstart;
    dstart->prev = temp;
    dstart = temp;
    cout << "Element Inserted" << endl;
}

void circular_llist::add_after(int value, int pos)
{
    if (clast == NULL)
    {
	    cout << "First Create the list." << endl;
	    return;
    }
    struct node *temp, *s;
    s = clast->next;
    for (int i = 0; i < pos-1; i++)
    {
	    s = s->next;
	    if(s == clast->next)
	    {
		    cout << "There are less than";
		    cout << pos << " in the list" << endl;
		    return;
	    }
    }
    temp = new(struct node);
    temp->next = s->next;
    temp->info = value;
    s->next = temp;
    /*Elements inserted at the end*/
    if (s == last)
    {
	    clast = temp;
    }
}
 
/*
 * Insertion of element at a particular position
 */
void double_llist::add_after(int value, int pos)
{
    if (dstart == NULL)

    {
        cout<<"First Create the list."<<endl;
        return;
    }

    struct dnode *tmp, *q;
    q = dstart;
    for (int i = 0;i < pos-1;i++)
    {
        q = q->next;
        if (q == NULL )
        {
            cout<<"There are less than ";
            cout<<pos<<" elements."<<endl;
            return;
        }
    }
    tmp = new(struct dnode);
    tmp->info = value;
    if (q->next == NULL )
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
    cout << "Element Inserted" << endl;
}

void circular_llist::delete_element(int value)
{
    struct node *temp, *s;
    s = clast->next;
      /* If List has only one element*/
    if (clast->next == clast && clast->info == value)  
    {
        temp = last;
        clast = NULL;
        free(temp);
        return;
    }
    if (s->info == value)  /*First Element Deletion*/
    {
        temp = s;
        clast->next = s->next;
        free(temp);
        return;
    }
    while (s->next != clast)
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
    s = clast->next;
    while (s != clast)
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
    if (clast == NULL)
    {
        cout<<"List is empty, nothing to display"<<endl;
        return;
    }
    s = clast->next;
    cout<<"Circular Link List: "<<endl;
    while (s != clast)
    {
        cout<<s->info<<"->";
        s = s->next;
    }
    cout<<s->info<<endl;
}

void circular_llist::update()
{
    int value, pos, i;
    if (clast == NULL)
    {
        cout<<"List is empty, nothing to update"<<endl;
        return;
    }
    cout<<"Enter the node position to be updated: ";
    cin>>pos;
    cout<<"Enter the new value: ";
    cin>>value;
    struct node *s;
    s = clast->next;
    for (i = 0;i < pos - 1;i++)
    {
        if (s == clast)
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
    if (clast == NULL)
    {
        cout<<"List is empty, nothing to sort"<<endl;
        return;
    }
    s = clast->next;
    while (s != clast)
    {
        ptr = s->next;
        while (ptr != clast->next)
        {
            if (ptr != clast->next)
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

/*
 * Menu of Circular llist
 */
void circular_llist::cmenu()
{
    int choice, element, position;

        cout<<endl<<"---------------------------"<<endl;
        cout<<endl<<"Circular singly linked list"<<endl;
        cout<<endl<<"---------------------------"<<endl;     
        
    while (1)
    {
	cout<<"1.Create Node"<<endl;
        cout<<"2.Add at beginning"<<endl;
        cout<<"3.Add after"<<endl;
        cout<<"4.Delete"<<endl;
        cout<<"5.Search"<<endl;
        cout<<"6.Display"<<endl;
        cout<<"7.Update"<<endl;
        cout<<"8.Sort"<<endl;
        cout<<"9.Quit"<<endl;
        cout<<"Enter your choice : ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            cout<<"Enter the element: ";
            cin>>element;
            create_node(element);
            cout<<endl;
            break;
        case 2:
            cout<<"Enter the element: ";
            cin>>element;
            add_begin(element);
            cout<<endl;
            break;
        case 3:
            cout<<"Enter the element: ";
            cin>>element;
            cout<<"Insert element after position: ";
            cin>>position;
            add_after(element, position);
            cout<<endl;
            break;
        case 4:
            if (clast == NULL)
            {
                cout<<"List is empty, nothing to delete"<<endl;
                break;
            }
            cout<<"Enter the element for deletion: ";
            cin>>element;
            delete_element(element);
            cout<<endl;
            break;
        case 5:
            if (clast == NULL)
            {
                cout<<"List Empty!! Can't search"<<endl;
                break;
            }
            cout<<"Enter the element to be searched: ";
            cin>>element;
            search_element(element);
            cout<<endl;
            break;
        case 6:
            display_list();
            break;
        case 7:
            update();
            break;
        case 8:
            sort();
            break;                      
        case 9:
            return;
        default:
            cout<<"Wrong choice"<<endl;
        }
    }
 
}

/*
 * Deletion of element from the list
 */
void double_llist::delete_element(int value)
{
    struct dnode *tmp, *q;
     /*first element deletion*/
    if (dstart->info == value)
    {
        tmp = dstart;
        dstart = dstart->next;
        dstart->prev = NULL;
        cout<<"Element Deleted"<<endl;
        free(tmp);
        return;
    }
    q = dstart;
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
    struct dnode *q;
    if (dstart == NULL)
    {
        cout<<"List empty,nothing to display"<<endl;
        return;
    }
    q = dstart;
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
    struct dnode *q = dstart;
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
    struct dnode *p1, *p2;
    p1 = dstart;
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
    dstart = p1;
    cout<<"List Reversed"<<endl;
}

/*
 * Menu of Doubly llist
 */
void double_llist::dmenu()
{
    int choice, element, position;

        cout<<endl<<"----------------------------"<<endl;
        cout<<endl<<"Operations on Doubly linked list"<<endl;
        cout<<endl<<"----------------------------"<<endl;
        
    while( 1 )
     {  
	cout<<"1.Create Node"<<endl;
        cout<<"2.Add at begining"<<endl;
        cout<<"3.Add after position"<<endl;
        cout<<"4.Delete"<<endl;
        cout<<"5.Display"<<endl;
        cout<<"6.Count"<<endl;
        cout<<"7.Reverse"<<endl;
        cout<<"8.Quit"<<endl;
        cout<<"Enter your choice : ";
        cin>>choice;
        switch ( choice )
        {
        case 1:
            cout<<"Enter the element: ";
            cin>>element;
            create_list(element);
            cout<<endl;
            break;
        case 2:
            cout<<"Enter the element: ";
            cin>>element;
            add_begin(element);
            cout<<endl;
            break;
        case 3:
            cout<<"Enter the element: ";
            cin>>element;
            cout<<"Insert Element after postion: ";
            cin>>position;
            add_after(element, position);
            cout<<endl;
            break;
        case 4:
            if (dstart == NULL)
            {
                cout<<"List empty,nothing to delete"<<endl;
                break;
            }
            cout<<"Enter the element for deletion: ";
            cin>>element;
            delete_element(element);
            cout<<endl;
            break;
        case 5:
            display_dlist();
            cout<<endl;
            break;
        case 6:
            count();
            break;
        case 7:
            if (dstart == NULL)
            {
                cout<<"List empty,nothing to reverse"<<endl;
                break;
            }
            reverse();
            cout<<endl;
            break;
        case 8:
            return;
        default:
            cout<<"Wrong choice"<<endl;
        }
    }
}
/***********************end of doubly link list*****************/

class List
{
   public:
    List()
    {
        sfirst=NULL;
        slast=NULL;
    }
    void create();
    void insert();
    void delet();
    void display();
    void search();
    void smenu();
};

int main()
 {
	int n ;
	cout << "This program can implement following structures :" ;
	do 
	 {
	     cout << "\n1. Stack ( of integers )" ;      // in beginning only stack added but later more options will be added.
	     cout << "\n2. Singly Linked list" ;
	     cout << "\n3. Doubly Linked list" ;
	     cout << "\n4. Cicular Linked list" ;
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
				     s1.stmenu() ;
				   }
				 break;
			   case 2 :
				 {
			             List l ;
				     l.smenu();
				 }
				 break ;
			   case 3 :
				   {
			             double_llist dl ;
				     dl.dmenu() ;
				   }
				 break ;
			   case 4 :
				   {
			             circular_llist cl ;
				     cl.cmenu() ;
				   }
                                 break ;
		           default :
		   	           cout << "\nInvalid Input" ;
	           }

	} while( 1 ) ;

 }

void List::create()
{
    struct node *temp;
    temp = new(struct node);
    int n;
    cout << "\nEnter an Element:";
    cin >> n;
    temp->info = n;
    temp->next = NULL;
    if(sfirst == NULL)
    {
        sfirst = temp;
        slast = sfirst;
    }

    else
    {
        slast->next = temp;
        slast = temp;
    }
}

void List::insert()
{
    struct node *prev,*cur;
    prev = NULL;
    cur = sfirst;
    int count = 1,pos,ch,n;
    struct node *temp = new(struct node);
    cout << "\nEnter an Element:";
    cin >> n;
    temp->info = n;
    temp->next = NULL;
    cout << "\nINSERT AS\n1:FIRSTNODE\n2:LASTNODE\n3:IN BETWEEN FIRST&LAST NODES";
    cout << "\nEnter Your Choice:";
    cin >> ch;
    switch(ch)
    {
    case 1:
        temp->next = sfirst;
        sfirst = temp;
        break;
    case 2:
        slast->next = temp;
        slast = temp;
        break;
    case 3:
        cout << "\nEnter the Position to Insert:";
        cin >> pos;
        while(count != pos)
        {
            prev = cur;
            cur = cur->next;
            count++;
        }
        if(count == pos)
        {
            prev->next = temp;
            temp->next = cur;
        }
        else
            cout << "\nNot Able to Insert";
        break;
     default :
	 cout << "\nInvalid Input";

    }

}

void List::delet()
{
    struct node *prev = NULL,*cur = sfirst;
    int count = 1,pos,ch;
    cout << "\nDELETE\n1:FIRSTNODE\n2:LASTNODE\n3:IN BETWEEN FIRST&LAST NODES";
    cout << "\nEnter Your Choice:";
    cin >> ch;
    switch(ch)
    {
    case 1:
        if(sfirst != NULL)
        {
            cout << "\nDeleted Element is " << sfirst->info;
            sfirst = sfirst->next;
	    free(cur);
        }
        else
            cout << "\nNot Able to Delete";
        break;
    case 2:
        while(cur != slast)
        {
            prev = cur;
            cur = cur->next;
        }
        if(cur == slast)
        {
            cout << "\nDeleted Element is: " << cur->info;
            prev->next = NULL;
            slast = prev;
	    free(cur);
        }
        else
            cout << "\nNot Able to Delete";
        break;
    case 3:
        cout << "\nEnter the Position of Deletion:";
        cin >> pos;
        while(count != pos)
        {
            prev = cur;
            cur = cur->next;
            count++;
        }
        if(count == pos)
        {
            cout << "\nDeleted Element is: " << cur->info;
            prev->next = cur->next;
	    free(cur);
        }
        else
            cout << "\nNot Able to Delete";
        break;
   default :
	 cout << "\nInvalid Input";
    }
}

void List::display()
{
    struct node *temp = sfirst;
    if(temp == NULL)
    {
        cout << "\nList is Empty";
    }
    while(temp != NULL)
    {
        cout << temp->info;
        cout << "-->";
        temp = temp->next;
    }
    cout << "NULL";
}

void List::search()
{
    int value,pos = 0;
    bool flag = false;
    if(sfirst == NULL)
    {
        cout << "List is Empty";
        return;
    }
    cout << "Enter the Value to be Searched:";
    cin >> value;
    struct node *temp;
    temp = sfirst;
    while(temp != NULL)
    {
        pos++;
        if(temp->info == value)
        {
            flag = true;
            cout << "Element" << value << "is Found at " << pos << " Position";
            return;
        }
        temp = temp->next;
    }
    if(!flag)
    {
        cout << "Element " << value << " not Found in the List";
    }
}

void smenu()
{
    
    int ch;
    while(1)
    {
        cout<<"\n**** MENU ****";
        cout<<"\n1:CREATE\t2:INSERT\n3:DELETE\t4:SEARCH\n5:DISPLAY\t6:EXIT\n";
        cout<<"\nEnter Your Choice:";
        cin>>ch;
        switch(ch)
        {
        case 1:
            create();
            break;
        case 2:
            insert();
            break;
        case 3:
            delet();
            break;
        case 4:
            search();
            break;
        case 5:
            display();
            break;
        case 6:
            return;
	default :
	    cout << "\nInvalid Input";
        }
    }

}
