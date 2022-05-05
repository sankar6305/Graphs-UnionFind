class Solution {
public:
    int parent[1001] ;
    int Rank[1001] ;
    void mst(){
        for( int i = 0 ; i < 1001 ; i+=1 ) {
            parent[i] = i ;
            Rank[i] = 0 ;
        }
    }
    int findPar(int node ) {
        if(node == parent[node] ) {
            return node ;
        }
        return parent[node] = findPar(parent[node]) ;
    }
    void unionFind(int a , int b ) {
        a = findPar(a) ;
        b = findPar(b) ;
        if(Rank[a] < Rank[b]) {
            parent[a] = b ;
        } else if( Rank[a] > Rank[b] ){
            parent[b] = a ;
        } else{
            parent[a] = b ;
            Rank[b]+=1 ;
        }
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        ios_base::sync_with_stdio(false) ;
        cin.tie(NULL) ;
        cout.tie(NULL) ;
        mst() ;
        int n = points.size() ;
        vector<vector<int>>vect;
        for( int i =0 ; i < points.size() ; i+=1 ) {
            for( int j =i+1 ; j < points.size() ; j+=1 ) {
                if(i==j){continue;}
                int dist = abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]) ;
                // it is a distance between two nodes ==> leetcode ==> Q.no 1584  
                vect.push_back({dist,i,j}) ;
            }
        }
        int ans = 0 ;
        sort(vect.begin(),vect.end()) ; // This for getting the least weighted node 
        // Kruskal can be usfull for finding the shortest distance by connecting the all the paths 


        /*
         Dijkstra's Algorithm at every step greedily selects the next edge that is closest to some source vertex s. 
         It does this until s is connected to every other vertex in the graph. Clearly, the predecessor subgraph that is produced is a spanning tree of G, but is the sum of edge weights minimized?
         Prim's Algorithm, which is known to produce a minimum spanning tree, is highly similar to Dijkstra's Algorithm, but at each stage it greedily selects the next edge that is closest to any vertex currently in the working MST at that stage. Let's use this observation to produce a counterexample. */




        for( auto it : vect ) {
            int w = it[0] ;
            int x = it[1] ;
            int y = it[2] ;
            if( findPar(x)!=findPar(y) ) {
                ans += w ;
                unionFind(x,y) ;
            }
        }
        return ans ;
    }
};