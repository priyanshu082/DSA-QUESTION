#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n, lastNo;
    int digits = 0;

    cin >> n;

    while (n > 0)
    {
        lastNo = n % 10;
        digits = digits + 1;
        n = n / 10;
    }

    // another way to find number od digits
    int digits2 = int(log10(n) + 1);

    cout << "There are " << digits << " digits in the number" << endl;
    cout << "There are " << digits2 << " digits in the number" << endl;
    return 0;

    // time complexity for this method of division by 10, is o(log10(n))
}