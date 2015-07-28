#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);

    vector<int> v;
    v.push_back(1);

    int x = 2, i=0;
    while(v[i]<2048) {
        v.push_back(x*v[i]);
        i++;
    }
    
    int t;
    cin>>t;

    while(t--) {
        int p;
        cin>>p;

        int sol=0;
        for(i=v.size()-1;i>=0;i--) {
            if(v[i] > p) continue;
            else break;
        }

        while(p > 0) {
            sol += p/v[i];
            p = p%v[i];

            for(i--;i>=0;i--) {
                if(v[i] > p) continue;
                else break;
            }
        }

        cout<<sol<<endl;
    }

    return 0;
}
