#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;

vector<long long int> v,p;
long long int tt;

void sieve() {
	bool *primes = new bool[1000001];
	
	for(int i=2;i<1000001;i++) primes[i]=true;
	
	for(int i=2;i<1000001;i++) {
		if(primes[i]) {
			p.push_back(i);
			for(int j=2;i*j<1000001;j++) primes[i*j]=false;
		}
	}
	p.push_back(1000003);
	delete[] primes;
}

long long int power(int a,int b) {
	long long int val=1;
	for(int i=0;i<b;i++) {
		val*=a;
	}
	return val;
}



void getval() {
	long long int temp;
	tt=power(10,12);
	for(int i=0;i<p.size();i++) {
		for(int j=1;j<p.size();j++) {
			temp = power(p[i],p[j]-1);			
			if(temp>tt or temp<0) { break; }
			v.push_back(temp);
		}
	}
	
	//sort(v.begin(),v.end());

}

int main() {
	int t;
	long long int m,n,count,temp,j,val;
	sieve();
	getval();
	
	//for(int i=0;i<v.size();i++) cout<<v[i]<<endl;
	
	scanf("%d",&t);
	while(t--) {
		count=0;
		scanf("%lld %lld",&m,&n);
		//m=999999000000;n=1000000000000;
		if(n<1000001) {
			
			for(j=0;p[j]<m;j++);
			for(;p[j]<=n;j++) count++;
			
			for(int i=0;i<v.size();i++) if(v[i]>=m and v[i]<=n) count++;
			/*
			for(j=0;v[j]<m;j++);
			for(;v[j]<=n;j++) count++;
			*/
			printf("%lld\n",count);
			
		} else {
		
			//cout<<"else"<<endl;
			bool *primes = new bool[n-m+1];
			
			for(long long int i=0;i<(n-m+1);i++) primes[i]=true;
			
			temp = sqrt((double)n);

			for(long long int i=0;p[i]<=temp;i++ ) {
				//if(p[i]==1000003) break;
				j=m/p[i];
				val=p[i]*j;
				if(val<m) j++;
				val=p[i]*j;
				//cout<<p[i]<<" "<<j<<" "<<val<<endl;
				while(val<=n) { 
					primes[val-m]=false;                
					val+=p[i];
				}
			}
			
			for(long long int i=0;i<(n-m+1);i++) if(primes[i]) count++;//{ cout<<m+i<<endl;count++; }
			
			for(int i=0;i<v.size();i++) if(v[i]>=m and v[i]<=n) count++;
			/*
			for(j=0;v[j]<m and j<v.size();j++);
			for(;v[j]<=n and j<v.size();j++) count++;
			*/
			printf("%lld\n",count); 
			
			delete[] primes;
			
		}
	}
	//system("pause");
	return 0;
}

