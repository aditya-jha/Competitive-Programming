#include<iostream>

using namespace std;

int main() {
    int t, c = 1;
    cin>>t;

    while(t) {
        int g = 0, n = 0, e;
        for(int i=0; i<t; i++) {
            cin>>e;
            if (e > 0) {
                g++;
            } else {
                n++;
            }
        }
        cout<<"Case "<<c<<": "<<g-n<<endl;
        c++;
        cin>>t;
    }

    return 0;
}