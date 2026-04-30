#include <stdio.h>

int isPossible(int arr[], int n, int k, long long maxTime) {
    int painters = 1;
    long long time = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] > maxTime)
            return 0;

        if (time + arr[i] <= maxTime) {
            time += arr[i];
        } else {
            painters++;
            time = arr[i];
        }

        if (painters > k)
            return 0;
    }
    return 1;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int arr[n];
    long long sum = 0, max = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
        if (arr[i] > max)
            max = arr[i];
    }

    long long left = max, right = sum, ans = sum;

    while (left <= right) {
        long long mid = left + (right - left) / 2;

        if (isPossible(arr, n, k, mid)) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    printf("%lld", ans);

    return 0;
}