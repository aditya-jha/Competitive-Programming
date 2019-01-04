#include<iostream>

using namespace std;

int main() {
    double h, u, d, f, u1, u2, t;

    while(1) {
        cin>>h>>u>>d>>f;

        if (h == 0) {
            break;
        }

        f = f/100;
        u1 = u;
        u2 = f*u;
        t = 0;

        for (int i = 1; ; i++) {
            if (i>1) {
                u1 -= u2;
            }
            if (u1 > 0) {
                t += u1;
            }
            if (t>h) {
                cout<<"success on day "<<i<<endl;
                break;
            }
            
            t -= d;

            if (t < 0) {
                cout<<"failure on day "<<i<<endl;
                break;
            }
        }
    }

    return 0;
}