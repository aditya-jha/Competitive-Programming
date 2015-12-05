#include<iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);

	int t, n;
	long long x, sum;
	cin>>t;

	while(t--) {
		cin>>n>>x;
		int a[n];

		for(int i=0;i<n;i++) {
			cin>>a[i];
		}

		int j=0, flag = 0;
		sum = 0;

		for(int i=0;i<n;i++) {
			if(flag) break;
			sum += a[i];
			if(sum == x) {
				flag = 1;
				break;
			} else if(sum > x) {
				while(j<=i && sum>x) {
					sum -= a[j++];
					if(sum == x) {
						flag = 1;
						break;
					}
				}
			}
		}

		if(!flag) cout<<"NO\n";
		else cout<<"YES\n";
	}
	return 0;
}
