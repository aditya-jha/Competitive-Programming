#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<cstring>
#include<algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	
	string s;
	cin>>s;
	
	int len = s.length();
	int pivot,i;
	int a[len+1];
	//memset(a,0,sizeof(a));
	
	for(i=0;i<len;i++) {
		if(s[i]=='^') { pivot = i; break; }
		else if((int)s[i]>48 and (int)s[i]<58) a[i] = (int)s[i]-48
		else if(s[i]=='=') a[i]=0;
	}
	a[i]=0;
	i++;
	for(;i<len;i++) {
		if((int)s[i]>48 and (int)s[i]<58)  a[i] = (int)s[i]-48
		else a[i]=0;
	}
	//for(int j=0;j<len;j++) cout<<a[j]<<" ";
	unsigned long long int left=0,right=0;
	
	for(i=0;i<pivot;i++) {
		left+=(a[i]*(pivot-i));
	}
	for(i=pivot+1;i<len;i++) right+=((long long int)a[i]*(long long int)(i-pivot));
	
	if(left==right) cout<<"balance\n";
	else if(left<right) cout<<"right\n";
	else cout<<"left\n";
	
	delete[] a;
	
	return 0;
}
