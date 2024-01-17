vector<Edge> Prim()
	{	
		vector<bool> used(n+5, false); // danh dau dinh da duoc tham
		vector<Edge> mst; // danh sach canh cau cay khung
		
		used[1] = true; // tim cay khung tu dinh dau tien cua do thi
	
		while(mst.size() < n-1) // lap den khi cay khung tim duoc du n-1 canh
		{
			int u, v; float minW = INF; 
			for (int i=1 ; i<=n ; i++){
				if (used[i]){
					for (auto it : adj[i]){
						if (it.second < minW && !used[it.first]){
							minW = it.second;
							u = it.first; v = i;
						}
					}
				}
			}
			used[u] = true;
			mst.push_back({u, v, minW}); // them canh vao cay khung
		}
		
		return mst;
	}