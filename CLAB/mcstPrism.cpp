//MST USING PRISM ALGORITHM.
//INPUT DATA IS ADJACENCY MATRIX.
//BY:ADITYA NARAYAN JAISWAL 20U02065
#include <bits/stdc++.h>
using namespace std;

#define V 7

int minKey(int key[], bool mstSet[])
{
	int min = INT_MAX, min_index;

	for (int v = 0; v < V; v++)
		if (mstSet[v] == false && key[v] < min)
			min = key[v], min_index = v;

	return min_index;
}

void printMST(int parent[], int graph[V][V])
{   
    int s=0;
	cout<<"Edge \tWeight\n";
	for (int i = 1; i < V; i++){
		cout<<parent[i]<<" - "<<i<<" \t"<<graph[i][parent[i]]<<" \n";
        s+=graph[i][parent[i]];
    }
    cout<<"MINIMUM COST :"<<s<<endl;
}

void primMST(int graph[V][V])
{
	int parent[V];
	
	
	int key[V];
	bool mstSet[V];

	for (int i = 0; i < V; i++)
		key[i] = INT_MAX, mstSet[i] = false;

	key[0] = 0;
	parent[0] = -1; 

	for (int count = 0; count < V - 1; count++)
	{
		int u = minKey(key, mstSet);
		mstSet[u] = true;
		for (int v = 0; v < V; v++)
			if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
				parent[v] = u, key[v] = graph[u][v];
	}

	printMST(parent, graph);
}


int main()
{
	int graph[V][V] = { { 0,5,9,7,0,0,4},
						{ 5,0,10,0,8,21,0},
						{ 9,10,0,20,25,0,0},
						{ 7,0,20,0,11,0,6},
						{ 0,8,25,11,0,30,0},
                        { 0,21,0,0,30,0,0},
                        { 4,0,0,6,0,0,0} };

	cout<<"BY:ADITYA NARAYAN JAISWAL 20U02065"<<endl;
	primMST(graph);

	return 0;
}