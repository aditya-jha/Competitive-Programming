#include<iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);

    int n, f;
    cin>>n;

    while(n--) {
        cin>>f;

        int a, b, c;
        long long sum = 0;
        while(f--) {
            cin>>a>>b>>c;
            sum += a*c;
        }

        cout<<sum<<endl;
    }

    return 0;
}