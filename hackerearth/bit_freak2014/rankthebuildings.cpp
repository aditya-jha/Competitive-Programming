#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int> > v(1000001, vector<int>());
vector<vector<int> > w(1000001, vector<int>());

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

int findRank(int p, int ind) {
    int counter=0;
    for(int i=1;i<p;i++) {
        for(int j=0;j<v[i].size();j++) {
            if(v[i][j]<ind) counter++;
        }    
    }    
    return counter;
} 

int findRankAgain(int p, int ind) {
    int counter=0;
    for(int i=1;i<p;i++) {
        for(int j=0;j<w[i].size();j++) {
            if(w[i][j]<ind) counter++;
        }    
    }    
    return counter;
}   

int main() {
    
    int n, rankA =0, rankB=0;
    n = scan_d();
    
    int *a = new int[n+1];
    for(int i=1;i<=n;i++) {
        a[i] = scan_d();
        v[a[i]].push_back(i);
    }   
    
    //for(int i=0;i<1000001;i++) sort(v[i].begin(), v[i].end());
    
    for(int i=2;i<=n;i++) {
        rankA += findRank(a[i], i);
    }
       
    for(int i=1;i<=n;i++) {
        //cin>>a[i];
        a[i] = scan_d();
        w[a[i]].push_back(i);
    }   
    //for(int i=0;i<1000001;i++) sort(w[i].begin(), w[i].end());
    for(int i=2;i<=n;i++) {
        rankB += findRankAgain(a[i], i);
    }        
   
    if(rankA>rankB) {
        //cout<<"Upendra "<<rankA<<endl;
        putchar('U');putchar('p');putchar('e');putchar('n');putchar('d');putchar('r');putchar('a');putchar(' ');
        print_d(rankA);
    }        
    else {
        //cout<<"Ujjaval "<<rankB<<endl;
        putchar('U');putchar('j');putchar('j');putchar('a');putchar('v');putchar('a');putchar('l');putchar(' ');
        print_d(rankB);
    }    
    
    delete[] a;
    return 0;
}    
