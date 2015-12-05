#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
    int t,n;
    cin>>t;

    while(t--) {
    	cin>>n;

    	int a[n];
    	for(int i=0;i<n;i++) {
    		cin>>a[i];
    	}
    	sort(a,a+n);
    	for(int i=n-1;i>=0;i--) {
    		cout<<a[i]<<" ";
    	}
    	cout<<endl;
    }
    return 0;
}
