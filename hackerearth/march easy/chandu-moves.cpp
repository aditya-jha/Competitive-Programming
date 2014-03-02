#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

#define llu long long unsigned
#define abs(a) (a<0?-a:a)
#define min(a,b) (a<b?a:b)

vector<llu> v;

llu solve(int a, int b, int n) {
    v.clear();
    //cout<<a<<" " <<b<<endl;
    v.push_back(abs(a-1)+abs(b-1));
    v.push_back(abs(a-1)+abs(n-b));
    v.push_back(abs(n-a)+abs(n-b));
    v.push_back(abs(n-a)+abs(b-1));
    
    //for(int i=0;i<4;i++) cout<<v[i]<<" ";
    //cout<<endl;
    
    llu minim = v[0];
    for(int i=1;i<4;i++) minim = min(v[i],minim);
    
    return minim;
}    

int main() {
    ios_base::sync_with_stdio(0);
    
    int n,k;
    cin>>n>>k;
    
    int *x = new int[k];
    int *y = new int[k];
    
    for(int i=0;i<k;i++) cin>>x[i];
    for(int i=0;i<k;i++) cin>>y[i];
    
    llu moves = 0;
    for(int i=0;i<k;i++) {
        moves += solve(x[i],y[i],n);
    }    
    
    
    cout<<moves<<'\n';
    
    delete[] x,y;
    
    return 0;
}    
