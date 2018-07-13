#include<iostream>
#include<string>

using namespace std;

int getSum(string s) {
    int sum = 0;

    for(int i=0; i<s.length(); i++) {
        sum += (s[i] - '0');
    }
    if (sum >= 10) {
        return getSum(to_string(sum));
    } else {
        return sum;
    }
}

int main() {
    long long int s;

    while(1) {
        cin>>s;

        if (s == 0) {
            break;
        }
        cout<<getSum(to_string(s))<<endl;
    }

    return 0;
}