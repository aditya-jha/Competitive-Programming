//
// Created by Aditya Jha on 08/11/17.
//

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main() {
    int t;
    char c;

    cin>>t;
    c = getchar();

    while (t--) {
        c = getchar();
        int count = 0;
        while (c != '\n' && c != '\0') {
            if (c == '4') {
                count++;
            }
            c = getchar();
        }
        cout<<count<<endl;
    }

    return 0;
}