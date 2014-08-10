#include<iostream>
#include<cstdio>
#include<vector>
#include<cstdlib>
#include<vector>
#include<cstring>
#include<string>

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

int n,m;
int table[201], a[401];

int solve(int index) {
    vector<pair<int, int> > v;
    
    for(int i=0;i<n;i++) {
        int present = -1;
        for(int j=index+1;j<m;j++) {
            if(table[i] == a[j]) {
                v.push_back(make_pair(i,j));
                present = i;
                break;
            }    
        }    
        if(present == -1) {
            v.clear();
            return i;
        }    
    }    
    
    int max = -1, ret=-1;
    for(int i=0;i<v.size();i++) {
        if(v[i].second > max) {
            max = v[i].second;
            ret = v[i].first;
        }
    }    
    
    v.clear();
    
    return ret;
}    

int main() {
    ios_base::sync_with_stdio(0);
    
    int t;
    t = scan_d();
    
    while(t--) {
        n = scan_d(); m = scan_d();
        
        for(int i=0;i<n;i++) table[i] = -1;
        
        for(int i=0;i<m;i++) a[i] = scan_d();;
        
        int seats = 0, sol = 0;
        for(int i=0;i<m;i++) {
            bool present = false;
            
            for(int j=0;j<seats;j++) {
                if(table[j] == a[i]) {
                    present = true;
                    break;
                }    
            }
            
            if(!present) {
                if(seats<n) {
                    table[seats++] = a[i];
                    sol++;
                }    
                else {
                    table[solve(i)] = a[i];
                    sol++;
                }    
            }        
        }    
        
        print_d(sol);
    }   
    return 0; 
}    
