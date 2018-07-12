#include<iostream>
#include<string>

using namespace std;

int main() {
    string s;
    int i = 1;
    cin>>s;

    while(s != "*") {
        if (s == "Hajj") {
            cout<<"Case "<<i<<": Hajj-e-Akbar\n";
        } else if (s == "Umrah") {
            cout<<"Case "<<i<<": Hajj-e-Asghar\n";
        }

        i++;
        cin>>s;
    }

    return 0;
}
