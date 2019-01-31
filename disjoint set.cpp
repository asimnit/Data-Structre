#include<iostream>
using namespace std;
class set
{
	int *s;
	int size;
	void makeset();
	public:
		set()
		{
			cout<<"enter the number of the vetices:";
			cin>>size;
			s = new int [size];
			makeset();
		}
		set(int s)
		{
			size =s;
			this->s = new int [size];
			makeset();
		}
		int find(int x);
		void Union(int x, int y);
		~set()
		{
			delete s;
		}
};

void set::makeset()
{
	int i; 
	for(i=0; i<size; i++)
	{
		s[i] = -1;
	}
}

int set::find(int x)
{
	if(s[x]<0)
	 return x;
	else
	 find(s[x]);
}

void set::Union(int x, int y)
{
	if(find(x) == find(y))
	{
	    cout<<"The cycle is created."<<endl;
	    return;
    }
else
{

   int root1, root2;
   root1 = find(x);
   root2 = find(y);
   if(s[root2]<s[root1])
   {
   	   s[root1] = root2;
   	   s[root2] += s[root1];
   }
   else
   {
   	  s[root2] = root1;
   	  s[root1] += s[root2];
   }
}
}

int main()
{
	set S;
	int t = 1;
	int i = 1; 
	while(t)
	{
		int v1, v2;
		cout<<"Enter the adjacent vertices of the edge"<<i<<": ";
		cin>>v1>>v2;
		S.Union(v1, v2);
		i++;
	}
	return 0;
}

