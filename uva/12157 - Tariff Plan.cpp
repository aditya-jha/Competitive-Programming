#include<iostream>
#include<cmath>

using namespace std;

int main() {
    int t;
    cin>>t;

    for(int i=1; i<=t; i++) {
        int n;
        cin>>n;

        int m = 0, j = 0;
        double k;
        while(n--) {
            cin>>k;
            m += (ceil(k/30) * 10);
            j += (ceil(k/60) * 15);

            if (int(k)%30 == 0) {
                m += 10;
            }
            if (int(k)%60 == 0) {
                j += 15;
            }
        }

        cout<<"Case "<<i<<": ";
        if (m < j) {
            cout<<"Mile "<<m<<endl;
        } else if (j < m) {
            cout<<"Juice "<<j<<endl;
        } else {
            cout<<"Mile Juice "<<m<<endl;
        }
    }
}