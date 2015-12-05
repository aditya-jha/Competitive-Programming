/*
*   This solution is wrong
*   merge sort inversion counting technique has to be used
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);

    int t,n;
    cin>>t;

    while(t--) {
        cin>>n;

        int a[n];
        vector<pair<int,int> > v;
        v.clear();

        for(int i=0;i<n;i++) {
            cin>>a[i];
            v.push(make_pair(a[i],i));
        }

        int sol[n];
        sort(v.begin(), v.end());
        sol[v[0].second] = 0;
        for(int i=1;i<n;i++) {
            int s = 0;
            for(int j=0;j>=0;j--) {
                if(v[j].first < v[i].first && v[j].second > v[i].second) {
                    s = sol[v[j].second] + 1;
                    break;
                }
                sol[v[i].second] = s;
            }
        }
        for(int i=0;i<n;i++) cout<<sol[i]<<" ";
        cout<<endl;
    }
    return 0;
}
