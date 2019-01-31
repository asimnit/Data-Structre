#include<iostream>
#include<deque>
using namespace std;
class graph
{
	int V; //number of vertex
	int E; //number of edge
	int **adj;
	int *degree;
	int *distance;
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
	int u, v;
	for(i=0; i<E; i++)
	{
		cout<<"Enter the adjacency vertices of the edge"<<i<<":";
		cin>>u>>v;
		adj[u][v] = 1;
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
	distance = new int [V];
	path = new int [V];
	int i;
	int v, w;
	for(i=0; i<V; i++)
	{
		distance[i] = -1;
	}
	deque<int> q;
	q.push_back(s);
	distance[s] = 0;
	while(!q.empty())
	{
	   v= q.front();
	   q.pop_front();
	   for(w=0; w<V; w++)
	   {
	   	  if(adj[v][w] && distance[w] == -1)
	   	  {
	   	  	 distance[w]= distance[v] + 1;
	   	  	 path[w] = v;
	   	  	 q.push_back(w);
		  }
	   }	
	}
	cout<<"node  distance"<<endl;
	for(i=0; i<V; i++)
	{
		cout<<i<<"     "<<distance[i]<<endl;
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
    cout<<"Enter the source and desrtinatio of the path to be displayed:";
    int s, d;
    cin>>s>>d;
    cout<<endl;
    G.printpath(s, d);
	return 0;
}
