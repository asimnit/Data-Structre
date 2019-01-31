#include<iostream>
using namespace std;
class node{
	public:
		int data;
		node *next;
};

class sll{
	
	node *head;
	public:
		sll()
		{
			head = NULL;
		}
       	void insert_first(int x);
	    void insert_last(int x);
		void insert_any(int x, int y);
		void delete_first();
		void delete_last();
		void delete_any( int y);
		void display();
		node* get_node(int x);
		~sll()
		{
			delete head;
		}
};

node* sll::get_node(int x)
{
	node* n;
	n = new node;
	n->data = x;
	n->next = NULL;
	return n;
}
void sll::insert_first(int x)
{
	if(head==NULL)
	{
		node *n;
		n = get_node(x);
		head = n;
	}
	else
	{
		node *n;
		n = get_node(x);
		n->next = head;
		head = n;
	}
}

void sll::insert_last(int x)
{
	if(head==NULL)
	{
		node *n;
		n = get_node(x);
		head = n;
	}
	else
	{
		node *n;
		n = get_node(x);
		node *temp;
        temp = head;
        while(temp->next!=NULL)
        {
        	temp = temp->next;
		}
		temp->next = n;
	}
}

void sll::insert_any(int x, int y)
{
	if(head==NULL)
	{
		node *n;
		n = get_node(x);
		head = n;
	}
	else
	{
		int i;
		node *temp, *ptr, *n;
		temp = head;
		n= get_node(x);
		for(i=0; i<(y-1); i++)
		{
			ptr= temp;
			temp = temp->next;
		}
		ptr->next = n;
		n->next = temp;
	}
}

void sll::delete_first()
{
	if(head == NULL)
	{
		cout<<"there is no element to delete"<<endl;
	}
	else
	{
		node *temp;
		temp = head;
		head = head->next;
		delete temp;
    }
}

void sll::delete_last()
{
    if(head == NULL)
	{
		cout<<"there is no element to delete"<<endl;
	}
	else
	{
		node *temp, *ptr;
		temp = head;
		while(temp->next!=NULL)
		{
			ptr = temp;
			temp= temp->next;
		}
		delete temp;
		ptr->next = NULL;
	}	
}

void sll::delete_any( int y)
{
     if(head == NULL)
	{
		cout<<"there is no element to delete"<<endl;
	}	
     else
	{
		int i;
		node *temp, *ptr, *n;
		temp = head;
		for(i=0; i<(y-1); i++)
		{
			ptr= temp;
			temp = temp->next;
		}
		ptr->next = temp->next;
		delete temp;
	}
}

void sll::display()
{
	if(head==NULL)
	{
		cout<<"there is no element in the link list"<<endl;
	}
	else
	{
	    node *temp;
	    temp = head;
	   while(temp!= NULL)
	  {
		  cout<<temp->data<<endl;
		  temp= temp->next;
	  }
    }
}

int main()
{
	sll list;
	int count = 1;
	while(count)
	{
		cout<<"enter your choice: 1:insert_first, 2:insert_last, 3: insert_any, 4:delete_first, 5:delete_last, 6:delete_any, 7: display"<<endl;
	    int choice;
	    cin>>choice;
		switch(choice)
		{
			case 1:
				{
					cout<<"enter the element to be inserted"<<endl;
					int n;
					cin>>n;
					list.insert_first(n);
				}
				break;
			case 2:
				{
					
					cout<<"enter the element to be inserted"<<endl;
					int n;
					cin>>n;
					list.insert_last(n);
				}
				break;
			case 3:
				{
					
					cout<<"enter the element and position to be inserted"<<endl;
					int n, m;
					cin>>n>>m;
					list.insert_any(n, m);
				}
				break;
			case 4:
				{
					list.delete_first();
				}
				break;
			case 5:
				{
					list.delete_last();
				}
				break;
			case 6:
				{
					cout<<"enter the position to be deleted"<<endl;
					int n;
					cin>>n;
					list.delete_any(n);
				}
				break;
			case 7:
				{
				   	cout<<"the list element are"<<endl;
				   	list.display();
				}
				break;
		}
		cout<<"enter 0 to terminate and 1 to continue: "<<endl;
		cin>>count;
	}
	return 0;
}
