#include<bits/stdc++.h>
using namespace std;

struct Heap 
{
	vector<int> array;
	int count;
	int capacity;
	int heap_type;
	int getmax(Heap *h);
	int deletemax(Heap *h);
	void insert(Heap *h, int data);
	void destroy(Heap *h);
	void build(Heap *h, vector<int> A, int n);
	Heap()
	  {
			cout<<"Enter count, capcity, type: ";
			cin>>count>>capacity>>heap_type;
			array = vector<int>(capacity);
	  }
	private:
		int parent(int i);
		int Lchildren(int i);
		int Rchildren(int i);
		void percolatedown(int i);
		void resize();
};

int Heap::parent(int i)
{
	if(i <= 0 || i >= count)
	return -1;
	return (i - 1)/2;
}

int Heap::Lchildren(int i)
{
	int left = (2 * i) + 1;
	if(left >= count)
	return -1;
	return left;
}

int Heap::Rchildren(int i)
{
	int right = (2 * i) + 2;
	if(right >= count)
	return -1;
	return right;
}

int Heap::getmax(Heap *h)
{
	if(h->count == 0)
	return -1;
	else return h->array[0];
}

void Heap::percolatedown(int i)
{
	int l, r, max, temp;
	l = Lchildren(i);
	r = Rchildren(i);
	if(l != -1 && array[l] > array[i])
	max = l;
	else
	max = i;
	if(r != -1 && array[r] > array[max])
	max = r;
	if(max != i)
	{
		temp = array[max];
		array[max] = array[i];
		array[i] = temp;
		percolatedown(max);
	}
}

int Heap::deletemax(Heap *h)
{
	if(h->count == 0)
	return -1;
	int data;
	data = h->array[0];
	h->array[0] = h->array[h->count - 1];
	h->count--;
	percolatedown(0);
	return data;
}

void Heap::insert(Heap *h, int data)
{
	if(h->capacity == h->count)
	resize();
	h->count++;
	int i = h->count - 1;
	h->array[i] = data;
	while(i >= 0 && h->array[i] > h->array[(i - 1)/2])
	{
		int temp = h->array[i];
		h->array[i] = h->array[(i-1)/2];
		h->array[(i-1)/2] = temp;
		i = (i - 1)/2;
	}
}

void Heap::resize()
{
	vector<int> array_old = array;
	array = vector<int>(capacity*2);
	int i;
	for(i = 0; i < capacity; i++)
	{
		array[i] = array_old[i];
	}
	capacity = 2*capacity;
}

void Heap::destroy(Heap *h)
{
	if(h == NULL)
	return;
	delete h;
	h = NULL;
}

void Heap::build(Heap *h, vector<int> A, int n)
{
	if(h == NULL)
	{
		return;
	}
	while(n > h->capacity)
	resize();
	int i;
	for(i = 0; i < n; i++)
	{
		h->array[i] = A[i];
	}
	h->count = n;
	for(i = (n - 1)/2; i >=0; i--)
	{
		percolatedown(i);
	}
}

int main()
{
	Heap H;
	Heap *h = &H;
	vector<int> A;
	A.push_back(1);
	A.push_back(5);
	A.push_back(2);
	A.push_back(10);
	H.build(h, A, 4);
	H.insert(h, 20);
	cout<<H.getmax(h);
	cout<<endl<<H.deletemax(h);
	cout<<endl<<H.getmax(h);
	return 0;
}
