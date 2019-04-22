#include <bits/stdc++.h>
#define max 100
using namespace std;

vector<int> graph[max];
vector<int> cycles[max];
int color[max];
int parent[max];
vector<int> check[max];
int num = 0;

void dfs(int u, int p)
{
	if (color[u] == 2) {
		return;
	}
	if (color[u] == 1) {
		num++;
		int temp=p;
        check[num].push_back(temp);
		while (temp!=u) {
			temp = parent[temp];
			check[num].push_back(temp);
		}
		return;
	}
	parent[u] = p;
	color[u] = 1;
     vector <int> ::iterator it;
	 for (it = graph[u].begin(); it != graph[u].end(); ++it) {
		if (*it == parent[u]) {
			continue;
		}
		dfs(*it, u);
	}
	color[u] = 2;
}

int main()
{
    int m,n;
    cin>>m>>n;
    int u,v;
    for (int i = 1; i <= n; ++i)
    {
        cin>> u;
        cin>>v;
        graph[u].push_back(v);  // for directed graph
        graph[v].push_back(u);
    }
	dfs(1,0);
	vector <int> ::iterator it;
	for(int i=1;i<=num;i++){
        cout<<"Cycle "<<i<<": ";
        for (it = check[i].begin(); it != check[i].end(); ++it)
			cout << *it << " ";
		cout << endl;
	}
}

