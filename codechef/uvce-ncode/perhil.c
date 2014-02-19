// Program to print all prime factors
# include <stdio.h>
# include <math.h>
inline void fastRead(int *a)
{
register char c=0;
while (c<33) c=getchar_unlocked();
*a=0;
while (c>33)
{
*a=*a*10+c-'0';
c=getchar_unlocked();
}
}
// A function to print all prime factors of a given number n
void primeFactors(int n)
{
register int i;
register float temp=sqrt(n);
while (n%2 == 0)
{
n = n/2;
}
while (n%3 == 0)
{
n = n/3;
}
for (i = 5; i <= temp; i = i+2)
{
if((i-1)%4==0&&n%i==0)
{
printf("PERFECT\n");
return;
}
else
{
while (n%i == 0)
{
n = n/i;
}
}
}
if(n>2&&(n-1)%4==0)
{
printf("PERFECT\n");
return;
}
printf("IMPERFECT\n");
return;
// This condition is to handle the case whien n is a prime number
// greater than 2
}
int main()
{
int t;
scanf("%d",&t);
getchar();
while(t--)
{
int n;
fastRead(&n);
primeFactors(n);
}
return 0;
}

/*

#include<stdio.h>
#include<stdlib.h>

 
#define MOD 1000000007
#define llu long long unsigned
#define lld long long
#define ld long

long int arr[1000000];

long int gcd(long int a, long int b) {
	if(b==0) return a;
	else return gcd(b,a%b);
}

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
	long int i=1,j=2,k;
	long int sq = i*i + j*j,ss=sq,p=2;
	for(k=2;k<1000;) {
		ss = sq; p=2;
		if(arr[ss]!=1) {
			while(ss<=1000000) {
				arr[ss]=1;//v.push_back(sq);
				ss = sq*p;
				p++;
			}
		}
		k++;
		sq = 1+ k*k;
		
	}
		i=2; j=3; sq = i*i + j*j;
	while(sq<=1000000) {
		while(sq<=1000000) {
			if(arr[sq]!=1) {
				if(gcd(j,i) ==1 ) {
					ss = sq;p=2;
					while(ss<=1000000) {
						arr[ss]=1;
						ss = sq*p;
						p++;
					}	
				}
					
			}
			j++;
			sq = i*i + j*j;
		}
		i++;
		j= i+1;
		sq = i*i + j*j;
	}
	
	int t;
	t = scan_d();
	while(t--) {
		
		sq = scan_ld();
		
		if(arr[sq]>0) {
			putchar_unlocked('P');putchar_unlocked('E');putchar_unlocked('R');putchar_unlocked('F');putchar_unlocked('E');
			putchar_unlocked('C');putchar_unlocked('T');putchar_unlocked('\n');
		}	
		else {
			putchar_unlocked('I');putchar_unlocked('M');putchar_unlocked('P');putchar_unlocked('E');
			putchar_unlocked('R');putchar_unlocked('F');putchar_unlocked('E');
			putchar_unlocked('C');putchar_unlocked('T');putchar_unlocked('\n');
		}	
	}
	return 0;
}
*/
