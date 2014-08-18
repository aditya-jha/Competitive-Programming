#include<iostream>
#include<cstdio>
#include<string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	
	unsigned long long int a,b,w,x,c,con=0,p,aa,bb,q;
	
	cin>>a>>b>>w>>x>>c;
	
	
	while(c>a) {
		
		
		if(b<x) {
			a--;
			b = w - (x-b);
			c--;
			con++;
		}
		if(b>=x) {
			q = (b-x)/x;
			c = c-q;
			con+=q;
		}
	}
	
	cout<<con<<'\n';
	
	
	return 0;
}
