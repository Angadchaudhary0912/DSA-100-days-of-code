#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);

    char names[n][100];
    for (int i = 0; i < n; i++) {
        scanf("%s", names[i]);
    }

    char unique[n][100];
    int count[n];
    int u = 0;

    for (int i = 0; i < n; i++) {
        int found = -1;
        for (int j = 0; j < u; j++) {
            if (strcmp(names[i], unique[j]) == 0) {
                found = j;
                break;
            }
        }
        if (found != -1) {
            count[found]++;
        } else {
            strcpy(unique[u], names[i]);
            count[u] = 1;
            u++;
        }
    }

    int max = count[0];
    char winner[100];
    strcpy(winner, unique[0]);

    for (int i = 1; i < u; i++) {
        if (count[i] > max) {
            max = count[i];
            strcpy(winner, unique[i]);
        } else if (count[i] == max) {
            if (strcmp(unique[i], winner) < 0) {
                strcpy(winner, unique[i]);
            }
        }
    }

    printf("%s %d\n", winner, max);

    return 0;
}