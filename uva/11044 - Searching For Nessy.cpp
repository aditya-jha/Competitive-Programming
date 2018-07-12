#include <iostream>
#include <cmath>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);

	int t;
	cin>>t;

	while(t--) {
		double n, m;
		cin>>n>>m;

        int r = ceil((n-2)/3);
        int c = ceil((m-2)/3);
		cout<<r*c<<endl;
	}

	return 0;
}