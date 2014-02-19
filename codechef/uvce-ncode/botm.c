#include<stdio.h>

#define abs(a) (a>-1?a:-a)
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

void print_ld(ld n) {
	int i=11;
	char output_buffer[12];output_buffer[11]='\n';
	
	do {
		output_buffer[--i]=(n%10)+'0';
		n/=10;
	} while(n);
	
	do {
		putchar_unlocked(output_buffer[i]);
	} while(++i<12);
}

int main() {
    int t;
    t = scan_d();
    //scanf("%d",&t);   
    while(t--) {
        long int n,i;
        n = scan_ld();
        //scanf("%ld",&n);           
        long int a[n];
        for(i=0;i<n;i++) {
            a[i] = scan_ld();
            //scanf("%ld",&a[i]);
            //sum += a[i];
        }
        long int mid = a[n/2], count=0, temp;
        //printf("mid: %ld\n",mid);
        for(i=0;i<n;i++) {
            temp = mid - a[i];
            count += abs(temp);
            //printf("%ld\n",abs(temp));
        } 
            
        print_ld(count);
        //printf("%ld\n",count);
        
    }   
    //system("pause");
    return 0; 
}    
