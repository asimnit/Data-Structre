#include<iostream>
#include<deque>
#include<algorithm>
const long MAX_INT = 9999;
using namespace std;
struct vertex
{
	int id;//identifier
	int d;//distance from a given vertex
	friend bool operator<(vertex v1, vertex v2);
	friend bool operator>(vertex v1, vertex v2);
	friend bool operator==(vertex v1, vertex v2);
};

bool operator<(vertex v1, vertex v2)
{
	return v1.d<v2.d;
}

bool operator>(vertex v1, vertex v2)
{
	return v1.d>v2.d;
}

bool operator==(vertex v1, vertex v2)
{
	return v1.d==v2.d;
}

class graph
{
	int V; //number of vertex
	int E; //number of edge
	int **adj;
	int *degree;
	int **weight;//weight of any edge
	int *path;
	public:
		graph()
		{
			int i;
			cout<<"Enter the number of vertex and edge";
			cin>>V>>E;
		}
		graph(int v, int e)
		{
			int i;
			V= v;
			E = e;
		}
		void cal_of_degree();
		void topological_sort();
	    void adjMatrix_directed();
	    void shortestpath(int s);//to calculate shortest path to each node from a given source node
	    void printpath(int s, int d);
		~graph()
		{
			int i;
			for(i=0; i<V; i++)
			delete[] adj[i];
			delete[] adj;
		}
};

void graph::adjMatrix_directed()
{
	int i,j;
	adj = new int* [V];
	for(i=0; i<V; i++)
	{
		adj[i] = new int [V];
	}
	for(i=0; i<V; i++)
	{
		for(j=0; j<V; j++)
		{
			adj[i][j] = 0;
		}
	}
	weight = new int* [V];
	for(i=0; i<V; i++)
	{
		weight[i] = new int [V];
	}
	for(i=0; i<V; i++)
	{
		for(j=0; j<V; j++)
		{
			weight[i][j] = 0;
		}
	}
	int u, v;
	for(i=0; i<E; i++)
	{
		cout<<"Enter the adjacency vertices of the edge"<<(i+1)<<":";
		cin>>u>>v;
		adj[u][v] = 1;
		cout<<endl<<"Enter the weight of the edge:";
		cin>>weight[u][v];
	}
}

void graph::topological_sort()
{
	int counter= 0;
	int i;
	int v;
	deque<int> q;
	for(i=0; i<V; i++)
	{
		if(degree[i] == 0)
		q.push_back(i);
	}
	while(!q.empty())
	{
		v = q.front();
		cout<<v<<' ';
		counter++;
		q.pop_front();
		for(i=0; i<V; i++)
		{
			if(adj[v][i])
		{
			degree[i] = degree[i] - 1;
			if(degree[i] == 0)
			q.push_back(i);
		}
		}
	}
	if(counter!=V)
	cout<<"There is cycle in the graph";
}

void graph::cal_of_degree()
{
	degree = new int [V];
	int i, j;
	for(i=0; i<V; i++)
	{
		degree[i] = 0;
	}
	for(i=0; i<V; i++)
	{
		for(j=0; j<V; j++)
		{
			if(adj[j][i])
			degree[i]++;
		}
	}
}

void graph::shortestpath(int s)
{
	vertex *v;
	v = new vertex [V];
	path = new int [V];
	int i, j;
	int newd;
	for(i=0; i<V; i++)
	{
		v[i].id = i;
		v[i].d = MAX_INT;
	}
	v[s].d = 0;
	int k;
	for(i=0; i<V-1; i++)
	{  
		for(j=0; j<V; j++)
		{
			for(k=0; k<V; k++)
			{
				if(adj[j][k])
				{
					newd = v[j].d + weight[j][k];
					if(v[k].d>newd)
					{
						v[k].d = newd;
						path[k]= j;
					}
				}
			}
		}
	}
	cout<<"node  distance"<<endl;
	for(i=0; i<V; i++)
	{
		cout<<i<<"     "<<v[i].d<<endl;
	}
}

void graph::printpath(int s, int d)
{
   int start=100;
   int dest = d;
   while(start!= s)
   {
       start = path[dest];
	   cout<<dest<<"<-";
	   dest = start;   	
   }
   cout<<s;	
}

int main()
{
	graph G;
	G.adjMatrix_directed();
	G.cal_of_degree();
	cout<<endl<<"Result of topological traversal:";
    G.topological_sort();
    cout<<endl<<"the shotest path to every element is:"<<endl;
    G.shortestpath(0);
    int t = 1;
    while(t)
{
    cout<<"Enter the source and desrtinatio of the path to be displayed:";
    int s, d;
    cin>>s>>d;
    cout<<endl;
    G.printpath(s, d);
    cout<<endl<<"enter 1:to contonue and 0:to stop:"<<endl;
    cin>>t;
}
	return 0;
}
