// Time Complexity : O(logn)
// Space Complexity : O(1)

#include <iostream>
using namespace std;

bool isBadVersion(int version);

int firstBadVersion(int n) {
    int left = 1;
    int right = n;

    while (left < right) {
        int mid = left + (right - left) / 2;
        if (isBadVersion(mid)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    return left;
}

bool isBadVersion(int version) {
    // Example implementation logic
    if (version >= 4) {
        return true;
    } else {
        return false;
    }
}

int main() {
    int n = 5;
    int bad = firstBadVersion(n);

    cout << "First bad version: " << bad << endl;

    return 0;
}
