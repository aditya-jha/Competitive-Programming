#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main() {
    int n,m,c,t;
    vector<string> v;

    while(1) {
        cin>>n;
        cin>>m;
        cin>>c;

        if (n == 0 && m == 0 && c == 0) {
            break;
        }

        int consumed = 0, max_consumed = 0;

        int* a = new int[n];
        int* d = new int[m];
        bool* b = new bool[n];
        
        for (int i=0; i<n; i++) {
            cin>>a[i];
            b[i] = false;
        }

        for (int i=0; i<m; i++) {
            cin>>d[i];
        }
    
        bool fused = false;
        for (int i=0; i<m; i++) {
            t = d[i]-1;
            b[t] = !b[t];

            if (b[t]) {
                consumed += a[t];
            } else {
                consumed -= a[t];
            }
            max_consumed = max(max_consumed, consumed);

            if (consumed > c) {
                fused = true;
                break;
            }
        }

        if (!fused) {
            string output = "Fuse was not blown.\nMaximal power consumption was " + to_string(max_consumed) + " amperes.";
            v.push_back(output);
        } else {
            string output = "Fuse was blown.";
            v.push_back(output);
        }

        delete[] a;
        delete[] b;
        delete[] d;
    }

    if (v.size() > 0) {
        for (int i=0; i<v.size(); i++) {
	    cout<<"Sequence "<<i+1<<endl;
            cout<<v[i]<<endl<<endl;
        }
        // cout<<"Sequence "<<v.size()<<endl;
        // cout<<v[v.size() - 1];
    }

    return 0;
}