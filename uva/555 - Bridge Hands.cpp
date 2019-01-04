//
// Created by Aditya Jha on 2018-12-27.
//

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

struct Card {
    int value;
    int suitValue;
    char type;
    char suit;
};

bool comparator(Card a, Card b) {
    if (a.suitValue == b.suitValue) {
        return a.value < b.value;
    } else {
        return a.suitValue < b.suitValue;
    }
}

vector<Card> N, E, S, W;

void giveToPlayer(int position, Card card) {
    position = position % 4;

    if (position == 0) {
        N.push_back(card);
    } else if (position == 1) {
        E.push_back(card);
    } else if (position == 2) {
        S.push_back(card);
    } else if (position == 3) {
        W.push_back(card);
    }
}

void readCards(char dealer) {
    int position = 0;
    if (dealer == 'N') {
        position = 1;
    } else if (dealer == 'E') {
        position = 2;
    } else if (dealer == 'S') {
        position = 3;
    }

    for(int j=0;j<2;j++) {
        string s;
        cin>>s;

        for (int i=1;i<s.length(); i+=2) {
            char type = s[i];
            char suit = s[i-1];

            Card card;
            card.type = type;
            card.suit = suit;

            if (type == 'A') {
                card.value = 14;
            } else if (type == 'K') {
                card.value = 13;
            } else if (type == 'Q') {
                card.value = 12;
            } else if (type == 'J') {
                card.value = 11;
            } else if (type == 'T') {
                card.value = 10;
            } else {
                card.value = type - '0';
            }

            if (suit == 'C') {
                card.suitValue = 1;
            } else if (suit == 'D') {
                card.suitValue = 2;
            } else if (suit == 'S') {
                card.suitValue = 3;
            } else {
                card.suitValue = 4;
            }

            giveToPlayer(position, card);
            position++;
        }
    }

    sort(N.begin(), N.end(), comparator);
    sort(S.begin(), S.end(), comparator);
    sort(E.begin(), E.end(), comparator);
    sort(W.begin(), W.end(), comparator);
}

void printHand(char player, vector<Card> &c) {
    cout<<player<<":";
    for (int i=0;i<c.size(); i++) {
        cout<<" "<<c[i].suit<<c[i].type;
    }
    cout<<endl;
}

int main() {
    char dealer;

    while(true) {
        N.clear();
        S.clear();
        W.clear();
        E.clear();

        cin>>dealer;

        if (dealer == '#') {
            break;
        }

        readCards(dealer);

        printHand('S', S);
        printHand('W', W);
        printHand('N', N);
        printHand('E', E);
    }

    return 0;
}