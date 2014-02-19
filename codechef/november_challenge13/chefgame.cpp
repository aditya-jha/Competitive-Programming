#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<climits>
#include<queue>

using namespace std;

#define MOD 1000000007
#define llu long long unsigned
#define lld long long
#define ld long

int scan_d() {
	int ip=getchar_unlocked(),ret=0;
	for(;ip<'0'||ip>'9';ip=getchar_unlocked());
	for(;ip>='0'&&ip<='9';ip=getchar_unlocked())
		ret=ret*10+ip-'0';

	return ret;
}
long scan_ld() {
	ld ip=getc(stdin),ret=0;
	for(;ip<'0'||ip>'9';ip=getc(stdin));
	for(;ip>='0'&&ip<='9';ip=getc(stdin))
	ret=ret*10+ip-'0';
	
	return ret;
}

int main() {
	long int t,k,n,temp,min_val,p,chance,flag;
	long count;
	int arr[101][50], min[101];
	queue<long int> odd,even;
	t = scan_ld();
	while(t--) {
		k=scan_ld(); p=0;
		for(long int i=0;i<k;i++) {
			n=scan_ld();
			if(n==0);
			else if(n==1) {
				temp = scan_ld();
				if(temp%2==0) even.push(temp);
				else odd.push(temp);
			} else {
				min_val=LONG_MAX;
				for(long int j=0;j<n;j++) {
					arr[p][j] = scan_ld();
					if(arr[p][j]<min_val) min_val=arr[p][j];
				}
				min[p++] = min_val;				
			}
		}

		chance = 1; flag=0; count=0;
		for(long int i=0;i<p;i++) {
			if(chance==1) {
				if(min[i]%2!=0) { count++; chance=2; }
				else { count+=2; chance=1; }
			} else {
				if(min[i]%2==0) { count++; chance=1; }
				else { count+=2; chance=2; }
			}
		}
		for(long int i=0;;i++) {
			if(chance==1) {
				if(odd.empty()) { flag=0; break; }
				else { chance=2; odd.pop(); }
			} else {
				if(even.empty()) { flag=1; break; }
				else { chance=1; even.pop(); }
			}
		}

		if(flag==1) { printf("ODD\n"); continue; }
		
		for(long int i=0;i<p;i++) {
			if(chance==1) {
				if(min[i]%2==0) { count++; chance=2; }
				else { count+=2; chance=1; }
			} else {
				if(min[i]%2!=0) { count++; chance=1; }
				else { count+=2; chance=2; }
			}
		}
		for(long int i=0;;i++) {
			if(chance==1) {
				if(even.empty()) { flag=0; break; }
				else { chance=2; even.pop(); }
			} else {
				if(odd.empty()) { flag=1; break; }
				else { chance=1; odd.pop(); }
			}
		}
		
		if(flag==1) { printf("EVEN\n"); continue; }
		
		else printf("DON'T PLAY\n");
	}
	return 0;
}
