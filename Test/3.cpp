#include <iostream>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    int a[100];
    int b[4]{-1, -1, -1, -1};
    // max, max-1, max_a, max-1_a
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] >= b[0])
        {
            b[1] = b[0];
            b[3] = b[2];
            b[0] = a[i];
            b[2] = i;
        }
    }
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (i == b[2] && k >= 1)
        {
            sum -= a[i];
        }
        else if (i == b[3] && k >= 2)
        {
            sum -= a[i];
        }
        else
        {
            sum += a[i];
        }
    }
    cout << sum;
    return 0;
}