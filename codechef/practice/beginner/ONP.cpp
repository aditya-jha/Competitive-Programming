#include<iostream>
#include<cstdio>
#include<string>
#include<stack>

using namespace std;

int main() {
    int t;
    stack<char> s;
    string input;
    cin>>t;

    while(t--) {
        cin>>input;

        while(!s.empty()) {
            s.pop();
        }

        for(int i=0;i<input.length();i++) {
            if(input[i] == ')') {
                cout<<s.top();
                s.pop();
            }
            else if((input[i] >= 'a' and input[i] <= 'z') || (input[i]>='0' && input[i] <= '9')) {
                cout<<input[i];
            }
            else if(input[i] == '('){
                continue;
            }
            else {
                s.push(input[i]);
            }
        }
        cout<<endl;
    }

    return 0;
}
