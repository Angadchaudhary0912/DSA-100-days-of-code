/*formula Given an array of integers, count the number of subarrays 
whose sum is equal to zero.*/


#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int count = 0;
    int prefixSum = 0;

    int freq[20001] = {0};
    int offset = 10000;

    for(int i = 0; i < n; i++) {
        prefixSum += arr[i];

        if(prefixSum == 0)
            count++;

        if(freq[prefixSum + offset] > 0)
            count += freq[prefixSum + offset];

        freq[prefixSum + offset]++;
    }

    printf("%d", count);

    return 0;
}