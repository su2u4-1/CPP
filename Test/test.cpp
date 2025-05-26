#include <bitset>
#include <iostream>

using namespace std;

int main() {
    string a = "123";
    string b = "12345678901234567890123456789012345678901234567890";
    cout << sizeof(a) << ", " << &a << ", " << static_cast<const void*>(a.data()) << endl
         << sizeof(b) << ", " << &b << ", " << static_cast<const void*>(b.data()) << endl;
    for (long long i = 0x7ffffcba0; i < 0x7ffffcc00; i++) {
        cout << hex << i << dec << ": " << bitset<8>(*reinterpret_cast<char*>(i)) << endl;
    }
    return 0;
}
