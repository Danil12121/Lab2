#include <iostream>
using namespace std;
long long P(int a, int b){
    long long  s = 1;
    for (int i = a; i <= b; i++){
        s *= i;
    }
    return s;
}
int main() {
    cout << P(8, 15) << endl;
    int a; cin >> a;
    cout << P(a, 20) << endl;
    int b; cin >> b;
    cout << P(1, b) << endl;
    cin >> a >> b;
    cout << P(a, b) << endl;
    return 0;
}
