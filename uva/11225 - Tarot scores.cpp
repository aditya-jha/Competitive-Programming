//
// Created by Aditya Jha on 2018-12-27.
//

#include<iostream>
#include<string>
#include<map>

using namespace std;

int main() {
    map<string, double> values;

    values["one"] = 4.5;
    values["two"] = 0.5;
    values["three"] = 0.5;
    values["four"] = 0.5;
    values["five"] = 0.5;
    values["six"] = 0.5;
    values["seven"] = 0.5;
    values["eight"] = 0.5;
    values["nine"] = 0.5;
    values["ten"] = 0.5;
    values["eleven"] = 0.5;
    values["twelve"] = 0.5;
    values["thirteen"] = 0.5;
    values["fourteen"] = 0.5;
    values["fifteen"] = 0.5;
    values["sixteen"] = 0.5;
    values["seventeen"] = 0.5;
    values["eighteen"] = 0.5;
    values["nineteen"] = 0.5;
    values["twenty"] = 0.5;
    values["twenty-one"] = 4.5;

    values["king"] = 4.5;
    values["queen"] = 3.5;
    values["knight"] = 2.5;
    values["jack"] = 1.5;
    values["ace"] = 0.5;

    int t;
    cin>>t;

    for (int hand=1; hand <= t; hand++) {
        int m;
        cin>>m;

        double score = 0;
        int oudlers = 0;

        for (int i=0; i<m; i++) {
            string v, u, s;
            cin >> v;

            if (v == "fool") {
                score += 4.5;
                oudlers++;
            } else {
                cin >> u >> s;

                if (v == "twenty-one" || v == "one") {
                    oudlers++;
                }

                score += values[v];
            }
        }

        int toScore = 56;
        if (oudlers == 3) {
            toScore = 36;
        } else if (oudlers == 2) {
            toScore = 41;
        } else if (oudlers == 1) {
            toScore = 51;
        }

        string result;;
        double points;
        if (score >= toScore) {
            result = "won";
            points = score - toScore;
        } else {
            result = "lost";
            points = toScore - score;
        }

        cout<<"Hand #"<<hand<<endl;
        cout<<"Game "<<result<<" by "<<points<<" point(s)."<<endl;

        if (hand != t) {
            cout<<endl;
        }
    }

    return 0;
}