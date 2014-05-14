#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

#define node pair<int,int>

vector<vector<int> > v(100010, vector<int> ());
vector<node> freq;
int n,m,p,x,y;

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

void print_lld(lld n) {
	int i=21;
	char output_buffer[22];
	output_buffer[21]='\n';
	
	do { 
		output_buffer[--i]=(n%10)+'0';
		n/=10;
	} while(n);
	
	do {
		putchar_unlocked(output_buffer[i]);
	} while(++i<22);
}

void getCount(int index) {
    freq.clear();
    
    int i=0, con=1;
    
    while(i<v[index].size()) {
        freq.push_back(make_pair(v[index][i],0));
        i++;
        con=1;
        
        while(i<v[index].size()) {
            if(v[index][i] == v[index][i-1]) con++;    
            else break;
            i++;
        }    
        
        freq[freq.size()-1].second = con;
    }    
}    

bool check(int m) {
    int len = freq.size()-1;
    for(int i=len;i>-1;i--) {
        if(freq[i].first == m) continue;
        if(i != len) {
            if(freq[i+1].first == freq[i].first + 1) {
                int diff = freq[i+1].second + 1 - freq[i].second;
                if(diff < 0) return false;
            }
            else {
                int diff = freq[i].second;
                if(diff > 1) return false;
            }        
        }    
        else {
            int diff = freq[i].second;
            if(diff > 1) return false;
        }    
    }    
    return true;
}    

void solve(int m) {
    long long sol = m-1;
    
    if(freq[0].first == 1) sol -= freq[0].second;
    if(freq[freq.size()-1].first == m) sol += freq[freq.size()-1].second;
    
    if(check(m) == false) {
        putchar_unlocked('-');
        putchar_unlocked('1');
        putchar_unlocked('\n');
    }    
    else print_lld(sol);
}    

void read() {
    n = scan_d();
    m = scan_d();
    p = scan_d();
   
    
    while(p--) {
        x = scan_d();
        y = scan_d();
        v[x].push_back(y);
    }   
}    

int main() {    
    read();
    
    for(int i=1;i<=n;i++) {
        if(v[i].size() == 0) print_d(m-1);
        else {
            sort(v[i].begin(), v[i].end());
            
            getCount(i);
                        
            if(m==1) {
                putchar_unlocked('0');
                putchar_unlocked('\n');
            }    
            else solve(m);
        }    
    }    
    
    return 0;
}    
