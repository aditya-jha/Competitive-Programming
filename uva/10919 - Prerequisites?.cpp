#include<iostream>
#include<set>

using namespace std;

int main() {
    int k, m, c, count, req, val;
    
    while (1) {
        cin>>k;

        if (k == 0) {
            break;
        }

        cin>>m;

        set<int> s;

        while (k--) {
            cin>>c;
            s.insert(c);
        }

        bool passed = true;
        while(m--) {
            int selected = 0;
            cin>>count>>req;
            while (count--) {
                cin>>val;
                if (s.find(val) != s.end()) {
                    selected++;
                }
            }
            if (selected < req) {
                passed = false;
            }
        }

        if (passed) {
            cout<<"yes\n";
        } else {
            cout<<"no\n";
        }
    }

    return 0;
}