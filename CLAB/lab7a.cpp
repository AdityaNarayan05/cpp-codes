//MST USING PRISM ALGORITHM.
//INPUT DATA IS ADJACENCY LIST.
//BY:ADITYA NARAYAN JAISWAL 20U02065
#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <utility>

using namespace std;
const int MAX = 1e4 + 5;
typedef pair<long long, int> pii;
bool marked[MAX];
vector <pii> adj[MAX];
int prim(int x)
{
    priority_queue<pii, vector<pii>, greater<pii> > Q;
    int y;
    long long minimumCost = 0;
    pii p;
    Q.push(make_pair(0, x));
    while(!Q.empty())
    {
        // Select the edge with minimum weight
        p = Q.top();
        Q.pop();
        x = p.second;
        // Checking for cycle
        if(marked[x] == true)
            continue;
        minimumCost += p.first;
        marked[x] = true;
        for(int i = 0;i < adj[x].size();++i)
        {
            y = adj[x][i].second;
            if(marked[y] == false)
                Q.push(adj[x][i]);
        }
    }
    return minimumCost;
}

int main()
{
    cout<<"BY:ADITYA NARAYAN JAISWAL 20U02065"<<endl;
    int nodes, edges, x, y;
    long long weight, minimumCost;
    cout<<"Enter no nodes and edges"<<endl;
    cin >> nodes >> edges;
    for(int i = 0;i < edges;++i)
    {
        cout<<"Enter the vertexs and their weight"<<endl;
        cin >> x >> y >> weight;
        adj[x].push_back(make_pair(weight, y));
        adj[y].push_back(make_pair(weight, x));
    }
    // Selecting 1 as the starting node
    minimumCost = prim(1);
    cout << minimumCost << endl;
    return 0;
}