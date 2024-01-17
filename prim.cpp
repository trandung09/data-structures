#include <bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;
const int INF = INT_MAX;

struct edge {
	int u, v, w;
};

class Graph 
{
public:
	int n, t;
	vector<vector<pii>> adj;

public:
	Graph(){
	}
	
	friend istream& operator>> (istream& cin, Graph& gr){
		cin >> gr.n >> gr.t;
		gr.adj.resize(gr.n+1);
		for (int i=0 ; i<gr.t ; i++){
			int u, v, w;
			cin >> u >> v >> w;
			gr.adj[u].push_back({v, w});
			gr.adj[v].push_back({u, w});
		}
		return cin;
	}
};

vector<int> dist(1006, INF);
vector<int> parent(1006);

void prim(Graph gr, int s)
{
	vector<bool> used(gr.n+5, false);
	vector<edge> mst;
	dist[s] = 0;
	
	for (int q=0 ; q<gr.n-1 ; q++)
	{
		int dMin = INF, u = -1;
		for (int i=1 ; i<=gr.n ; i++){ // tim phan tu co dist nho nhat
			if (!used[i] && dist[i] < dMin){
				dMin = dist[i];
				u = i;
			}
		}
		
		used[u] = true; // danh dau u da duoc duyet
		
		for (auto it : gr.adj[u]){
			int v = it.fi, w = it.se;
			if (dist[v] > w && !used[v]){
				parent[v] = u;
				dist[v] = w; // cap nhat duong di cho cac canh ke cua u
			}
		}
	
	}      
	
	int res  = 0;
	for (int i=1 ; i<=gr.n ; i++){
		if (dist[i] != 0){
			cout << i << " " << parent[i] << " " << dist[i] << endl;
			res += dist[i];
		}
	}
		
	cout << "Result: " << res;                             
}

int main()
{
	Graph gr; cin >> gr;
	cout << "Cay khung nho nhat:\n";
	prim(gr, 1);
	
	return 0;
}