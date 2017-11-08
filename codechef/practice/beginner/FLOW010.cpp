//
// Created by Aditya Jha on 08/11/17.
//

#include <iostream>
#include <string>

using namespace std;

int main() {
    int t;
    string s;

    cin>>t;

    while (t--) {
        cin>>s;

        if (s == "b" || s == "B") {
            cout<<"BattleShip\n";
        } else if(s == "c" || s == "C") {
            cout<<"Cruiser\n";
        } else if(s == "d" || s == "D") {
            cout<<"Destroyer\n";
        } else if(s == "f" || s == "F") {
            cout<<"Frigate\n";
        }
    }

    return 0;
}