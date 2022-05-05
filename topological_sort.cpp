
#include <bits/stdc++.h>
using namespace std;


class Solution
{

	public:
    stack<int>st ;
    // Topological Sorting is all about finding the all the prevnodes in an order 
    // It means all connected components are going to be arranges in order they are connected
    //The topological sort algorithm takes a directed graph and returns an array of the nodes where each node appears before all the nodes it points to.
    // The ordering of the nodes in the array is called a topological ordering. 
	//Function to return list containing vertices in Topological order. 
    void DFS(vector<int>adj[] , int node , bool visited[] ){

        visited[node] = true ;
        for( auto it : adj[node] ) {
            if(visited[it]) continue ;
            DFS(adj,it,visited) ;
        }
        st.push(node) ;
    }
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
        bool visited[V] ;
        for( int i =0 ; i < V ; i++ ) {
            visited[i] = false ;
        }
        for( int i =0 ; i < V ; i+=1 ) {
            if(visited[i] == false ) {
                DFS(adj,i,visited) ;
            }
        }
        vector<int>ans ;
        while(!st.empty()) {
            ans.push_back(st.top()) ;
            st.pop() ;
        }
        return ans ;
	}
};


//This function is used to check our order is in correct order or not 
// This function checking the our topological order is correct or not 
// 9
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) { // o(n^2)
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}