//
// Created by Aditya Jha on 2018-12-27.
//

#include<iostream>
#include<stack>
#include<utility>
#include<vector>
#include<string>

using namespace std;

struct Card {
    int value = 0;
    string card = "JOKER";
};

int main() {
    int t;
    cin>>t;

    for (int c = 1; c<=t; c++) {

        vector<Card> cards;

        for (int i=0; i<52; i++) {
            string s;
            cin>>s;

            Card card;
            card.card = s;

            if (s[0] == 'A' || s[0] == 'K' || s[0] == 'Q' || s[0] == 'J' || s[0] == 'T') {
                card.value = 10;
            } else {
                card.value = s[0] - '0';
            }

            cards.push_back(card);
        }

        int top = 26;
        int y = 0;

        for (int i=0; i<3; i++) {
            int x = cards[top].value;
            y += x;

            top -= (11 - x);
        }

        for (int i=0; i<52; i++) {
            if (i<=top || i>=27) {
                y--;
            }
            if (y==0) {
                cout<<"Case "<<c<<": "<<cards[i].card<<endl;
            }
        }
    }
    return 0;
}