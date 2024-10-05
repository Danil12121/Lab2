#include <iostream>
using namespace std;
int main() {
    using byte = unsigned char;
    pair<byte, byte> a;
    pair<byte, byte> b;
    cin >> a.first >> a.second;
    cin >> b.first >> b.second;

    if ((a.first == b.first) || (a.second == b.second))
        cout << "condition is true" << endl;
    else
        cout << "condition is false" << endl;

    if (abs(a.first - b.first) == abs(a.second - b.second))
        cout << "condition is true" << endl;
    else
        cout << "condition is false" << endl;

    if (abs(a.first - b.first) <= 1 || abs(a.second - b.second) <= 1)
        cout << "condition is true" << endl;
    else
        cout << "condition is false" << endl;

    if ((abs(a.first - b.first) == abs(a.second - b.second)) ||
       ((a.first == b.first) || (a.second == b.second)))
        cout << "condition is true" << endl;
    else
        cout << "condition is false" << endl;

    if (abs(a.first - b.first)<=1 && (a.second + 1 == b.second))
        cout << "condition is true" << endl;
    else
        cout << "condition is false" << endl;

    return 0;
}
