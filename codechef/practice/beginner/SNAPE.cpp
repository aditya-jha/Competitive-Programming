#include<iostream>
#include<cmath>

#define abs(a) (a>0?a:a*-1)

using namespace std;

int main() {
    int t;
    cin>>t;

    while(t--) {
        double b,ls,rs;
        cin>>b>>ls;
        rs = b*b - ls*ls;
        cout<<sqrt(abs(rs))<<" ";
        cout<<sqrt(b*b + ls*ls)<<endl;
    }

    return 0;
}
