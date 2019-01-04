#include<iostream>
#include<string>
using namespace std;

int main() {
    int t;

    while(1) {
        cin>>t;

        if (t == 0) {
            break;
        }

        string curr = "+x";
        for (int i = 1; i < t; i++) {
            string o;
            cin>>o;

            if (o == "+z") {
                if (curr == "+x") {
                    curr = "+z";
                } else if (curr == "-x") {
                    curr = "-z";
                } else if (curr == "+z") {
                    curr = "-x";
                } else if (curr == "-z") {
                    curr = "+x";
                }
            } else if (o == "-z") {
                if (curr == "-z") {
                    curr = "-x";
                } else if (curr == "+z") {
                    curr = "+x";
                } else if (curr == "-x") {
                    curr = "+z";
                } else if (curr == "+z") {
                    curr = "+x";
                }
            } else if (o == "+y") {
                if (curr == "+x") {
                    curr = "+y";
                } else if (curr == "-x") {
                    curr = "-y";
                } else if (curr == "+y") {
                    curr = "-x";
                } else if (curr == "-y") {
                    curr = "+x";
                }
            } else if (o == "-y") {
                if (curr == "+x") {
                    curr = "-y";
                } else if (curr == "-x") {
                    curr = "+y";
                } else if (curr == "+y") {
                    curr = "+x";
                } else if (curr == "-y") {
                    curr = "+x";
                }
            }
        }

        cout<<curr<<endl;
    }

    return 0;
}