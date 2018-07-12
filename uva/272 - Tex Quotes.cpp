#include<iostream>
#include<string>

using namespace std;

int main() {
    char s;
    bool open = false;
    s = getchar();
    char q = '\'';
    char b = '`';
    while(s != -1) {
        if (s == '"') {
            if (open) {
                open = false;
                putchar(q);
                putchar(q);
            } else {
                open = true;
                putchar(b);
                putchar(b);
            }
        } else {
           putchar(s);
        }
        s = getchar();
    }

    return 0;
}
