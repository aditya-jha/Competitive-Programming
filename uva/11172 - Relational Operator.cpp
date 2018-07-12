#include<iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);

    int t;
    cin>>t;

    while(t--) {
        long long int a, b;
        cin>>a>>b;

        if (a < b) {
            cout<<"<\n";
        } else if (a == b) {
            cout<<"=\n";
        } else {
            cout<<">\n";
        }
    }

    return 0;
}
