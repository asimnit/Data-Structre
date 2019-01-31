#include<iostream>
#include<deque>
using namespace std;
class node
{
	public:
		int data;
		int hd;//horizontal distance
		node *left;
		node *right;
};

class Btree
{
	public:
		node *root;
		Btree()
		{
			root = NULL;
		}
		node* getnode(int x);
		void insert(int x);
		void display(node *r);
		void display_hd(node *r);
		void deletetree(node *r);
		void det_hd(node *r);
		int size(node *r);
		int max();
		int min();
		int sum(node *r);
		~Btree()
		{
			deletetree(root);
		}
};

node* Btree::getnode(int x)
{
	node *n;
	n = new node;
	n->data = x;
	n->left = NULL;
	n->right = NULL;
	return n;
}

void Btree::insert(int x)
{
	if(root==NULL)
	{
	   node *m;
	   m = getnode(x);
	   root = m;
	   root->hd = 0;
	   return;	
	}
		node *temp;
		deque<node*> q;
		q.push_back(root);
		while( !q.empty() )
	  {
		   temp = q.front();
		   q.pop_front();
		   if(temp->left==NULL)
		   {
		   	  temp->left = getnode(x);
		   	  return;
		   }
		   else
		   {
		   	  q.push_back(temp->left);
		   }
		   if(temp->right==NULL)
		   {
		   	  temp->right = getnode(x);
		   	  return;
		   }
		   else
		   {
		   	  q.push_back(temp->right);
		   }		
	   }
}

void Btree::display(node *r)
{
	if(r)
	{
	  cout<<r->data<<' ';
	  display(r->left);
	  display(r->right);
   }
}

void Btree::display_hd(node *r)
{
	if(r)
	{
	  cout<<r->hd<<' ';
	  display_hd(r->left);
	  display_hd(r->right);
   }
}

void Btree::deletetree(node *r)
{
  	if(r==NULL)
	{
		return;
	}
	else
	{
	  deletetree(r->left);
	  deletetree(r->right);
	  delete r;
    }
}

int Btree::size(node *r)
{
	if(r==NULL)
	{
		return 0;
	}
	else
	{
		return( size(r->left) + 1 + size(r->right) );
	}
}

int Btree::max()
{
	if(root==NULL)
	{
		cout<<"There is no element.";
		return 0;
	}
	else
	{
		deque<node*> q;
		node *temp;
		int max = root->data;
		q.push_back(root);
		while( !q.empty() )
		{
			temp = q.front();
			q.pop_front();
			if(max<temp->data)
			 max = temp->data;
			if(temp->left)
			  q.push_back(temp->left);
			if(temp->right)
			  q.push_back(temp->right);
		}
		return max;
	}
}

int Btree::min()
{
		if(root==NULL)
	{
		cout<<"There is no element.";
		return 0;
	}
	else
	{
		deque<node*> q;
		node *temp;
		int min = root->data;
		q.push_back(root);
		while( !q.empty() )
		{
			temp = q.front();
			q.pop_front();
			if(min>temp->data)
			 min = temp->data;
			if(temp->left)
			  q.push_back(temp->left);
			if(temp->right)
			  q.push_back(temp->right);
		}
		return min;
	}
}

int Btree::sum(node *r)
{
	if(r==NULL)
	{
		return 0;
	}
	else
	{
		return( r->data + sum(r->left) + sum(r->right) ); 
	}
}

void Btree::det_hd(node *r)
{
	node *p = r;
	if(p->left)
	{
		node *l = p->left;
		l->hd = p->hd -1;
		det_hd(l);
	}
	if(p->right)
	{
		node *r = p->right;
		r->hd = p->hd - 1;
		det_hd(r);
	}
}

int main()
{
	Btree T;
	T.insert(5);
	T.insert(6);
	T.insert(10);
	T.insert(17);
	T.insert(1);
	T.insert(12);
	T.insert(51);
	T.insert(100);
	T.display(T.root);
	cout<<endl<<"The horizontal distance of every node is:"<<endl;
    T.det_hd(T.root);
    T.display_hd(T.root);
	cout<<endl<<"Size= "<<T.size(T.root);
	cout<<endl<<"Maximum= "<<T.max();
	cout<<endl<<"Minimum= "<<T.min();
	cout<<endl<<"Sum= "<<T.sum(T.root);
	return 0;
}
