#include<iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);

    int t;
    cin>>t;

    while(t--) {
        long long n;
        cin>>n;

        long long sol = (((((n * 63) + 7492) * 5 ) - 498)/10) % 10;
        if (sol < 0) {
            sol *= -1;
        }
        cout<<sol<<endl;
    }

    return 0;
}