#include <stdio.h>

int maxLen(int arr[], int n) {
    int sum = 0, max_length = 0;

    for (int i = 0; i < n; i++) {
        sum = 0;
        for (int j = i; j < n; j++) {
            sum += arr[j];
            if (sum == 0) {
                int length = j - i + 1;
                if (length > max_length)
                    max_length = length;
            }
        }
    }
    return max_length;
}

int main() {
    int arr[] = {15, -2, 2, -8, 1, 7, 10, 23};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("%d", maxLen(arr, n));

    return 0;
}