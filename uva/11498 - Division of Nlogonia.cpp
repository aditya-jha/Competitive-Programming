#include<iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);

    int k;
    cin>>k;

    while(k) {
        int dx, dy, x, y;
        cin>>dx>>dy;

        for(int i=0; i<k; i++) {
            cin>>x>>y;

            if (x > dx && y > dy) {
                cout<<"NE\n";
            } else if (x > dx && y < dy) {
                cout<<"SE\n";
            } else if (x < dx && y < dy) {
                cout<<"SO\n";
            } else if (x < dx && y > dy) {
                cout<<"NO\n";
            } else {
                cout<<"divisa\n";
            }
        }
        cin>>k;
    }

    return 0;
}
