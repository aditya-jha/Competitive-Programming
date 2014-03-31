#include<cstdio>
#include<iostream>
#include<vector>

using namespace std;

bool primes[100000000];
vector<int> pp;

bool isPrime(int n) {
        
    int lim=(int)sqrt(n);
    for(int i=0;pp[i]<=lim;i++) {
        if(n%pp[i]==0) return false;
    }    
    return true;
}    



void seive() {
    for(int i=0;i<100000000;i++) primes[i]=true;
	primes[0]=primes[1]=false;
	
	for(int i=2;i<100000000;i++) {
		if(primes[i]) {
			pp.push_back(i);
			for(int j=i+i;j<100000000;j+=i) primes[j]=false;
		}
	}		
}    

int reverse(int n) {
    int t=n, val=0;
    while(t) {
        val = val*10 + n%10;
        n=n/10;
    }    
    cout<<val<<endl;
    return val;
}    

int main() {
    int num;
    for(int i=13;i<100000000;i++) {
        if(primes[i]) {
            num = reverse(i);
            if(num!=i) {
                if(num<100000000) {
                    if(primes[num]) {
                        //print_d(num);
                        cout<<num<<endl;
                    }    
                } else if(isPrime(num)) {
                    //print_d(num);
                    cout<<num<<endl;
                }
            } 
        }    
    }  
    return 0;  
}    
