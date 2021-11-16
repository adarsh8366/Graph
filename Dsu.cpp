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
