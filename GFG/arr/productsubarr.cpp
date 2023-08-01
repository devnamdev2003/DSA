#include <iostream>
#include <vector>

using namespace std;

int countSubarraysWithProductLessThanK(vector<int>& arr, int k) {
    int n = arr.size();
    int count = 0;
    int product = 1;
    int left = 0;

    for (int right = 0; right < n; right++) {
        product *= arr[right];

        while (product >= k && left <= right) {
            product /= arr[left];
            left++;
        }

        count += right - left + 1;
    }

    return count;
}

int main() {
    vector<int> arr = {1, 9, 2, 8, 6, 4, 3};
    int k = 100;

    int result = countSubarraysWithProductLessThanK(arr, k);
    cout << "Count: " << result << endl;

    return 0;
}
