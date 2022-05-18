

#include<bits/stdc++.h>
using namespace std;



class Solution
{
	public:
	vector<vector<int>>ans ;
	void DFS(int curr, vector<int>adj[] , vector<int>&disc , vector<int>&low , vector<int>&isPresentMyStack,stack<int>&st ) {
	    
	    static int timei =0  ;
	    low[curr] = disc[curr] = timei++ ;
	    st.push(curr) ;
	    isPresentMyStack[curr] = 1 ;
	    
	    for( int it : adj[curr] ) {
	        if(disc[it] == -1 ) {
	            DFS(it,adj,disc,low,isPresentMyStack,st) ;
	            low[curr] = min(low[curr],low[it]) ; 
	        } else if(isPresentMyStack[it] == 1) { //if it is back edge or cross edges 
    	        // if it is cross edge it doesn't be includeed in the stack 
    	        // if it is in the stack it is the cross edge 
	            low[curr] = min(low[curr] , disc[it]) ;
	        }
	    }
	    if( disc[curr] == low[curr] ) {
	        vector<int>temp ;
	        while(st.top() != curr ) {
	            temp.push_back(st.top()) ;
	            isPresentMyStack[st.top()] = -1 ;
	            st.pop() ;
	        }
	        temp.push_back(st.top()) ;
	        isPresentMyStack[curr] = -1 ;
	        st.pop() ;
	        sort(temp.begin(),temp.end()) ;
	        ans.push_back(temp) ;
	    }
	    return ;
	}
	
	
    vector<vector<int>> tarjans(int V, vector<int> adj[])
    {
        // descovery Array 
        vector<int>disc(V,-1) ;
        vector<int>low(V,-1) ;
        vector<int>isPresentMyStack(V,-1) ;
        stack<int>st ;
        
        for( int i = 0 ; i < V ; i++ ) {
            if(disc[i] == -1 ) {
                DFS(i,adj,disc,low,isPresentMyStack,st) ;
            }
        }
        sort(ans.begin(),ans.end()) ;
        return ans ;
    }
};



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
        vector<vector<int>> ptr = obj.tarjans(V, adj);

        for(int i=0; i<ptr.size(); i++)
        {
            for(int j=0; j<ptr[i].size(); j++)
            {
                if(j==ptr[i].size()-1)
                    cout<<ptr[i][j];
                else
                    cout<<ptr[i][j]<<" ";
            }
            cout<<',';
        }
        cout<<endl;
    }

    return 0;
}

