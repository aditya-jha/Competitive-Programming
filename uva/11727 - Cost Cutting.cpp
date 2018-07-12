#include<iostream>
#include<algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);

    int t;
    cin>>t;

    for (int j=0; j<t; j++) {
        int* a = new int[3];
        for(int i=0; i<3; i++) {
            cin>>a[i];
        }

        sort(a, a+3);

        cout<<"Case ";
        cout<<(j+1);
        cout<<": ";
        cout<<a[1]<<endl;
    }

    return 0;
}