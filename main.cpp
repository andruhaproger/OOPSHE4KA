#include <iostream>
#include <calc.h>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    int ans =  sum_of_bin_range(a, b);
    cout << ans << endl;
}
