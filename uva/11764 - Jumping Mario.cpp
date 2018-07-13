#include<iostream>

using namespace std;

int main() {
    int t, n, _case = 1;

    cin>>t;

    while(t--) {
        cin>>n;
        int* walls = new int[n];
        
        for(int i=0; i<n;i++) {
            cin>>walls[i];
        }

        int high = 0, low = 0;
        for (int i=1; i<n; i++) {
            if (walls[i] > walls[i-1]) {
                high++;
            } else if (walls[i] < walls[i-1]) {
                low++;
            }
        }

        cout<<"Case "<<_case<<": "<<high<<" "<<low<<endl;
        _case++;
        
        delete[] walls;
    }

    return 0;
}