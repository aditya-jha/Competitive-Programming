#include <iostream>
#include <string>

using namespace std;

string getLanguage(string s) {
    if (s == "HELLO") {
        return "ENGLISH";
    } else if (s == "HOLA") {
        return "SPANISH";
    } else if (s == "HALLO") {
        return "GERMAN";
    } else if (s == "BONJOUR") {
        return "FRENCH";
    } else if (s == "CIAO") {
        return "ITALIAN";
    } else if (s == "ZDRAVSTVUJTE") {
        return "RUSSIAN";
    } else {
        return "UNKNOWN";
    }
}

int main() {
    string s;
    int i = 1;
    cin >> s;

    while (s != "#") {
        cout << "Case " << i << ": " << getLanguage(s) << endl;
        i++;
        cin>>s;
    }

    return 0;
}