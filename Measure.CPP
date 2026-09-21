#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace chrono;

int binarySearch(const vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1;
}

int main() {
    int sizes[] = {10, 100, 1000};

    cout << "n\tTime (nanoseconds)" << endl;

    for (int n : sizes) {
        vector<int> arr(n);

        // Fill sorted array
        for (int i = 0; i < n; i++) {
            arr[i] = i + 1;
        }

        int target = n; // search last element

        auto start = high_resolution_clock::now();

        binarySearch(arr, target);

        auto stop = high_resolution_clock::now();

        auto duration = duration_cast<nanoseconds>(stop - start);

        cout << n << "\t" << duration.count() << endl;
    }

    return 0;
}