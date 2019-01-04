#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main() {
    string s;
    int _case = 1;

    while(cin>>s) {
        int n, a, b, start, end;
        cin>>n;
        
        cout<<"Case "<<_case<<":"<<endl;
        while(n--) {
            cin>>a>>b;

            start = min(a, b);
            end = max(a, b);

            bool same = true;
            for (int i=start+1; i<=end; i++) {
                if (s[i] != s[i-1]) {
                    same = false;
                    break;
                }
            }

            if (same) {
                cout<<"Yes\n";
            } else {
                cout<<"No\n";
            }
        }
    }
}