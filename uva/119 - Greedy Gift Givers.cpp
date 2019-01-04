#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main() {
    int t;
    vector<string> output;

    while(cin>>t) {
        string sol="";
        string names[t];
        int gives[t];
        int receives[t];

        for (int i=0; i<t; i++) {
            cin>>names[i];
            gives[i] = 0;
            receives[i] = 0;
        }

        string p, s;
        int amount;
        int n;
        for (int i=0; i<t; i++) {
            cin>>p>>amount>>n;
            int value = 0;

            if (n>0 && amount > 0) {
                value = amount/n;
            }
            for (int j=0; j<n; j++) {
                cin>>s;
                for (int k=0;k<t;k++) {
                    if (names[k] == s) {
                        receives[k] += value;
                        break;
                    }
                }
            }

            if (n>0 && amount > 0) {
                for (int k=0;k<t;k++) {
                    if (names[k] == p) {
                        gives[k] += (value*n);
                        break;
                    }
                }
            }
        }

        for (int i=0; i<t;i++) {
            sol += names[i] + " " + to_string(receives[i] - gives[i]) + "\n";
        }
        output.push_back(sol);
    }

    for (int i=0; i<output.size() - 1; i++) {
        cout<<output[i];
        cout<<endl;
    }

    cout<<output[output.size() -1]<<endl;
    return 0;
}