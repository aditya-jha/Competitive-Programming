#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>

using namespace std;

int main() {
    int a,b,c,n,m;
    int give[102],get[102];
    long long int sum=0;
    cin>>n>>m;
    
    memset(give,0,sizeof(give));
    memset(get,0,sizeof(get));
    
    while(m--) {
        cin>>a>>b>>c;
        give[a]+=c;
        get[b]+=c;
    }
    
    for(int i=1;i<=n;i++) {
        if(get[i]>=give[i]) {
            get[i] = get[i]-give[i];
            sum += get[i];
        }
    }
    
    cout<<sum<<endl;
    
    return 0;
}

