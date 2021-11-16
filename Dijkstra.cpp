vector<int> dijkstra(vector<vector<int>> &edge, int vertices, int edges, int source) 
{
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector<int> dist(vertices,INT_MAX);
    dist[source] = 0;
    vector<vector<pair<int,int>>> adj(vertices);
    for(auto &it:edge) {
        adj[it[0]].push_back(make_pair(it[1],it[2]));
        adj[it[1]].push_back(make_pair(it[0],it[2]));
    }
    pq.push(make_pair(0,source));
    
    while(!pq.empty()) {
        auto top = pq.top();
        pq.pop();
        int par = top.second;
        
        for(auto &it:adj[par]) {
            int child = it.first;
            int wt = it.second;
            if(dist[child]>wt+dist[par]) {
                dist[child] = wt+dist[par];
                pq.push(make_pair(dist[child],child));
            }
        }
    }
    return dist;
}
