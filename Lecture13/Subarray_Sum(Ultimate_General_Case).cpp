#include <iostream>
using namespace std;
#define int long long

#define shift 100001
#define size 200003  // From -100001 to +100001 inclusive

int32_t main() {
    int n, x;
    cin >> n >> x;

    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int freq[size] = {0};
    freq[shift] = 1;        // prefix sum = 0 exists once for shifted.

    int prefixsum = 0, count = 0;

    for (int i = 0; i < n; i++) {
        prefixsum += a[i];

        int check = prefixsum - x + shift;
        if (check >= 0 && check < size) {
            count += freq[check];
        }

        int shiftedsum = prefixsum + shift;
        if (shiftedsum >= 0 && shiftedsum < size) {
            freq[shiftedsum]++;
        }
    }

    cout << count << endl;
    return 0;
}
