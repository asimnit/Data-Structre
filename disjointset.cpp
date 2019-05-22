#include<bits/stdc++.h>
using namespace std;

class Set 
{
	int size;
	vector<int> s;
	public:
		void makeset();
		int find(int x);
		void Union(int x, int y);
};

void Set::makeset()
{
	cout<<"Enter the size of the disjoint set: ";
	cin>>size;
	s = vector<int>(size);
	int i;
	for(i = 0; i <size; i++)
	s[i] = i;
}

int Set::find(int x)
{
	if(x < 0 || x >= size)
	return -1;
	if(s[x] == x)
	return x;
	else return find(s[x]);
}

void Set::Union(int x, int y)
{
	int root1 = find(x);
	int root2 = find(y);
	if(root1 == root2)
	return;
	if(root1 == -1 || root2 == -1)
	return;
	s[root1] = root2;
}

int main()
{
	Set s;
	s.makeset();
	s.Union(5, 6);
	s.Union(1, 2);
	s.Union(0, 2);
	s.Union(1, 3);
	cout<<s.find(0)<<" "<<s.find(1);
}
