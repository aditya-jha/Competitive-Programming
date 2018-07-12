#include<iostream>
#include<algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);

    int t, n, sum;
    cin>>t;

    while(t--) {
        cin>>n;

        int *slots = new int[n];
        for (int i=0; i<n; i++) {
            cin>>slots[i];
        }

        sort(slots, slots + n);

        sum=0;
        for (int i=1; i<n; i++) {
            sum += (slots[i] - slots[i-1]);
        }

        if (n > 1) {
            sum += (slots[n-1] - slots[0]);
        }

        cout<<sum<<endl;

        delete[] slots;
    }

    return 0;
}