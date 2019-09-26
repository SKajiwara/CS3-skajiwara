#include <iostream>
#include <string>
using namespace std;
int main(void) {
    string a;
    cin >> a;
    for (int i = 0; i < a.size() - 1; i++)
        cout << a.substr(i,2) << " ";
    cout << endl;
    return 0;
}