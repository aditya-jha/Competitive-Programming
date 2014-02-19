#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<string>

using namespace std;

#define node pair<int, int>
#define max(a,b) (a>b?a:b)

int k,n,m,sum;   
vector<int> v;//(1001, make_pair(0,0));
int a[1001], b[1001][1001], c[1001][1001];

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

void read() {
    sum = 0;
    
    //cin>>n>>m>>k;
    n = scan_d();
    m = scan_d();
    k = scan_d();
    
    for(int i=1;i<=n;i++) a[i] = scan_d(); //cin>>a[i];
    
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            b[i][j] = scan_d();
            //cin>>b[i][j];
        }    
    }    
    
    for(int i=1;i<=n;i++) {
        sum += b[i][a[i]];
        for(int j=1;j<=m;j++) c[i][j] = scan_d(); //cin>>c[i][j];
    }
}     

bool myfunction (int i,int j) { return (i>j); } 

int main() {
    ios_base::sync_with_stdio(0);
    
    int t,max_index;
    //cin>>t;
    t = scan_d();
    
    while(t--) {
        sum = 0;
        v.clear();
        read();
        
        for(int i=1;i<=n;i++) {
            max_index = a[i];
            int val = b[i][max_index];
            
            for(int j=1;j<=m;j++) {
                if(b[i][j]-c[i][j] > val) {
                    val = b[i][j] - c[i][j];
                    max_index = j;
                }    
            }    
            if( max_index != a[i] ) {
                v.push_back(b[i][max_index] - c[i][max_index] - b[i][a[i]]);
            }    
        }    
        
        sort(v.begin(), v.end(), myfunction);
        
        //for(int i=v.size()-k; i<v.size();i++) {
        for(int i=0; i<v.size() && i<k;i++) {
            sum += v[i];
        }    
                
        //cout<<sum<<'\n';
        print_d(sum);
    }    
    
    return 0;
}    
