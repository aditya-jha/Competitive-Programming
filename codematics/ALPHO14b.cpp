#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

#define MOD 1000000007

vector<long long> v;

void solve() {
    long long i=1;
    for(int i=0;i<65;i++) {
        i *= 2;
        v.push_back(i);
    }    
}    

int main() {
    ios_base::sync_with_stdio(0);
    int t;
    cin>>t;
    
    while(t--) {
        long long int n,k;
        cin>>n>>k;
        
        cout<<(n+k-1)%MOD<<endl;
    } 
    
    return 0;   
}    
