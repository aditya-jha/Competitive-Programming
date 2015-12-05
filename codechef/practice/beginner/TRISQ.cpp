#include<iostream>

using namespace std;

int a[10001];

int main() {
    ios_base::sync_with_stdio(0);

    a[0] = a[1] = a[2] = a[3] = 0;
    for(int i=4;i<10001;i++) {
        a[i] = i/2 - 1;
        a[i] += a[i-2];
    }

    int t;
    cin>>t;

    while(t--) {
        int b;
        cin>>b;
        cout<<a[b]<<endl;
    }

    return 0;
}
