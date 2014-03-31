#include<cstdio>
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

bool primes[20000000];
vector<int> pp;
bool isPrime(int n) {
        
    int lim=(int)sqrt(n*1.0);
    for(int i=0;pp[i]<=lim;i++) {
        if(n%pp[i]==0) return false;
    }    
    return true;
}    



void seive() {
    
    for(int i=0;i<20000000;i++) primes[i]=true;
	primes[0]=primes[1]=false;

	for(int i=2;i<20000000;i++) {
		if(primes[i]) {
			pp.push_back(i);
			for(int j=i+i;j<20000000;j+=i) primes[j]=false;
		}
	}		
}    

int reverse(int n) {
    int val=0;
    while(n!=0) {
        val = val*10 + n%10;
        n=n/10;
    }    
    return val;
}   

 
void print_d(int n) {
	int i=10;
	char output_buffer[11];output_buffer[10]='\n';
	
	do {
		output_buffer[--i]=(n%10)+'0';
		n/=10;
	} while(n);
	
	do {
		putchar_unlocked(output_buffer[i]);
	} while(++i<11);
} 

int main() {
    
    int num;

    seive();
    
    for(int i=13;i<20000000;i++) {
        if(primes[i]==true) {
            num = reverse(i);
            
            if(num!=i) {
                if(num<20000000) {
                    if(primes[num]==true) {
                        print_d(num);
                        if(num>i) primes[num]=false;
                    }    
                }
                else {
                    if(isPrime(num)) print_d(num);
                }    
            } 
        }    
    }  
    return 0;  
}    
