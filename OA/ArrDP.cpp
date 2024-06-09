#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to compute LIS ending at each position
vector<int> computeLIS(const vector<int>& arr) {
    int n = arr.size();
    vector<int> lis(n, 1);
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (arr[i] > arr[j] && lis[i] < lis[j] + 1) {
                lis[i] = lis[j] + 1;
            }
        }
    }
    return lis;
}

// Function to compute LDS starting at each position
vector<int> computeLDS(const vector<int>& arr) {
    int n = arr.size();
    vector<int> lds(n, 1);
    for (int i = n - 2; i >= 0; --i) {
        for (int j = n - 1; j > i; --j) {
            if (arr[i] > arr[j] && lds[i] < lds[j] + 1) {
                lds[i] = lds[j] + 1;
            }
        }
    }
    return lds;
}

// Function to find minimum operations to make array bitonic
int minOperationsToMakeBitonic(const vector<int>& arr) {
    int n = arr.size();
    vector<int> lis = computeLIS(arr);
    vector<int> lds = computeLDS(arr);

    int maxBitonicLength = 0;
    for (int i = 0; i < n; ++i) {
        maxBitonicLength = max(maxBitonicLength, lis[i] + lds[i] - 1);
    }

    // Debugging prints
    cout << "LIS: ";
    for (int length : lis) {
        cout << length << " ";
    }
    cout << endl;

    cout << "LDS: ";
    for (int length : lds) {
        cout << length << " ";
    }
    cout << endl;

    return n - maxBitonicLength;
}

int main() {
    vector<int> arr = {1, 2, 5, 3, 2, 1, 7, 6};
    cout << "Minimum operations to make the array bitonic: "
         << minOperationsToMakeBitonic(arr) << endl;
    return 0;
}
