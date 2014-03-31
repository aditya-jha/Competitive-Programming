#include<iostream>
#include<algorithm>
using namespace std;

int main() {
    int a,b,s,t;
    cin>>a>>b;
    
    if(a<b) swap(a,b);
    
    t = a-b;
    s = t/10;
    t = t%10;
    
    if(s!=0) cout<<s;
    if(t!=9) cout<<t+1<<endl;
    else cout<<t-1<<endl;
    
    return 0;
}    
