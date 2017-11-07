#include<iostream>
#include<vector>
#include<utility>
#include<string>
#include<algorithm>

using namespace std;

vector<int> routeToParent(int node) {
    vector<int> route;

    while (node) {
        route.push_back(node);
        node = node / 2;
    }

    return route;
}

pair<int, int> lowestCommonParent(vector<int> routeX, vector<int> routeY) {
    pair<int, int> parent;
    bool found = false;

    for (int i = 0; i < routeX.size() && i < routeY.size(); i++) {
        if (routeX[i] != routeY[i]) {
            parent = make_pair(routeX[i-1], i-1);
            found = true;
            break;
        }
    }

    if (found) {
        return parent;
    } else {
        if (routeX.size() <= routeY.size()) {
            return make_pair(routeX[routeX.size()-1], routeX.size()-1);
        } else {
            return make_pair(routeY[routeY.size()-1], routeY.size()-1);
        }
    }

}

int colorNodesFromNodeToParent(int rootColor, int colorToFind, int size, int startPosition) {
    int count = 0;
    for (int i = startPosition + 1; i < size; i++) {
        if ((i % 2 == 0 ? rootColor : (rootColor + 1) % 2) == colorToFind) {
            count++;
        }
    }

    return count;
}

int main() {
    int t, x, y, find;
    string s;
    int rootColor = 0;

    cin >> t;

    while (t--) {
        cin >> s;

        if (s == "Qi") {
            rootColor = (rootColor+1)%2;
        } else {
            cin >> x >> y;
            vector<int> routeX = routeToParent(x);
            vector<int> routeY = routeToParent(y);

            reverse(routeX.begin(), routeX.end());
            reverse(routeY.begin(), routeY.end());

            pair<int, int> parent = lowestCommonParent(routeX, routeY);

            if (s == "Qb") {
                find = 0;
            } else if (s == "Qr"){
                find = 1;
            }

            int countX = 0, countY = 0;
            if (x != y) {
                countX = colorNodesFromNodeToParent(rootColor, find, routeX.size(), parent.second);
                countY = colorNodesFromNodeToParent(rootColor, find, routeY.size(), parent.second);
            }

            int parentColor = (parent.second % 2 == 0 ? rootColor : (rootColor + 1) % 2) == find;
            cout << countX + countY + parentColor << endl;
        }

    }

    return 0;
}
