// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution
{
    public:
    void DFS(vector<vector<int>>&adj , vector<int>&visited , int node ) {
        visited[node] = 1 ;
        //recstack[node] = 1 ;
        for( auto it : adj[node] ) {
            if(visited[it] == -1 ) {
                DFS(adj,visited,it);
            }
        }
        //cout<<node<<" ";
        //recstack[node] = -1 ;
        //return false ;
    }
    int isCircle(int N, vector<string> A)
    {
        vector<vector<int>>adj(26) ;
        vector<int>indegre(26,0) ;
        vector<int>outdegre(26,0) ;
        for( auto it : A ) {
            adj[it[0]-'a'].push_back(it.back()-'a') ;
            indegre[it.back()-'a']++ ;
            outdegre[it[0]-'a']++;
        }
        for( int i =0 ; i < 26 ; i++ ) {
            if(indegre[i]  != outdegre[i] ) {
                return false ;
            }
        }
        int i;
        for( i =0 ; i < 26 ; i++ ) {
            if(adj[i].size()> 0 ) {
                break ;
            }
        }
        vector<int>visited(26,-1) ;
        DFS(adj,visited ,i) ;
        for( int i =0 ; i < 26 ; i++ ) {
            if(adj[i].size() > 0 && visited[i] == -1 ){
                return false ;
            }
        }
        
        return true ;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<string> A;
        string s;
        
        for(int i = 0;i < N; i++)
        {
            cin>>s;
            A.push_back(s);
        }
        
        Solution ob;
        cout<<ob.isCircle(N, A)<<endl;
    }
    return 0;
}  // } Driver Code Ends