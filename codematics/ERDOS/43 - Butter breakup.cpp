#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<vector>
#include<string>
using namespace std;


vector<int> pp;
long long counter = 0;
long long start = 8589934592LL, end = 17179869184LL;

void sieve() {
	bool *primes = new bool[1000001];
	for(int i=0;i<1000001;i++) primes[i]=true;
	primes[0]=primes[1]=false;
	
	for(int i=2;i<1000001;i++) {
		if(primes[i]) {
			pp.push_back(i);
			for(int j=i+i;j<1000001;j+=i) primes[j]=false;
		}
	}	
	pp.push_back(10000000);
	delete[] primes;
}

int a[1000000];

void factors(int n) {
    for(int i=0;i<pp.size() and pp[i]<=n;i++) {
        while(n%pp[i]==0 and n>=pp[i]) {
            a[pp[i]]++;
            n = n/pp[i];
        }    
    }    
    
}    

int main() {
    string s = "4113101149215104800030529537915953170486139623539759933135949994882770404074832568499";
    cout<<s.length()<<endl;
    int len = s.length();
    
    for(int i=0;i<s.length();i++) {
        if(s[i] == '1' and 
    }    
    
    
    getchar();
    
    return 0;
}    
