#include<iostream>
using namespace std;
int max(int x, int y)
{
	if(x>y)
	return x;
	else 
	return y;
}

struct Avlnode
{
	int data;
	Avlnode *left;
	Avlnode *right;
	int height;
};

typedef Avlnode node;

struct avltree
{
    	Avlnode *root;
		avltree()
		{
			root = NULL;
		}
		node* insert(Avlnode *r, int data);
		void display(Avlnode *r);
		~avltree()
		{
			delete root;
		}
		private:
		Avlnode* LLrotation(Avlnode *x);
		Avlnode* RRrotation(Avlnode *x);
		Avlnode* LRrotation(Avlnode *z);
		Avlnode* RLrotation(Avlnode *z);
		int hight(node *r);
};

int avltree::hight(node *r)
{
	if(r==NULL)
	return -1;
	else
	 return r->height;
}

Avlnode* avltree::LLrotation(Avlnode *x)
{
	node* w;
	w = x->left;
	x->left = w->right;
	w->right = x;
	x->height = max( hight(x->left), hight(x->right) ) + 1;
	w->height = max( hight(w->left), hight(w->right) ) + 1;
	return w;
}

node*  avltree::RRrotation(node *x)
{
	node *w;
	w = x->right;
	x->right = w->left;
	w->left = x;
	x->height = max( hight(x->left), hight(x->right) ) + 1;
	w->height = max( hight(w->left), hight(w->right) ) + 1;
	return w;
}

node* avltree::LRrotation(node *z)
{
	z->left = RRrotation(z->left);
	return LLrotation(z);
}

node* avltree::RLrotation(node *z)
{
	z->right = LLrotation(z->right);
	return RRrotation(z);
}

node* avltree::insert(node *r, int data)
{
	if(r==NULL)
	{
		r = new node;
		r->data = data;
		r->height= 0;
		r->left = NULL;
		r->right = NULL;
	}
 else if(data<r->data)
 {
 	r->left = insert(r->left, data);
 	if(hight(r->left) - hight(r->right) == 2)
 	{
 		if(data<r->left->data)
 		r = LLrotation(r);
 		else
 		r = LRrotation(r);
	}
 }
 else if(data>r->data)
 {
 	r->right = insert(r->right, data);
 	if(hight(r->right) - hight(r->left)==2)
 	{
 		if(data>r->right->data)
 	        r = RRrotation(r);
 	    else
 	       r = RLrotation(r);
 	}
 }
 r->height = max(hight(r->left), hight(r->right)) + 1;
 return r;
}

void avltree::display(node *r)
{
	if(r==NULL)
	return;
	else
	{
		display(r->left);
		cout<<r->data<<" ";
		display(r->right);
	}
}

int main()
{
	avltree T;
	T.root = T.insert(T.root, 2);
	T.root = T.insert(T.root, 4);
	T.root = T.insert(T.root, 7);
	T.root = T.insert(T.root, 6);
	T.root = T.insert(T.root, 5);
	T.root = T.insert(T.root, 8);
	T.display(T.root);
}
