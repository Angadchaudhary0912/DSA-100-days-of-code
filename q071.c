#include <stdio.h>
#include <string.h>

#define SIZE 1000

int table[SIZE];
int m;

int hash(int key) {
    return key % m;
}

void insert(int key) {
    int h = hash(key);
    int i = 0;
    int index;

    while (i < m) {
        index = (h + i * i) % m;
        if (table[index] == -1) {
            table[index] = key;
            return;
        }
        i++;
    }
}

int search(int key) {
    int h = hash(key);
    int i = 0;
    int index;

    while (i < m) {
        index = (h + i * i) % m;
        if (table[index] == -1)
            return 0;
        if (table[index] == key)
            return 1;
        i++;
    }
    return 0;
}

int main() {
    int n, i, key;
    char op[10];

    scanf("%d", &m);
    scanf("%d", &n);

    for (i = 0; i < m; i++)
        table[i] = -1;

    for (i = 0; i < n; i++) {
        scanf("%s %d", op, &key);

        if (strcmp(op, "INSERT") == 0) {
            insert(key);
        } else if (strcmp(op, "SEARCH") == 0) {
            if (search(key))
                printf("FOUND\n");
            else
                printf("NOT FOUND\n");
        }
    }

    return 0;
}