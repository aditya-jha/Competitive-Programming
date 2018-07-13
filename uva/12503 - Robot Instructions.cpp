#include<iostream>
#include<string>
#include <cstdlib>

using namespace std;

int main() {
    int t,n;
    string s;
    cin>>t;

    while(t--) {
        cin>>n;

        int* a = new int[n];
        int pos = 0;
        for (int i=0; i<n;i++) {
            cin>>s;
            if (s[0] == 'L') {
                a[i] = -1;
            } else if (s[0] == 'R') {
                a[i] = 1;
            } else {
                string c;
                int ii;
                cin>>c>>ii;
                a[i] = a[ii-1];
            }

            pos += a[i];
        }

        cout<<pos<<endl;
    }

    return 0;
}