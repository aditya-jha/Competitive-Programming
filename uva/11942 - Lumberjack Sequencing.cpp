#include<iostream>

using namespace std;

bool isAsc(int* a) {
    for (int i=1; i<10; i++) {
        if (a[i] < a[i-1]) {
            return false;
        }
    }

    return true;
}

bool isDesc(int* a) {
    for (int i=1; i<10; i++) {
        if (a[i] > a[i-1]) {
            return false;
        }
    }

    return true;
}

int main() {
    int n;
    cin>>n;

    cout<<"Lumberjacks:\n";
    while(n--) {
        int* a = new int[10];
        for(int i=0; i<10;i++) {
            cin>>a[i];
        }
        bool ordered = true;
        if (isAsc(a) || isDesc(a)) {
            cout<<"Ordered\n";
        } else {
            cout<<"Unordered\n";
        }
    }

    return 0;
}