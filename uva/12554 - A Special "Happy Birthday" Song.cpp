#include<iostream>
#include<string>
#include<cmath>

using namespace std;

int main() {
    int t;
    cin>>t;

    string names[t];

    for (int i=0; i<t;i++) {
        cin>>names[i];
    }

    string words[16] = {"Happy", "birthday", "to", "you", "Happy", "birthday", "to", "you", "Happy", "birthday", "to", "Rujia", "Happy", "birthday", "to", "you"};

    int i=0, j=0;
    int end = (ceil((t*1.0)/16))*16;
    while(end--) {
        cout<<names[i]<<": "<<words[j]<<endl;
        i++;
        j++;
        j = j%16;
        i = i%t;
    }

    return 0;
}