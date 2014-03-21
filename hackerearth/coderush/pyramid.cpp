#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int scan_d() {
	int ip=getchar_unlocked(),ret=0;
	for(;ip<'0'||ip>'9';ip=getchar_unlocked());
	for(;ip>='0'&&ip<='9';ip=getchar_unlocked())
		ret=ret*10+ip-'0';

	return ret;
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
    
    vector<int> v;
    vector<int> pp;
    int t;
    
    t = scan_d();
    
    while(t--) {
        v.clear();
        pp.clear();
               
        int n,p,r;
        n  = scan_d();
        p  = scan_d();
        
        int count=0;
    
        for(int i=0;i<n;i++) {
            r  = scan_d();
            v.push_back(r);
        }    
        
        sort(v.begin(),v.end());
        
        int index=0;
        
        int counter=1;
        for(int i=1;i<n;i++) {
            if(v[i] == v[i-1]) counter++;
            else {
                pp.push_back(counter);
                counter=1;
            }    
        }    
        
        sort(pp.begin(), pp.end());
        
        counter=0;
        for(int i=0;i<=(pp.size()-p);i++) {
            if(pp[i]>0) {
                counter += pp[i];
                int j=i,temp=0,val=pp[i];
                while(temp<p) {
                    temp++;
                    pp[j]-=val;
                    j++;
                }    
            }    
        }     
        
        print_d(counter);
        //cout<<index<<endl;
    }    
    return 0;
}    
