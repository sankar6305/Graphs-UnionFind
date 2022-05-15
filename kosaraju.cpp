// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	void DFS(vector<int>adj[] , int index , vector<int>&visited,stack<int>&st ) {
	    visited[index] = 1 ;
	    for( auto it : adj[index] ) {
	        if(visited[it] == 0) {
	            DFS(adj,it,visited,st) ;
	        }
	    }
	    st.push(index) ;
	}
	vector<vector<int>>transposed_matrix(vector<int>adj[] , int V) {
	    vector<vector<int>>target(V) ;
	    for( int i =0 ; i < V ; i++ ) {
	        for(auto it : adj[i] ) {
	            target[it].push_back(i) ;
	        }
	    }
	    return target ;
	}
	void DFS_tr(vector<vector<int>>&adj , int index, vector<int>&visited ) {
	    visited[index] = 1 ;
	    for( auto it : adj[index] ) {
	        if(visited[it] == 0) {
	            DFS_tr(adj,it,visited) ;
	        }
	    }
	}
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<int> adj[])
    {
        stack<int>st ;
        vector<int>visited(V,0) ;
        for( int i=0 ; i < V ; i++ ) {
            if(visited[i] == 0 ) {
                DFS(adj,i,visited,st) ;
            }
        }
        visited = vector<int>(V,0) ;
        vector<vector<int>>tr_matrix = transposed_matrix(adj,V) ;
        //code here
        stack<int>st1 ;
        int count =0 ;
        while(!st.empty()) {
            auto it = st.top() ;
            st.pop() ;
            if(visited[it] == 0 ) {
                DFS_tr(tr_matrix,it,visited) ;
                count++;
            }
        }
        return count ;
        
    }
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends
