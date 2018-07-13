#include<iostream>
#include<climits>
#include <algorithm>

using namespace std;

int main() {
    int g, b, h, w;

    while(cin>>g) {
        cin>>b>>h>>w;

        int sol = INT_MAX;
        int cost, beds;
        for (int i = 0; i < h; i++) {
            cin>>cost;
            for (int j = 0; j < w; j++) {
                cin>>beds;
                if (beds >= g) {
                    sol = min(sol, g*cost);
                }
            }
        }

        if (sol == INT_MAX || sol > b) {
            cout<<"stay home\n";
        } else {
            cout<<sol<<endl;
        }
    }

    return 0;
}