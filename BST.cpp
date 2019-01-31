#include<iostream>
#include<deque>
using namespace std;
struct node
{
		int data;
		node *left;
		node *right;
};

struct BST
{
		node *root;
		BST()
		{
			root = NULL;
		}
		node *getnode(int x);
		void insert(int x);
		void search(int x);
		int min();
		int max(node *r);
		node* pnode(int x);
		void deletetree(node *r);
		void display(node *r);
		void deletenode(int x);
		~BST()
		{
			deletetree(root);
		}
};

node* BST::getnode(int x)
{
	node *n;
	n = new node;
	n->data = x;
	n->left = NULL;
	n->right = NULL;
	return n;
}

void BST::insert(int x)
{
	node *r;
	r = root;
	if(r==NULL)
	{
		root = getnode(x);
		return;
	}
	 else
	 {
	 	node *m;
	 	while(r)
	 	{
	 	   if(x<r->data)
	 	   {
	 	   	  m = r;
	 	   	  r =r->left;
	 	   	  if(r==NULL)
	 	   	  {
	 	   	      r = getnode(x);
				  m->left = r;
				  return;	
			  }
		   }
		   else
		   {
		   	  m = r;
	 	   	  r =r->right;
	 	   	  if(r==NULL)
	 	   	  {
	 	   	      r = getnode(x);
				  m->right = r;
				  return;	
			  }
		   }
		}
	 }
}
void BST::display(node *r)
{
	if(r)
	{
	  display(r->left);
	  cout<<r->data<<' ';
	  display(r->right);
   }
}

void BST::deletetree(node *r)
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

void BST::search(int x)
{
	node *r;
	r = root;
	if(r==NULL)
	{
		cout<<"There is no element to search";
		return;
	}
	else
	{
		while(r)
		{
			if(x == r->data)
			{
				cout<<"\n"<<"The given element is present in the tree.";
				return;
			}
			else if(x< r->data)
			{
				r= r->left;
			}
			else
			{
				r = r->right;
			}
		}
		cout<<"\n"<<"The given element is not present in the tree";
	}
}

node* BST::pnode(int x)
{
	node *r, *n;
	r = root;
	while(r)
	{
			if(x == r->data)
			{
				return n;
			}
			else if(x< r->data)
			{
				n = r;
				r= r->left;
			}
			else
			{
				n =r;
				r = r->right;
			}
	}
}

void BST::deletenode(int x)
{
	if(root==NULL)
	{
		cout<<"There is no element to delete.";
		return;
	}
	else if(root->data==x)
	{
		if(root->right==NULL && root->left==NULL)
		{
			root = NULL;
			return;
		}
		if(root->right==NULL && root->left!=NULL)
		{
			node *r = root;
			root = root->left;
			delete r;
			return;
		}
		if(root->right!=NULL && root->left==NULL)
		{
			node *r = root;
			root= root->right;
			delete r;
			return;
		}
		if(root->right!=NULL && root->left!=NULL)
		{
			int y = max(root->left);
			deletenode(y);
			root->data= y;
			return;
		}
	}
	else
	{
		node *n, *l, *r;
		n= pnode(x);
		l = n->left;
		r= n->right;
		if(l!=NULL && l->data==x)
		{
			if(l->left==NULL && l->right==NULL)
			{
				delete l;
				n->left = NULL;
				return;
			}
			if(l->left==NULL && l->right!=NULL) 
			{
				n->left = l->right;
				delete l;
				return;
			}
			if(l->left!=NULL && l->right==NULL)
			{
				n->left = l->left;
				delete l;
				return;
			}
			if(l->left!=NULL && l->right!=NULL)
			{
				int y = max(l->left);
				deletenode(y);
				l->data = y;
				return;
			}
		}
		if(r!=NULL && r->data==x)
		{
			if(r->left==NULL && r->right==NULL)
			{
				delete r;
				n->right = NULL;
				return;
			}
			if(r->left==NULL && r->right!=NULL) 
			{
				n->right = r->right;
				delete r;
				return;
			}
			if(r->left!=NULL && r->right==NULL)
			{
				n->right = r->left;
				delete r;
				return;
			}
			if(r->left!=NULL && r->right!=NULL)
			{
				int y = max(r->left);
				deletenode(y);
				r->data = y;
				return;
			}
		}
		
	}
}

int BST::min()
{
	node *r;
	r = root;
	if(r==NULL)
	{
		cout<<"There is no element to search";
		return 0;
	}
	else
	{
		while(r->left)
		{
			r=r->left;
		}
		return (r->data);
	}
}

int BST::max(node *r)
{
	if(r==NULL)
	{
		cout<<"There is no element to search";
		return 0;
	}
	else
	{
		while(r->right)
		{
			r=r->right;
		}
		return (r->data);
	}
}

int main()
{
	BST T;
	T.insert(5);
	T.insert(4);
	T.insert(8);
	T.insert(1);
	T.insert(7);
	T.insert(9);
	T.insert(3);
	T.insert(6);
	T.insert(10);
	T.insert(0);
	T.insert(2);
	cout<<"The tree is: ";
	T.display(T.root);
	cout<<"\n"<<"The left subtree is: ";
	node *r = T.root;
	T.display(r->left);
	cout<<"\n"<<"The right subtree is: ";
	T.display(r->right);
	T.deletenode(5);
	T.deletenode(0);
	T.deletenode(1);
	T.deletenode(2);
	T.deletenode(3);
	T.deletenode(4);
	T.deletenode(6);
	T.deletenode(7);
	T.deletenode(8);
	T.deletenode(9);
	cout<<endl<<"After deleting:"<<endl;
	T.display(T.root);
	T.search(50);
	cout<<endl<<"Minimum value is:"<<T.min();
	cout<<endl<<"Maximum value is:"<<T.max(T.root);
	return 0;
}
