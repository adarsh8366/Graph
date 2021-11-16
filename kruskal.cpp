class DSU {
    private:
    vector<int> siz,par;
    public :
    DSU(int n) {
        for(int i=0;i<=n;++i) {
            siz.push_back(1);
            par.push_back(i);
        }
    }
    
    int find_par(int x) {
        if(par[x]==x) {
            return x;
        }
        
        return par[x] = find_par(par[x]);
    }
    
    void make_union(int x,int y) {
        int px = find_par(x);
        int py = find_par(y);
        if(px!=py) {
            if(siz[px]<siz[py]) {
                par[px] = py;
                siz[py] += siz[px];
            } else {
                par[py] = px;
                siz[px] += siz[py];
            }
        }
    }
}; 

class Node {
    public:
    int wt,u,v;
    public:
    Node(int u,int v,int wt) {
        this->u = u;
        this->v = v;
        this->wt = wt;
    }
};
bool cmp(Node x,Node y) {
    return x.wt<y.wt;
}

int kruskal(vector<Node>&edges,int n) {
    int ans = 0;
    DSU dsu(n);
    sort(begin(edges),end(edges),cmp);
    for(auto &it:edges) {
        int u = it.u, v = it.v, wt = it.wt;
        int pu = dsu.find_par(u);
        int pv = dsu.find_par(v);
        if(pu!=pv) {
            ans+= wt;
            dsu.make_union(pu,pv);
        }
    }
    
    return ans;
}
