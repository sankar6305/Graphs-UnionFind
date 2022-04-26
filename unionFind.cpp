#include<bits/stdc++.h>
using namespace std ;

// Parent Array to capture the parent array 
int parent[100000] ;
// Fiing the Rank of node 
int Rank[100000] ;

void makeSet() {
	// Initializing the all values with the parent and Rank arrays 
	for( int i = 0 ; i<= 100000; i+=1 ) {
		parent[i] = i ;
		Rank[i] = 0 ; 
	}
}

int findPar( int node ) {
	if( node == parent[node] ) {
		return node ;
	}
	return parent[node] = findPar(parent[node]) ;
	// Finding the parents of the array values 
}


void dsunion(int u , int v ) {
	u  = findPar(u) ;
	v = findPar(v) ;
	if(Rank[u] < Rank[v] ){
		parent[u] = v ;
	} else if( Rank[u] > Rank[v] ) {
		parent[v] = u ;
	} else{
		parent[v] = u ;
		Rank[u] +=1 ;
	}
}

int main() {
	makeSet() ;
	int m ;
	cin>>m;
	while(m--) {
		int u,v ;
		char ch ;
		cin>>ch>>u>>v ;
		// ch is used for finding the charecter of the array in the list 
		// u and v are nodes 
		if( ch=='U' ) {
			dsunion(u,v) ;
		} else {
			if(findPar(u) == findPar(v) ) {
				cout<<"They are connected \n" ;
			} else{
				cout<<"Thet are not connected  \n" ;
			}
		}
	}
}
