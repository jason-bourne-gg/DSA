#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

// Function to check if a given subsequence is "good"
bool is_good_subsequence(const std::vector<int>& subseq) {
    if (subseq.empty()) return false;

    std::unordered_set<int> elements(subseq.begin(), subseq.end());
    if (elements.size() != subseq.size()) return false;  // Check for uniqueness

    int min_elem = *std::min_element(subseq.begin(), subseq.end());
    int max_elem = *std::max_element(subseq.begin(), subseq.end());

    // Check if all elements between min_elem and max_elem are present
    for (int i = min_elem; i <= max_elem; ++i) {
        if (elements.find(i) == elements.end()) {
            return false;
        }
    }
    return true;
}

// Function to find and print all good subsequences
void find_good_subsequences(const std::vector<int>& arr) {
    int n = arr.size();
    std::vector<std::vector<int>> good_subsequences;
    int good_subseq_count = 0;

    // Iterate through all subsequences
    for (int i = 0; i < (1 << n); ++i) {
        std::vector<int> subseq;
        for (int j = 0; j < n; ++j) {
            if (i & (1 << j)) {
                subseq.push_back(arr[j]);
            }
        }
        if (is_good_subsequence(subseq)) {
            good_subsequences.push_back(subseq);
            ++good_subseq_count;
        }
    }

    // Print count of good subsequences
    std::cout << "Count of good subsequences: " << good_subseq_count << std::endl;

    // Print all good subsequences
    std::cout << "Good subsequences:" << std::endl;
    for (const auto& subseq : good_subsequences) {
        for (int num : subseq) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    std::vector<int> arr = {13,11,4,12,5,4};  // Example array
    find_good_subsequences(arr);
    return 0;
}
