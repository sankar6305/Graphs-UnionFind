#include <bits/stdc++.h>
using namespace std;

vector<long long>SegmentedSeive(long long l,long long r) {
    long long nsqrt = sqrt(r);
    vector<long long>isPrimes(nsqrt+1, 1), primes;
    isPrimes[0] = isPrimes[1] = 0;
    for(long long i = 2; i <= nsqrt; i++) {
        if(isPrimes[i] == 1) {
            primes.push_back(i);
            for(long long j = i*i; j <= nsqrt; j+=i) {
                isPrimes[j] = 0;
            }
        }
    }
    vector<long long>CurrentPrimes(r-l+1, 1);
    vector<long long>ans;
    for(auto i : primes) {
        for(long long j= max(i*i, (l+i-1)/i*i); j <= r; j+=i) {
            CurrentPrimes[j-l] = 0;
        }
    }
    if(l == 1) CurrentPrimes[0] = 0;
    return CurrentPrimes;
}


int main() {
	int t;
	cin >> t;
	while(t--) {
	    long long l, r;
	    cin >> l >> r;
	    vector<long long>ans = SegmentedSeive(l, r);
	    for(int i = 0; i < ans.size(); i++) {
	        if(ans[i] == 1) cout<<i+l<<"\n";
	    }
	    cout<<"\n";
	}
}

//{[
//int
