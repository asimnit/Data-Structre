#include<iostream>
using namespace std;
struct listnode
{
	int data;
	int key;
	listnode *next;
};

class hashtable
{
	int size;
	int count;
	listnode* *keys;
	int h(int x) //hashfunction
	{
		return x%9;
	}
	public:
		hashtable()
		{
			count = 0;
			cout<<"Enter the size of the hash table:";
			cin>>size;
			keys = new listnode* [size];
			int i;
			for(i=0; i<size; i++)
			{
				keys[i] = NULL;
			}
		}
		bool search(int x);
		void insert(int x);
		void Delete(int x);
		~hashtable()
		{
			delete[] keys;
		}
};

bool hashtable::search(int x)
{
	int index;
	index = h(x);
	listnode *temp;
	temp = keys[index];
	if(temp==NULL)
	{
	   cout<<endl<<"the element is not present"<<endl;
		return false;
	}
 else
 {
	while(temp->data!=x && temp->next!=NULL)
	{
		temp = temp->next;
	}
	if(temp->data == x)
	{
	  cout<<endl<<"the element is present"<<endl;
	  return true;
    }
	else
	{
		cout<<endl<<"the element is not present"<<endl;
		return false;
    }
}
}

void hashtable::insert(int x)
{
	int index;
	index = h(x);
	listnode *temp;
	temp = keys[index];
	if(temp == NULL)
	{
		temp = new listnode;
		temp->data = x;
		temp->key = index;
		temp->next = NULL;
		keys[index] = temp;
	}
	else
	{
		while(temp->next!=NULL)
		{
			temp = temp->next;
		}
		listnode *ptr;
		ptr = new listnode;
		ptr->data = x;
		ptr->key = index;
		ptr->next = NULL;
		temp->next = ptr;
	}
	count++;
}

void hashtable::Delete(int x)
{
	int index;
	index = h(x);
	listnode *temp, *prev;
	temp = keys[index];
	while(temp->next!=NULL && temp->data!=x)
	{
	    prev = temp;
		temp = temp->next;	
	}
	if(temp == keys[index])
	{
		keys[index] = temp->next;
		delete temp;
	}
	else
	{
		prev->next = temp->next;
		delete temp;
	}
	count--;
}

int main()
{
	hashtable H;
	int t=1;
	while(t)
	{
		cout<<"Enter your choice: 1:insert, 2:search, 3:delete"<<endl;
		int choice;
		cin>>choice;
		switch(choice)
		{
			case 1:
				{
					cout<<"Enter the element to be inserted:"<<endl;
					int e;
					cin>>e;
					H.insert(e);
				}
				break;
			case 2:
				{
					cout<<"Enter the element to be searched:"<<endl;
					int e;
					cin>>e;
					H.search(e);
				}
				break;
			case 3:
				{
					cout<<"Enter the element to be deleted:"<<endl;
					int e;
					cin>>e;
					H.Delete(e);
				}
				break;
		}
		cout<<"\n"<<"insert 1 to continue 0 to stop: ";
		cin>>t;
	}
	return 0;
}
