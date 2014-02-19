#include<iostream>
using namespace std;

int main() {
	int t,u,n,index;
	double d,r,curr,last_month,c,m,diff,max=0.00;
	cin>>t;
	while(t>0) {
		cin>>d>>u>>n;
		last_month = u*d;
		index = -1;
		max = 0.00;
		for(int i=0; i<n; i++) {	
			cin>>m>>r>>c;
			curr = c/m + r*u;
			diff = last_month - curr;
			if(diff>max) {
				max = diff;
				index = i;
			}
		}
		cout<<index+1<<endl;
		t--;
	}
	return 0;
}
