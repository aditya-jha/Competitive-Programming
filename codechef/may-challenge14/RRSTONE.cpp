#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<climits>
     
using namespace std;

#define getcx getchar_unlocked
#ifndef ONLINE_JUDGE
	#define getcx getchar
#endif

#define lld long long

int n,k;
long long minval = LLONG_MAX, maxval = LLONG_MIN, nmax;
long long a[100001], b[100001], c[100001];
     
inline long long in( )//fst input function
{
	long long n=0;
	int ch=getcx();int sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();}
 
	while( ch >= '0' && ch <= '9' )
	n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
	
	return n*sign;
}

void print(long long p[]) {
    for(int i=0;i<n;i++) printf("%lld ",p[i]);
}
    
int main() {
    scanf("%d %d",&n,&k);
     
    for(int i=0;i<n;i++) {
        a[i] = in();
        if(a[i] < minval) minval = a[i];
        if(a[i] > maxval) maxval = a[i];
    }
         
    if(k==0) print(a);
    else {
        
        for(int i=0;i<n;i++) b[i] = maxval - a[i];
        nmax = maxval - minval;
        for(int i=0;i<n;i++) c[i] = nmax - b[i];
        
        int j=0;
        if(maxval == nmax and minval == 0) {
            k = k%2;
            if(k==0) print(a);
            else print(b);
        }
        else {
            k--;
            k = k%2;
            if(k==0) print(b);
            else print(c);
        }
    }
    return 0;
} 
