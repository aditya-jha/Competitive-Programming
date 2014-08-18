#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>

using namespace std;

int digits(long long int a) {
	int count = 0;
	while(a!=0) {
		count++;
		a = a/10;
	}
	return count;
}

int main() {
	ios_base::sync_with_stdio(0);
	
	long long int w,m,k,i,j,pay=0,length=1,dig,rem;
	
	cin>>w>>m>>k;
	
	i=m;
	dig = digits(m);
	
	j = (long long int)pow(10.0,dig);
	
	//cout<<j<<endl;
	cout<<"j-i: "<<j-i<<endl;
	while(true) {
		
		pay = dig*k;
		
		rem = w - ((j-i)*pay);
		cout<<"dig: "<<dig<<" pay: "<<pay<<" rem: "<<rem<<endl;
		if(rem>=0) {
			i = j;
			dig++;
			w = rem;
			j = j*10;

		} else {
			pay=dig*k;
			rem = w/pay;
			i+=rem;
			break;
		}
		cout<<i<<endl;
		//if(length==0) break;
	}
	
	cout<<i-m<<"\n";

	return 0;

}
