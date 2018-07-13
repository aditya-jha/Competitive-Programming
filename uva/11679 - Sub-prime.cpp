#include<iostream>

using namespace std;

int main() {
    int b, n, d, c, a;
    cin>>b>>n;

    while(b>0 && n>0) {
        int* reserves = new int[b+1];

        for (int i=1; i<=b; i++) {
            cin>>reserves[i];
        }

        for (int i=0;i<n;i++) {
            cin>>d>>c>>a;
            reserves[d] -= a;
            reserves[c] += a;
        }

        char sol = 'S';
        for (int i=1;i<=b; i++) {
            if (reserves[i] < 0) {
                sol = 'N';
                break;
            }
        }

        cout<<sol<<endl;

        cin>>b>>n;
    }

    return 0;
}