
#include<bits/stdc++.h>
using namespace std;


class Solution {
  public:
	void shortest_distance(vector<vector<int>>&matrix){
        int n = matrix.size() ;
        //cout<<n<<"\n";
        for( int k =0 ; k < n ; k++ ) {
            for( int i =0 ; i < n ; i++ ) {
                for( int j =0 ; j < n ; j++ ) {
                    if(i==k || j==k || matrix[i][k]==-1 || matrix[k][j] == -1) continue;
	                matrix[i][j] = min(matrix[i][j]==-1 ? INT_MAX: matrix[i][j], matrix[i][k] + matrix[k][j]);
                }
            }
        }
	}
};


/* INPUT 
1
12
0 4 2 1 2 9 4 8 -1 4 -1 -1
9 0 3 6 2 6 2 3 6 -1 -1 3
7 1 0 10 8 9 1 3 -1 7 -1 10
5 1 9 0 3 -1 1 10 7 1 -1 7
-1 5 1 4 0 2 10 4 10 6 4 5
7 8 3 7 5 0 5 1 3 5 7 2
6 -1 6 1 10 7 0 10 -1 -1 7 7
-1 3 2 7 4 -1 4 0 10 5 6 10
10 6 1 10 4 4 7 10 0 4 7 4
1 1 6 8 8 9 2 10 6 0 -1 3
5 9 3 -1 4 3 -1 -1 -1 3 0 1
2 2 8 6 2 4 4 3 -1 3 4 0
*/


/*
OUTPUT :

0 2 2 1 2 4 2 5 7 2 6 5
5 0 3 3 2 4 2 3 6 4 6 3
4 1 0 2 3 5 1 3 7 3 7 4
2 1 4 0 3 5 1 4 7 1 7 4
5 2 1 3 0 2 2 3 5 4 4 4
4 4 3 5 4 0 4 1 3 5 6 2
3 2 5 1 4 6 0 5 8 2 7 5
6 3 2 4 4 6 3 0 9 5 6 6
5 2 1 3 4 4 2 4 0 4 7 4
1 1 3 2 3 5 2 4 6 0 7 3
3 3 3 4 3 3 4 4 6 3 0 1
2 2 3 3 2 4 4 3 7 3 4 0
*/

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>matrix(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution obj;
		obj.shortest_distance(matrix);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cout << matrix[i][j] << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}