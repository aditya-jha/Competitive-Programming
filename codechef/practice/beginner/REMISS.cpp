#include<iostream>

using namespace std;

#define max(a,b) (a>b?a:b)

int main() {
    int t;
    cin>>t;

    while(t--) {
        int a,b;
        cin>>a>>b;

        cout<<max(a,b)<< " " <<a+b<<endl;
    }

    return 0;
}
