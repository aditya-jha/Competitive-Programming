#include<iostream>
#include<cstdio>

template<typename type> inline type scan(type i) {
	type ip = getchar_unlocked(), ret=0;
	for(;ip<'0'||ip>'9';ip=getchar_unlocked());
	for(;ip>='0' && ip<='9'; ip=getchar_unlocked()) ret = ret*10+ip-'0';
	return ret;
}

template<typename type> inline void print(type n) {
	int i=21;
	char output_buffer[22];
	output_buffer[21]='\n';
	do { output_buffer[--i]=(n%10)+'0'; n/=10; } while(n);
	do { putchar_unlocked(output_buffer[i]); } while(++i<22);
}

int main() {
	int t,n,temp;
    t = scan(t);
    
    while(t--) {
        int con = 0,con2 = 0;

        n = scan(n);
        
        for(int i=0;i<n;i++) {
            temp = scan(temp);
            if(temp>1) {
                con++;
                if(temp == 2) con2++;
            }    
        }
        
        long long sol = con, sol2 = con2;
        sol = (sol*(sol-1))/2;
        sol2 = (sol2*(sol2-1))/2;
        
        sol = sol-sol2;
        print(sol);
    }   
    
    return 0; 
}    
