// Дано целое число типа long long, выведите на экран содержимое каждого
// из его байтов, используя знания по указателям.
#include <iostream>

using namespace std;

int main()
{
    long long a;
    cin >> a;
    cout << &a << endl;
    unsigned char* y = (unsigned char*)&a;
    for (int i = 0; i < 8; i++) {
        cout << (int)*(y + i) << endl;
    }
}
