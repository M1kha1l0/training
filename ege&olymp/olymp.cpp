#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;
    if (n < 2) { 
        cout << n << " " << n; 
        return 0;
    }

    int minn = 9999999;
    int s;
    if (n % 2 == 0) {
        s = (n / 2) - 2;
        minn = int(s / 3) * 2 + 2;
    }
    else { 
        s = (n - 1) / 2;
        minn = int(s / 3) * 2 + 1; 
    }

    cout << minn << " " << n << "\n";
    return 0;
}