#include <bits/stdc++.h>
#define pii pair<int,int> 

using namespace std;
typedef long long ll;

const int INF = INT_MAX;

vector<int> bag;

struct Edge {
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

void dijkstra(Graph gr, int u, int v)
{
	vector<int> dist(gr.n+5, INF);
	vector<bool> used(gr.n+5, false);
	vector<int> parent(gr.n+5);
	
	dist[u] = 0;
	parent[u] = u;
	
	//	while(bag.size() < gr.n)
	for (int i=0 ; i<gr.n ; i++){
		int ubest = -1, dbest = INF;
		
		for (int i=1 ; i<=gr.n ; i++){ // tim dinh chua xet co khoang cach nho nhat
			if (!used[i] && dist[i] < dbest){
				dbest = dist[i];
				ubest = i;
			}
		}
		
//		bag.push_back(ubest);
		used[ubest] = true;
		
		for (auto it : gr.adj[ubest]){ // duyet tat ca cac dinh ke voi dinh ubest
			int w = it.second, v = it.first;
			if (!used[it.first] && dist[v] > dbest+w){
				dist[v] = dbest+w;
				parent[v] = ubest;
			}
		}		
	}
	int k = v;
	cout << "Ket qua: " << dist[v] << endl;
	cout << "Duong di: ";
	while(k != u){ // tim danh sach canh duong di ngan nhat tu u den v
		cout << k << " ";
		k = parent[k]; 
		if (k == u) cout << u << " ";
	}
	
}

int main()
{
	Graph gr; cin >> gr;
	dijkstra(gr, 1, 4);
	
	return 0;
}
