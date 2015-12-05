#include<iostream>

using namespace std;

int gcd(int a, int b) {
    if(b == 0) return a;
    return gcd(b,a%b);
}

int solve(int *a, int n) {
    int sol = gcd(a[0], a[1]);

    for(int i=2;i<n;i++) sol = gcd(a[i], sol);

    return sol;
}

int main() {
    ios_base::sync_with_stdio(0);

    int t;
    cin>>t;

    while(t--) {
        int n;
        cin>>n;

        int a[n];
        for(int i=0;i<n;i++) cin>>a[i];

        int g = solve(a,n);

        for(int i=0;i<n;i++) cout<<a[i]/g<<" ";
        cout<<endl;
    }
    return 0;
}
