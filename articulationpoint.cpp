


#include<bits/stdc++.h>
using namespace std;


class Solution {
  public:
    vector<int>ans ;
    map<int,int>mp ;
    void tarjans_algo(vector<int>adj[] ,int curr , vector<int>&desc , vector<int>&low , int par ){
        static int time =0 ;
        int child =0 ;
        desc[curr] = low[curr] = time++;
        for( auto it : adj[curr] ) {
            if(desc[it] == -1) {
                tarjans_algo(adj,it,desc,low,curr) ;
                child++;
                low[curr] = min(low[curr],low[it]) ;
                if(par != -1 && low[it] >= desc[curr] ){
                    mp[curr]++;
                }
            } else {
                low[curr] = min(low[curr],desc[it]) ;
            }
        }
        if(par == -1 && child > 1){
            mp[curr]++;
        }
    }

    vector<int> articulationPoints(int V, vector<int>adj[]) {
        vector<int>desc(V,-1) ;
        vector<int>low(V,-1) ;
        for( int i =0 ;i < V ; i++ ){
            if(desc[i] == -1){
                tarjans_algo(adj,i,desc,low,-1);
            }

        }
        for( auto it : mp ){
            ans.push_back(it.first) ;
        }
        return ans ;
    }
};

// { Driver Code Starts.

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}  // } Driver Code Ends
