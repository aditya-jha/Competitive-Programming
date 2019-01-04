//
// Created by Aditya Jha on 2018-12-28.
//

#include<iostream>
#include<string>

using namespace std;

int north, south, east, west, bottom, top;

void moveNorth() {
    int temp = bottom;

    bottom = north;
    north = top;
    top = south;
    south = temp;
}

void moveSouth() {
    int temp = bottom;

    bottom = south;
    south = top;
    top = north;
    north = temp;
}

void moveEast() {
    int temp = bottom;

    bottom = east;
    east = top;
    top = west;
    west = temp;
}

void moveWest() {
    int temp = bottom;

    bottom = west;
    west = top;
    top = east;
    east = temp;
}

int main() {
    int t;
    string s;

    while(true) {
        cin>>t;

        if (t == 0) {
            break;
        }

        top = 1;
        north = 2;
        west = 3;
        east = 4;
        south = 5;
        bottom = 6;

        while(t--) {
            cin>>s;
            if (s == "north") {
                moveNorth();
            } else if (s == "south") {
                moveSouth();
            } else if (s == "west") {
                moveWest();
            } else {
                moveEast();
            }
        }

        cout<<top<<endl;
    }

    return 0;
}