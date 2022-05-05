
#include<bits/stdc++.h>
using namespace std;


class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> eadj[], int S)
    {
        // Code here
	// This Works for minimum path from Single source to all the remaining paths 
	
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq ;
        vector<int>dist(V,INT_MAX) ;
        dist[S] = 0 ;
        pq.push({0,S}) ;
        while(!pq.empty()) {
            auto it = pq.top() ;
            pq.pop() ;
            int w1 = it.first ;
            int adj = it.second ;
            for( auto it : eadj[adj] ) {
                int w1 = it[1] ;
                int y1 = it[0] ;
                if(dist[y1] > dist[adj] + w1 ) {
                    dist[y1] = dist[adj] + w1 ;
                    pq.push({w1,y1}) ;
                }
            }
        }
        return dist ;
    }
};


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}
