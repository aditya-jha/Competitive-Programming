#include<iostream>
#include<string>

using namespace std;

int main() {
    int t;
    cin>>t;

    while(t--) {
        int n;
        cin>>n;

        string s;
        cin>>s;

        bool I=false, Y=false;
        for(int i=0;i<n;i++) {
            if(s[i] == 'I') {
                I = true;
                break;
            }
            else if(s[i] == 'Y') {
                Y = true;
                break;
            }
        }

        if(I) cout<<"INDIAN\n";
        else if(Y) cout<<"NOT INDIAN\n";
        else cout<<"NOT SURE\n";
    }
    return 0;
}
