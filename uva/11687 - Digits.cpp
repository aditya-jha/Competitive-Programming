//
// Created by Aditya Jha on 2018-12-24.
//

#include<string>
#include<iostream>

using namespace std;

int main() {
    string s;

    while (true) {
        cin>>s;

        if (s == "END") {
            break;
        }

        if (s == "1") {
            cout<<"1"<<endl;
            continue;
        }

        unsigned long currLength = s.length();
        int count = 1;

        while (currLength != 1) {
            count++;
            currLength = to_string(currLength).length();
        }

        cout<<count + 1<<endl;
    }

    return 0;
}
