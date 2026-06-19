#include<iostream>
using namespace std;

void yinzi(int n) {
    int factor = 2;
    
    while (n > 1) {
        if (n % factor == 0) {
            cout << factor << " ";
            n /= factor;
        } else {
            factor++;
        }
    }
}

int main() {
    int i;
    cin >> i;
    yinzi(i);
    return 0;
}
