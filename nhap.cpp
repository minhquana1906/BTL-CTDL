#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

int main() {
    char str[] = "asd/ds/' . l ; ' ] , . / ' ; ] [ p ]";
    cout << "Cac dau cau: ";
    for (int i = 0; i < strlen(str); i++) {
        if (ispunct(str[i]))
            cout << str[i];
    }
    return 0;
}