
#include<bits/stdc++.h>
using namespace std;

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        //priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq ;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq ;
        int parant[V] ;
        int Key[V] ;
        bool mstVisit[V] ;
        // To solve this problem i don't need parant , but i am using it , to know the parant 
        for( int i =0; i < V ; i++ ) {
            Key[i] = INT_MAX ;
            mstVisit[i] = false ;
        }
        parant[0] = -1 ;
        Key[0] = 0 ;
        pq.push({0,0}) ;
        while(!pq.empty() ) {
            auto it = pq.top() ;
            pq.pop() ;
            //int u = it.first ;
            int v = it.second ;
            mstVisit[v] = true ;
            for( auto it1 : adj[v] ) {
                int u = it1[0] ;
                int weight = it1[1] ;
                if(mstVisit[u] == false && weight < Key[u] ){
                    Key[u] = weight ;
                    pq.push({Key[u],u}) ;
                    parant[u] = v ;
                }
            }
        }
        int ans =0 ; 
        for( int i =0 ; i < V ; i+=1 ) {
            ans += Key[i] ;
        }
        // if you want know the connections in between you can use this parant array to printing 
        // print the parant[i] <<" "<< i <<<"\n"; to know the parant 

        return ans ;
        // Total minimum value 
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
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}