#include<iostream>
#include<cstdio>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);

    int t,n;
    cin>>t;

    while(t--) {
        cin>>n;
        cout<<n/2 + 1<<endl;
    }

    return 0;
}
