#include<iostream>
#include<cstdlib>
#include<string>

using namespace std;

int main() {
    int t, n;
    char c;

    cin>>t;

    while(t--) {
        cin>>n;
        int* X = new int[n];
        int* Y = new int[n];

        for (int i=0; i<n; i++) {
            cin>>X[i]>>Y[i];
        }

        bool isValid = true;

        for (int i=1; i<n; i++) {
            if (abs(X[i] - Y[i]) != abs(X[i-1] - Y[i-1])) {
                isValid = false;
            }
        }

        if (isValid) {
            cout<<"yes"<<endl;
        } else {
            cout<<"no"<<endl;
        }

        if(t > 0) {
            cout<<endl;
        }

        delete[] X;
        delete[] Y;
    }
    return 0;
}