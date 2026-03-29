#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int val) {
    if (val == -1) return NULL;
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node*->left = node->right = NULL;
    return node;
}

struct Node* buildTree(int n) {
    if (n == 0) return NULL;
    int val;
    scanf("%d", &val);
    struct Node* root = newNode(val);
    if (!root) return NULL;

    struct Node** queue = (struct Node**)malloc(sizeof(struct Node*) * n);
    int head = 0, tail = 0;
    queue[tail++] = root;

    for (int i = 1; i < n; i++) {
        struct Node* curr = queue[head++];
        scanf("%d", &val);
        curr->left = newNode(val);
        if (curr->left) queue[tail++] = curr->left;

        if (++i < n) {
            scanf("%d", &val);
            curr->right = newNode(val);
            if (curr->right) queue[tail++] = curr->right;
        }
    }
    return root;
}

void printRightView(struct Node* root) {
    if (!root) return;

    struct Node* queue[1000];
    int head = 0, tail = 0;

    queue[tail++] = root;

    while (head < tail) {
        int levelSize = tail - head;

        for (int i = 0; i < levelSize; i++) {
            struct Node* curr = queue[head++];

            if (i == levelSize - 1) {
                printf("%d ", curr->data);
            }

            if (curr->left) queue[tail++] = curr->left;
            if (curr->right) queue[tail++] = curr->right;
        }
    }
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    struct Node* root = buildTree(n);
    printRightView(root);
    return 0;
}