#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main() {
    string s,p;
    cin>>s;
    p = s;

    int l,r,k,t;
    cin>>t;

    while(t--) {
        cin>>l>>r>>k;

        l = l-1;
        r = r-1;
        
        int newL = r-l+1;

        for(int i=0; i<newL; i++) {
            p[l+(i+k)%newL] = s[l+i];
            //p[l+i] = s[(l + i + (i+k)%newL)%newL];
        }
        s = p;
        //cout<<s<<endl;
    }

    cout<<s<<endl;

    return 0;
}
