#include<iostream>
#include<cstdlib>
using namespace std;

int main()
{
    int x = 0;
    int y = 0;

    while (x < y) {
        printf("%i\n", x);
        x = x + 3;
    }

    if (x % 2 == 0) {
        cout << x << " is even" << endl;
    }

    else {
        cout << x << " is odd" << endl;
    }
}