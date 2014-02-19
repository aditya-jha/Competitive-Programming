#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <queue>
#include <utility>

using namespace std;

int scan_d() {
	int ip=getchar(),ret=0;
	for(;ip<'0'||ip>'9';ip=getchar());
	for(;ip>='0'&&ip<='9';ip=getchar())
		ret=ret*10+ip-'0';

	return ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	
	int n;
	int a[100010], b[100010];
	bool first[100010], second[100010];
	
	//cin>>n;
	n = scan_d();
	
	for(int i=0;i<n;i++) {
		//cin>>a[i]>>b[i];
		a[i] = scan_d();
		b[i] = scan_d();
		//first[i] = second[i] = false;
		
	}
	
	int k = n/2;
	int f=0,s=0,index;
	
	for(int j=0;j<k;j++) {
		first[j]=true;
		second[j] = true;
	}
	s=0;f=0;
	for(int i=0;i<n;i++) {
		if(a[f]<b[s]) { first[f]=true; f++; }
		else { second[s] = true; s++; }
	}

	for(int i=0;i<n;i++) {
		if(first[i]==true) putchar('1');
		else putchar('0');
	}
	putchar('\n');

	for(int i=0;i<n;i++) {
		if(second[i]==true) putchar('1');
		else putchar('0');
	}
	putchar('\n');
	
	return 0;
}
