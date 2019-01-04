//
// Created by Aditya Jha on 2018-12-28.
//

#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<set>

using namespace std;

int main() {
    int round;
    string correct;
    string guess;

    while(true) {
        cin>>round;

        if (round == -1) {
            break;
        }

        getchar();

        cin>>correct>>guess;

        set<char> correctSet;
        set<char>::iterator itr;

        for (int i = 0;i<correct.length(); i++) {
            correctSet.insert(correct[i]);
        }

        set<char> guessed;

        int wrong = 0;
        for (int i=0;i<guess.length(); i++) {
            char g = guess[i];
            if (guessed.find(g) == guessed.end()) {
                // not yet guessed
                guessed.insert(g);
                itr = correctSet.find(g);
                if (itr != correctSet.end()) {
                    correctSet.erase(itr);
                    if (correctSet.empty()) {
                        break;
                    }
                } else {
                    wrong++;
                    if (wrong >= 7) {
                        break;
                    }
                }
            }
        }

        cout<<"Round "<<round<<endl;
        if (wrong >= 7) {
            cout<<"You lose."<<endl;
        } else {
            if (correctSet.empty()) {
                cout<<"You win."<<endl;
            } else {
                cout<<"You chickened out."<<endl;
            }
        }
    }

    return 0;
}