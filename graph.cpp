#include<iostream>
#include<deque>
using namespace std;
class graph
{
	int V; //number of vertex
	int E; //number of edge
	int **adj; //adjacency matrix
	int *visitedD;
	int *visitedB;//use for DFS traversal
	int *degree;
	public:
		graph()
		{
			int i;
			cout<<"Enter the number of vertex and edge";
			cin>>V>>E;
			visitedD = new int [V];
			for(i=0; i<V; i++)
			visitedD[i] = 0;
			visitedB= new int [V];
			for(i=0; i<V; i++)
			visitedB[i] = 0;
		}
		graph(int v, int e)
		{
			int i;
			V= v;
			E = e;
			visitedD = new int [V];
			for(i=0; i<V; i++)
			visitedD[i] = 0;
			visitedB= new int [V];
			for(i=0; i<V; i++)
			visitedB[i] = 0;
		}
		void cal_of_degree();
		void DFS(int u);
		void BFS(int u);
		void topological_sort();
		void adjMatrix();
		void adjMatrix_directed();
		~graph()
		{
			int i;
			for(i=0; i<V; i++)
			delete[] adj[i];
			delete[] adj;
			delete[] visitedD;
			delete[] visitedB;
			delete[] degree;
		}
};

void graph::adjMatrix()
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
		cout<<"Enter the adjacency vertices of the edge:";
		cin>>u>>v;
		adj[u][v] = 1;
		adj[v][u] = 1;
	}
}

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
void graph::DFS(int u)
{
	visitedD[u] = 1;
	cout<<u<<" ";
	int i;
	for(i=0; i<V; i++)
	{
		if(!visitedD[i] && adj[u][i])
		{
			DFS(i);
		}
	}
}

void graph::BFS(int u)
{
	int i;
	deque<int> q;
	q.push_back(u);
	while(!q.empty())
	{
		int n;
		n = q.front();
		cout<<n<<" ";
		q.pop_front();
		visitedB[n] = 1;
		for(i=0; i<V; i++)
		{
			if(!visitedB[i] && adj[n][i])
			q.push_back(i);
		}
	}
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

int main()
{
	graph G;
	G.adjMatrix_directed();
	G.cal_of_degree();
	cout<<"Result of DFS traversal:";
	G.DFS(0);
	cout<<endl<<"Result of BFS traversal:";
	G.BFS(0);
	cout<<endl<<"Result of topological traversal:";
    G.topological_sort();
	return 0;
}
