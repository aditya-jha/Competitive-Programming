#include<iostream>
#include<string>

using namespace std;

int main() {
    string s;
    int t, a, sum=0;
    cin>>t;

    while(t--) {
        cin>>s;
        if (s == "donate") {
            cin>>a;
            sum += a;
        } else {
            cout<<sum<<endl;
        }
    }

    return 0;
}