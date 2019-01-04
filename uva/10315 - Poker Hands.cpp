//
// Created by Aditya Jha on 2018-12-27.
//

#include<iostream>
#include<string>
#include<vector>
#include <algorithm>

using namespace std;

struct Card {
    int value;
    char type;
    char suit;
};

bool comparator(Card a, Card b) {
    return a.value < b.value;
}

bool isStraight(vector<Card> &cards) {
    for (int i=1; i<cards.size(); i++) {
        if (cards[i].value != (cards[i-1].value + 1)) {
            return false;
        }
    }

    return true;
}

bool isSameSuit(vector<Card> &cards) {
    for (int i=1; i<cards.size(); i++) {
        if (cards[i].suit != cards[i-1].suit) {
            return false;
        }
    }
    return true;
}

bool isStraightFlush(vector<Card> &cards) {
    return isSameSuit(cards) && isStraight(cards);
}

bool isFourOfAKind(vector<Card> &cards) {
    if (cards[1].value == cards[2].value && cards[2].value == cards[3].value) {
        if (cards[0].value == cards[1].value || cards[4].value == cards[3].value) {
            return true;
        }
    }

    return false;
}

bool isFullHouse(vector<Card> &cards) {
//    if (isFourOfAKind(cards))
//        return false;

    if (cards[1].value == cards[0].value && cards[1].value == cards[2].value && cards[3].value == cards[4].value) {
        return true;
    } else if (cards[1].value == cards[0].value && cards[3].value == cards[2].value && cards[3].value == cards[4].value) {
        return true;
    }

    return false;
}

bool isFlush(vector<Card> &cards) {
    return isSameSuit(cards);
}

bool isThreeOfAKind(vector<Card> &cards) {
    if (cards[1].value == cards[0].value && cards[1].value == cards[2].value && cards[3].value != cards[4].value) {
        return true;
    } else if (cards[1].value != cards[0].value && cards[3].value == cards[2].value && cards[3].value == cards[4].value) {
        return true;
    }

    return false;
}

int countPairs(vector<Card> &cards) {
//    if (isThreeOfAKind(cards)) {
//        return 0;
//    }

    int pairs = 0;
    if (cards[1].value == cards[0].value) {
        pairs++;
    }
    if (cards[1].value == cards[2].value) {
        pairs++;
    }
    if (cards[3].value == cards[2].value) {
        pairs++;
    }
    if (cards[3].value == cards[4].value) {
        pairs++;
    }

    return pairs;
}

bool isPair(vector<Card> &cards) {
    return countPairs(cards) == 1;
}

bool isTwoPairs(vector<Card> &cards) {
    return countPairs(cards) == 2;
}

int getHand(vector<Card> &cards) {
    if (isStraightFlush(cards)) {
        return 9;
    } else if (isFourOfAKind(cards)) {
        return 8;
    } else if (isFullHouse(cards)) {
        return 7;
    } else if (isFlush(cards)) {
        return 6;
    } else if (isStraight(cards)) {
        return 5;
    } else if (isThreeOfAKind(cards)) {
        return 4;
    } else if (isTwoPairs(cards)) {
        return 3;
    } else if (isPair(cards)) {
        return 2;
    } else {
        return 1;
    }
}

int getHigherHand(vector<Card> &a, vector<Card> &b) {
    for (int i=a.size()-1; i>=0; i--) {
        if (a[i].value == b[i].value) {
            continue;
        } else {
            if (a[i].value > b[i].value) {
                return 1;
            } else {
                return -1;
            }
        }
    }
    return 0;
}

vector<int> getPairs(vector<Card> &cards) {
    vector<int> sol;

    if (cards[1].value == cards[0].value) {
        sol.push_back(cards[0].value);
    }
    if (cards[1].value == cards[2].value) {
        sol.push_back(cards[1].value);
    }
    if (cards[3].value == cards[2].value) {
        sol.push_back(cards[2].value);
    }
    if (cards[3].value == cards[4].value) {
        sol.push_back(cards[3].value);
    }

    return sol;
}

int getHigherPair(vector<Card> &a, vector<Card> &b) {
    vector<int> pairsA = getPairs(a);
    vector<int> pairsB = getPairs(b);

    if (pairsA.size() == 2) {
        if (pairsA[1] > pairsB[1]) {
            return 1;
        } else if (pairsA[1] < pairsB[1]) {
            return -1;
        } else if (pairsA[0] > pairsB[0]) {
            return 1;
        } else if (pairsA[0] < pairsB[0]) {
            return -1;
        } else {
            for (int i=0; i<a.size(); i++) {
                if (a[i].value != pairsA[0] && a[i].value != pairsA[1]) {
                    for (int j=0; j<b.size(); j++) {
                        if (b[j].value != pairsB[0] && b[j].value != pairsB[1]) {
                            if (a[i].value > b[j].value) {
                                return 1;
                            } else if (a[i].value < b[j].value) {
                                return -1;
                            } else return 0;
                        }
                    }
                }
            }
        }
    } else {
        if (pairsA[0] > pairsB[0]) {
            return 1;
        } else if (pairsA[0] < pairsB[0]) {
            return -1;
        } else {
            vector<Card> newA, newB;
            for (int i=0;i<a.size(); i++) {
                if (a[i].value != pairsA[0]) {
                    newA.push_back(a[i]);
                }
            }
            for (int i=0;i<b.size(); i++) {
                if (b[i].value != pairsB[0]) {
                    newB.push_back(b[i]);
                }
            }

            return getHigherHand(newA, newB);
        }
    }

    return 0;
}

int main() {
    string s;

    while (getline(cin, s)) {
        vector<Card> black, white;

        int i = 2;
        while (i <= s.length()) {
            char type = s[i - 2];
            Card card;
            card.type = type;
            card.suit = s[i - 1];

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

            i += 3;

            if (black.size() == 5) {
                white.push_back(card);
            } else {
                black.push_back(card);
            }

            sort(white.begin(), white.end(), comparator);
            sort(black.begin(), black.end(), comparator);
        }

        int scoreBlack = getHand(black);
        int scoreWhite = getHand(white);

        string result = "Tie.";

        if (scoreBlack > scoreWhite) {
            result = "Black wins.";
        } else if (scoreBlack < scoreWhite) {
            result = "White wins.";
        } else {
            if (scoreBlack == 9 || scoreBlack == 8 || scoreBlack == 7 || scoreBlack == 5 || scoreBlack == 4) {
                // straight flush
                // four of a kind
                // straight
                // three of a kind
                if (white[2].value > black[2].value) {
                    result = "White wins.";
                } else if (white[2].value < black[2].value) {
                    result = "Black wins.";
                }
            } else if (scoreBlack == 6 || scoreBlack == 1) {
                // flush
                int r = getHigherHand(black, white);
                if (r > 0) {
                    result = "Black wins.";
                } else if (r < 0) {
                    result = "White wins.";
                }
            } else if (scoreBlack == 3 || scoreBlack == 2 ) {
                int r = getHigherPair(black, white);
                if (r > 0) {
                    result = "Black wins.";
                } else if (r < 0) {
                    result = "White wins.";
                }
            }
        }

        cout<<result<<endl;
    }

    return 0;
}