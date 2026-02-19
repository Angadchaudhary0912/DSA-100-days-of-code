//Given an array of integers, rotate the array to the right by k positions.

#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int k;
    scanf("%d", &k);

   
    k = k % n;

  
    for(int i = 0; i < n/2; i++) {
        int temp = arr[i];
        arr[i] = arr[n-1-i];
        arr[n-1-i] = temp;
    }

    
    for(int i = 0; i < k/2; i++) {
        int temp = arr[i];
        arr[i] = arr[k-1-i];
        arr[k-1-i] = temp;
    }

    for(int i = 0; i < (n-k)/2; i++) {
        int temp = arr[k+i];
        arr[k+i] = arr[n-1-i];
        arr[n-1-i] = temp;
    }

    
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
