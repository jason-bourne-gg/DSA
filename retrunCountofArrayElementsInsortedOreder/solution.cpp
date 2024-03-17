#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<int> findOccurences(vector<int> &arr) {
    int n = arr.size();
    map<int, int> occurrenceMap;
    vector<int> occurrences;

    // Count occurrences of each element in the input vector
    for (auto element : arr) {
        if (occurrenceMap.find(element) == occurrenceMap.end()) {
            occurrenceMap[element] = 1;
        } else {
            occurrenceMap[element]++;
        }
    }
    
    // Push the counts of occurrences into the output vector
    for (auto entry : occurrenceMap) {
        occurrences.push_back(entry.second);
    }

    return occurrences;
}

int main() {
    vector<int> arr = {1, 2, 3, 2, 3, 3, 4, 5, 4, 5, 5, 5};
    vector<int> result = findOccurences(arr);

    // Print the result
    cout << "Occurrences of each element in the input vector:" << endl;
    for (int count : result) {
        cout << count << " ";
    }
    cout << endl;

    return 0;
}
