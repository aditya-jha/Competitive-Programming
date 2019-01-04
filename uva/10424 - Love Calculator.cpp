#include<iostream>
#include<string>
#include<cstdio>
#include<algorithm>

using namespace std;

int getSum(int s) {
    string ss = to_string(s);
    int sum = 0;
    for (int i=0; i<ss.length(); i++) {
        sum += (ss[i] - '0');
    }

    if (sum < 10) {
        return sum;
    } else {
        return getSum(sum);
    }
}

int main() {
    string s, b;

    while(getline(cin,s)) {
        int sum = 0, summer = 0;
        getline(cin,b);

        for (int i=0; i<s.length(); i++) {
            if (s[i] >= 'A' && s[i] <= 'Z') {
                sum += (s[i] - 'A' + 1);
            } else if (s[i] >= 'a' && s[i] <= 'z'){
                sum += (s[i] - 'a' + 1);
            }
        }

        sum = getSum(sum);

        for (int i=0; i<b.length(); i++) {
            if (b[i] >= 'A' && b[i] <= 'Z') {
                summer += (b[i] - 'A' + 1);
            } else if (b[i] >= 'a' && b[i] <= 'z'){
                summer += (b[i] - 'a' + 1);
            }
        }

        summer = getSum(summer);

        double num = min(summer, sum);
        double den = max(summer, sum);
        double value = (num/den)*100;
        
        printf("%.2f %\n", value); 
    }

    return 0;
}